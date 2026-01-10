#pragma once

#include <string>

struct User {
	std::string name;
	short age;
	int salary;
	int id;
};

enum SortBy {
	SortBy_Name = 2,
	SortBy_Age = 3,
	SortBy_Salary = 4,
	SortBy_Id = 1,
};