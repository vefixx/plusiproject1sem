#include "table_utils.h"

#include <fstream>
#include "string_utils.h"
#include <iostream>
#include <iomanip>
#include "choice_handlers.h"

void AddToTable(User& user, std::vector<User>& users)
{
	int size = users.size();
	if (size > 0) {
		user.id = users[size - 1].id + 1;
	}
	else {
		user.id = 0;
	}

	users.push_back(user);
}

void PrintTable(const std::vector<User>& users)
{
	using namespace std;

	const int col_width_id = 5;
	const int col_width_name = 30;
	const int col_width_age = 10;
	const int col_width_salary = 12;

	cout << left
		<< setw(col_width_id) << "ID"
		<< setw(col_width_name) << "Имя"
		<< setw(col_width_age) << "Возраст"
		<< setw(col_width_salary) << "Зарплата"
		<< endl;

	cout << string(col_width_id, '-')
		<< '+' << string(col_width_name - 1, '-')
		<< '+' << string(col_width_age - 1, '-')
		<< '+' << string(col_width_salary - 1, '-')
		<< endl;

	for (const auto& user : users) {
		cout << left
			<< setw(col_width_id) << user.id
			<< setw(col_width_name) << user.name
			<< setw(col_width_age) << user.age
			<< setw(col_width_salary) << user.salary
			<< endl;
	}
}

bool DeleteUserById(std::vector<User>& users, int id)
{
	for (int i = 0; i < users.size(); i++) {
		if (users[i].id == id) {
			users.erase(users.begin() + i);
			return true;
		}
	}

	return false;
}

void PrintUser(const User& user)
{
	using namespace std;

	cout << user.name << ", возраст: " << user.age
		<< ", зарплата: " << user.salary << ", ID: " << user.id << endl;
}

void FindAndPrintUsersById(const std::vector<User>& users, int id)
{
	using namespace std;

	for (const User& user : users) {
		if (user.id == id) {
			cout << "Пользователь найден! ";
			PrintUser(user);
			return;
		}
	}

	cout << "По полю ID=" << id << " было найдено 0 пользователей" << endl;
}

void FindAndPrintUsersByName(const std::vector<User>& users, std::string name)
{
	using namespace std;

	bool any_find = false;
	for (const User& user : users) {
		if (user.name == name) {
			any_find = true;
			cout << "Пользователь найден! ";
			PrintUser(user);
		}
	}

	if (!any_find) {
		cout << "По полю Имя=\"" << name << "\" было найдено 0 пользователей" << endl;
	}
}

void FindAndPrintUsersByAge(const std::vector<User>& users, short age)
{
	using namespace std;

	bool any_find = false;
	for (const User& user : users) {
		if (user.age == age) {
			any_find = true;
			cout << "Пользователь найден! ";
			PrintUser(user);
		}
	}

	if (!any_find) {
		cout << "По полю Возраст=\"" << age << "\" было найдено 0 пользователей" << endl;
	}
}

void FindAndPrintUsersBySalary(const std::vector<User>& users, int salary)
{
	using namespace std;

	bool any_find = false;
	for (const User& user : users) {
		if (user.salary == salary) {
			any_find = true;
			cout << "Пользователь найден! ";
			PrintUser(user);
		}
	}

	if (!any_find) {
		cout << "По полю Зарплата=\"" << salary << "\" было найдено 0 пользователей" << endl;
	}
}

bool LoadFromFile(const std::string& file_name, std::vector<User>& users)
{
	using namespace std;

	ifstream file(file_name);

	if (!file.is_open()) {
		return false;
	}

	users.clear();

	string str;
	User user;
	while (getline(file, str)) {
		if (ParseFileLine(str, user)) {
			AddToTable(user, users);
		}
	}

	file.close();

	return true;
}

bool ParseFileLine(const std::string& line, User& out_user)
{
	using namespace std;

	string name;
	short age;
	int salary;

	// Парсим строки формата: <name>, <age>, <salary>
	// Если строка не соответствует формату, то пропускаем ее

	int start = 0;	// Откуда парсим поле.
	size_t comma_pos = line.find(',', 0);
	if (comma_pos == string::npos)
		return false;

	// Имя
	// Берем строку, обрезанную от start до запятой
	// Количество символов для обрезки = comma_pos - start, то есть длина поля
	// Это и будет необходимое содержимое поля
	name = line.substr(start, comma_pos - start);
	Trim(name);
	start = comma_pos + 1; // Устанавливаем новый старт обрезки

	if (name.length() == 0 || name.length() > 30)
		return false;

	// Возраст
	comma_pos = line.find(',', start);
	if (comma_pos == string::npos)
		return false;

	string age_string = line.substr(start, comma_pos - start);
	Trim(age_string);
	if (!StringIsNumber(age_string))
		return false;
	age = stoi(age_string);

	if (age < 0 || age > 100)
		return false;

	start = comma_pos + 1;

	// Зарплата
	// Обрезаем от start до конца строки
	string salary_string = line.substr(start);
	Trim(salary_string);
	if (!StringIsNumber(salary_string))
		return false;
	salary = stoi(salary_string);

	if (salary < 0)
		return false;

	out_user.name = name;
	out_user.age = age;
	out_user.salary = salary;
}