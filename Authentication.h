class Authentication;

#ifndef _AUTHENTICATION_H
#define _AUTHENTICATION_H

#include <string>

class Authentication
{
public:
	Authentication();
	~Authentication();

	int login(const std::string &sUsername, const std::string &sPassword);
	void keepAlive();
	bool joinServer(const std::string &sServerHash);

	std::string getUsername();
	std::string getSessionId();

private:
	typedef struct
	{
		Authentication *pThis;
		std::string sBuffer;
	} ContentCallbackInfo;
	static size_t ContentCallback(void *contents, size_t size, size_t nmemb, void *user);

	std::string m_sUsername;
	std::string m_sSessionId;

	static int m_iRefCount;
};

#endif
