#include <iostream>
#include <windows.h>
#include <limits>
#include "io_utils.h"
#include <vector>
#include "structs.h"

int main() {
	using namespace std;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<User> users;
	
	short choice;
	while (true) {
		cout << endl << "ФАЙЛОВАЯ БАЗА (" << users.size() << " объектов)" << endl;
		cout << "=============" << endl;
		cout << "0) Выход из программы" << endl;
		cout << "1) Загрузка из файла" << endl;
		cout << "2) Вывести таблицу" << endl;
		cout << "3) Удаление по ID" << endl;
		cout << "4) Сохранение в файл" << endl;
		cout << "5) Добавление пользователя" << endl;
		cout << "Введите номер действия: ";
		cin >> choice;

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

		if (choice == 0) {
			cout << "Вы вышли из программы" << endl;
			break;
		}

		if (!HandleChoice(choice, users)) {
			cout << "Неверное действие" << endl;
			continue;
		}
	}
}