#include "string_utils.h"

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
	bool all_is_digit = true;
	for (const char& ch : str) {
		if (!isdigit(ch)) {
			all_is_digit = false;
			break;
		}
	}

	return all_is_digit;
}



