#pragma once
#include <string>

void LTrim(std::string& str, const char* t = " \t\n\r\f\v");
void RTrim(std::string& str, const char* t = " \t\n\r\f\v");
void Trim(std::string& str, const char* t = " \t\n\r\f\v");
bool StringIsNumber(const std::string& str);