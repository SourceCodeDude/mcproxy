#ifndef _STRINGCONVERT_H
#define _STRINGCONVERT_H

#include <string>

class StringConvert
{
private:
	StringConvert();

public:
	static std::string narrow(const std::wstring &wstrString);
	static std::wstring widen(const std::string &strString);
};


#endif
