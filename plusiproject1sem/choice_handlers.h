#pragma once
#include <string>
#include <vector>
#include "structs.h"

bool LoadFromFile(const std::string& file_name, std::vector<User>& users);
bool ParseFileLine(const std::string& line, User& out_user);