#include <iostream>
#include <windows.h>
#include <limits>
#include "io_utils.h"

int main() {
	using namespace std;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	short choice;
	while (true) {
		cout << "ФАЙЛОВАЯ БАЗА" << endl;
		cout << "=============" << endl;
		cout << "0) Выход из программы" << endl;
		cout << "Введите номер действия: ";
		cin >> choice;

		if (cin.fail()) {
			cout << "Неверный ввод" << endl << endl;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			continue;
		}
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		if (cin.gcount() > 1) {
			cout << "Неверный ввод" << endl << endl;
			continue;
		}

		if (choice == 0) {
			cout << "Вы вышли из программы" << endl;
			break;
		}

		if (!HandleChoice(choice)) {
			cout << "Неверное действие" << endl << endl;
			continue;
		}
	}
}