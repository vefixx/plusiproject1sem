#pragma once
#include "structs.h"
#include <vector>

bool ParseFileLine(const std::string& line, User& out_user);
void AddToTable(User& user, std::vector<User>& users);
bool LoadFromFile(const std::string& file_name, std::vector<User>& users);
void PrintTable(const std::vector<User>& users);
bool DeleteUserById(std::vector<User>& users, long id);