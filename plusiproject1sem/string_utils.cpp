#include "string_utils.h"
#include <cctype>

void LTrim(std::string& str, const char* t)
{
	str.erase(0, str.find_first_not_of(t));
}

void RTrim(std::string& str, const char* t)
{
	str.erase(str.find_last_not_of(t) + 1);
}

void Trim(std::string& str, const char* t)
{
	LTrim(str, t);
	RTrim(str, t);
}

bool StringIsNumber(const std::string& str)
{
	if (str.empty())
		return false;

	size_t start = 0;
	if (str[0] == '-') {
		start = 1;
		if (str.length() == 1)
			return false;
	}

	for (size_t i = start; i < str.length(); ++i) {
		if (!isdigit(static_cast<unsigned char>(str[i]))) {
			return false;
		}
	}

	return true;
}



