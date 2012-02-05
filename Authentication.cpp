#include "StdInc.h"
#include "Authentication.h"
#include "curl/curl.h"

int Authentication::m_iRefCount = 0;

Authentication::Authentication()
{
	if (m_iRefCount++ == 0)
	{
		curl_global_init(CURL_GLOBAL_ALL);
	}
}

Authentication::~Authentication()
{
	if (--m_iRefCount == 0)
	{
		curl_global_cleanup();
	}
}

int Authentication::login(const std::string &sUsername, const std::string &sPassword)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (!curl)
	{
		return 1;
	}

	curl_easy_setopt(curl, CURLOPT_URL, "https://login.minecraft.net");

	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

	// TODO: urlencode
	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	std::string sPost = "user=" + sUsername + "&password=" + sPassword + "&version=12";
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, sPost.c_str());

	ContentCallbackInfo info;
	info.pThis = this;
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Authentication::ContentCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&info);

	res = curl_easy_perform(curl);

	curl_easy_cleanup(curl);

	std::string sData(info.sBuffer);

	std::string::size_type idx = sData.find(':');
	if (idx != std::string::npos)
	{
		std::string sTimestamp = sData.substr(0, idx);
		std::string sDeprecated = sData.substr(idx + 1);
		idx = sDeprecated.find(':');
		if (idx != std::string::npos)
		{
			m_sUsername = sDeprecated.substr(idx + 1);
			sDeprecated = sDeprecated.substr(0, idx);
			idx = m_sUsername.find(':');
			if (idx != std::string::npos)
			{
				m_sSessionId = m_sUsername.substr(idx + 1);
				m_sUsername = m_sUsername.substr(0, idx);
				idx = m_sSessionId.find(':');
				if (idx != std::string::npos)
				{
					m_sSessionId = m_sSessionId.substr(idx);
				}
			}
		}
	}

	return 0;
}

void Authentication::keepAlive()
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (!curl)
	{
		return;
	}

	// TODO: urlencode
	curl_easy_setopt(curl, CURLOPT_URL, ("https://login.minecraft.net/session?user=" + m_sUsername + "&session=" + m_sSessionId).c_str());

	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

	res = curl_easy_perform(curl);

	curl_easy_cleanup(curl);
}

bool Authentication::joinServer(const std::string &sServerHash)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (!curl)
	{
		return false;
	}

	// TODO: urlencode
	std::string sURL = "http://session.minecraft.net/game/joinserver.jsp?user=" + m_sUsername + "&sessionId=" + m_sSessionId + "&serverId=" + sServerHash;
	curl_easy_setopt(curl, CURLOPT_URL, sURL.c_str());

	ContentCallbackInfo info;
	info.pThis = this;
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Authentication::ContentCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&info);

	res = curl_easy_perform(curl);

	bool bOK = info.sBuffer.compare("OK") == 0;

	curl_easy_cleanup(curl);

	return bOK;
}

std::string Authentication::getUsername()
{
	return m_sUsername;
}

std::string Authentication::getSessionId()
{
	return m_sSessionId;
}

size_t Authentication::ContentCallback(void *contents, size_t size, size_t nmemb, void *user)
{
	ContentCallbackInfo *pInfo = (ContentCallbackInfo *)user;

	pInfo->sBuffer.append((char *)contents, size * nmemb);
	return size * nmemb;
}
