#pragma once
#include <string>
#include <vector>
#include "structs.h"

void HandleLoadFromFile(std::vector<User>& users);
void HandleDeleteUserById(std::vector<User>& users);
void HandleSaveToFile(const std::vector<User>& users);
void HandleAddUser(std::vector<User>& users);