#include "choice_handlers.h"

#include <fstream>
#include "string_utils.h"

bool LoadFromFile(const std::string& file_name, std::vector<User>& users)
{
	using namespace std;

	ifstream file(file_name);

	if (!file.is_open())
		return false;

	users.clear();

	string str;
	User user;
	while (getline(file, str)) {
		if (ParseFileLine(str, user)) {
			user.id = users.size();
			users.push_back(user);
		}
	}

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

	// Возраст
	comma_pos = line.find(',', start);
	if (comma_pos == string::npos)
		return false;

	string age_string = line.substr(start, comma_pos - start);
	Trim(age_string);
	if (!StringIsNumber(age_string))
		return false;
	age = stoi(age_string);

	start = comma_pos + 1;

	// Зарплата
	// Обрезаем от start до конца строки
	string salary_string = line.substr(start);
	Trim(salary_string);
	if (!StringIsNumber(salary_string))
		return false;
	salary = stoi(salary_string);

	out_user.name = name;
	out_user.age = age;
	out_user.salary = salary;
}
