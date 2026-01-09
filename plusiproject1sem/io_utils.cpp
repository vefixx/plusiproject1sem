#include "io_utils.h"
#include "choice_handlers.h"
#include <string>
#include <iostream>

bool HandleChoice(short choice, std::vector<User>& users)
{
	using namespace std;

	switch (choice) {
	case 1: {
		string file_name;
		cout << "Введите название файла (например, file.txt): ";
		getline(cin, file_name);
		bool success = LoadFromFile(file_name, users);
		if (!success) {
			cout << "Файл не найден." << endl;
		} else {
			cout << "Загружено " << users.size() << " пользователей из файла." << endl;
		}
		break;
	};
	default:
		return false;
	}

	return true;
}
