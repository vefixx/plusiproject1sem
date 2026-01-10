#pragma once
#include "structs.h"
#include <vector>

bool ParseFileLine(const std::string& line, User& out_user);
void AddToTable(User& user, std::vector<User>& users);
bool LoadFromFile(const std::string& file_name, std::vector<User>& users);
void PrintTable(const std::vector<User>& users);
bool DeleteUserById(std::vector<User>& users, int id);
void FindAndPrintUsersById(const std::vector<User>& users, int id);
void FindAndPrintUsersByName(const std::vector<User>& users, std::string name);
void FindAndPrintUsersByAge(const std::vector<User>& users, short age);
void FindAndPrintUsersBySalary(const std::vector<User>& users, int salary);
void SortTableBy(std::vector<User>& users, SortBy sort_by);
void PrintUser(const User& user);