#ifndef CHOICE_HANDLERS_H_
#define CHOICE_HANDLERS_H_

#include <string>
#include <vector>
#include "structs.h"

void HandleLoadFromFile(std::vector<User>& users);
void HandleDeleteUserById(std::vector<User>& users);
void HandleSaveToFile(const std::vector<User>& users);
void HandleAddUser(std::vector<User>& users);
void HandleFindByField(const std::vector<User>& users);
void HandleFindByIDField(const std::vector<User>& users);
void HandleFindByNameField(const std::vector<User>& users);
void HandleFindByAgeField(const std::vector<User>& users);
void HandleFindBySalaryField(const std::vector<User>& users);
void HandleSortByField(std::vector<User>& users);

#endif // !CHOICE_HANDLERS_H_
