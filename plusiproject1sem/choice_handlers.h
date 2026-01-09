#pragma once
#include <string>
#include <vector>
#include "structs.h"

void HandleLoadFromFile(std::vector<User>& users);
void HandleDeleteUserById(std::vector<User>& users);
void HandleSaveToFile(std::vector<User>& users);