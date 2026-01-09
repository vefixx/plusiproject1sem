#include "choice_handlers.h"

#include "table_utils.h"
#include <string>
#include <iostream>
#include <fstream>

void HandleLoadFromFile(std::vector<User>& users)
{
	using namespace std;

	string file_name;
	cout << "Введите название файла (например, file.txt): ";
	getline(cin, file_name);
	bool success = LoadFromFile(file_name, users);
	if (!success) {
		cout << "Файл не найден." << endl;
	}
	else {
		cout << "Загружено " << users.size() << " пользователей из файла." << endl;
	}
}

void HandleDeleteUserById(std::vector<User>& users)
{
	using namespace std;

	int id;
	while (true) {
		cout << "Введите ID пользователя для удаления (-1 для выхода): ";
		cin >> id;

		if (cin.fail()) {
			cout << "Неверный ввод" << endl;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			continue;
		}
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		if (cin.gcount() > 1) {
			cout << "Неверный ввод" << endl;
			continue;
		}

		if (id == -1) {
			break;
		}

		if (!DeleteUserById(users, id)) {
			cout << "Пользователь с ID=" << id << " не найден." << endl;
			continue;
		}

		cout << "Пользователь с ID=" << id << " успешно удален." << endl;
		break;
	}
}

void HandleSaveToFile(std::vector<User>& users)
{
	using namespace std;

	string file_name;
	cout << "Введите название файла (например, file.txt): ";
	getline(cin, file_name);

	ofstream file(file_name);

	if (!file.is_open()) {
		cout << "Не удалось открыть файл для записи." << endl;
		return;
	}

	for (const User& user : users) {
		file << user.name << ", " << user.age << ", " << user.salary << "\n";
	}

	file.close();
	cout << "Данные сохранены в файл: " << file_name << endl;

}
