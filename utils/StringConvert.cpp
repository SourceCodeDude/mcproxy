#include "StdInc.h"
#include "StringConvert.h"

#include <vector>
#include <locale>
#include <iostream>

std::string StringConvert::narrow(const std::wstring &wstrString)
{
	wchar_t const* from = wstrString.c_str();
	std::size_t const len = wstrString.size();
	std::vector<char> buffer(len + 1);
	std::use_facet<std::ctype<wchar_t> >(std::locale()).narrow(from, from + len, '_', &buffer[0]);
	return std::string(&buffer[0], &buffer[len]);
}

std::wstring StringConvert::widen(const std::string &strString)
{
	char const* from = strString.c_str();
	std::size_t const len = strString.size();
	std::vector<wchar_t> buffer(len + 1);
	std::use_facet<std::ctype<char> >(std::locale()).widen(from, from + len, (char *) &buffer[0]);
	return std::wstring(&buffer[0], &buffer[len]);
}
