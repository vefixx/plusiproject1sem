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

void HandleSaveToFile(const std::vector<User>& users)
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

void HandleAddUser(std::vector<User>& users)
{
    using namespace std;

    while (true) {
        cout << "Введите '-' в имени, чтобы выйти." << endl;

        string name;
        while (true) {
            cout << "Введите имя (30 символов макс.): ";
            getline(cin, name);

            if (name == "-") {
                cout << "Выход из добавления пользователей." << endl;
                return;
            }

            if (name.length() == 0) {
                cout << "Имя не может быть пустым. Попробуйте снова." << endl;
                continue;
            }

            if (name.length() > 30) {
                cout << "Имя не должно содержать более 30 символов. Попробуйте снова." << endl;
                continue;
            }

            break;
        }

        short age;
        while (true) {
            cout << "Введите возраст (введите 0 для выхода) (от 0 до 100): ";
            cin >> age;
            if (cin.fail()) {
                cout << "Неверный ввод возраста. Попробуйте снова." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (age == 0) {
                cout << "Выход из добавления пользователей." << endl;
                return;
            }

            if (age < 0 || age > 100) {
                cout << "Возраст должен быть от 0 до 100. Попробуйте снова." << endl;
                continue;
            }

            break;
        }

        int salary;
        while (true) {
            cout << "Введите зарплату (введите -1 для выхода): ";
            cin >> salary;
            if (cin.fail()) {
                cout << "Неверный ввод зарплаты. Попробуйте снова." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (salary == -1) {
                cout << "Выход из добавления пользователей." << endl;
                return;
            }

            if (salary < 0) {
                cout << "Зарплата не может быть отрицательной. Попробуйте снова." << endl;
                continue;
            }

            break;
        }

        User newUser;
        newUser.name = name;
        newUser.age = age;
        newUser.salary = salary;
        AddToTable(newUser, users);

        cout << "Пользователь добавлен: ";
        PrintUser(newUser);

        cout << "Продолжить добавление? (да/нет): ";
        string cont;
        getline(cin, cont);
        if (cont != "да" && cont != "Да") {
            break;
        }
    }
}

void HandleFindByField(const std::vector<User>& users)
{
    using namespace std;

    short choice;
    while (true) {
        cout << endl << "ПОИСК ПО ПОЛЮ" << endl;
        cout << "=============" << endl;
        cout << "0) Вернуться" << endl;
        cout << "1) Поиск по ID" << endl;
        cout << "2) Поиск по имени" << endl;
        cout << "3) Поиск по возрасту" << endl;
        cout << "4) Поиск по зарплате" << endl;
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
            break;
        }

        switch (choice) {
        case 1:
            HandleFindByIDField(users);
            break;
        case 2:
            HandleFindByNameField(users);
            break;
        case 3:
            HandleFindByAgeField(users);
            break;
        case 4:
            HandleFindBySalaryField(users);
            break;
        }
    }
}

void HandleFindByIDField(const std::vector<User>& users)
{
    using namespace std;

    int id;
    while (true) {
        cout << "Введите ID для поиска (введите -1 для отмены): ";
        cin >> id;
        if (cin.fail()) {
            cout << "Неверный ввод ID. Попробуйте снова." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (id == -1) {
            return;
        }

        if (id < 0) {
            cout << "Некорректный ID. Попробуйте снова." << endl;
            continue;
        }

        break;
    }

    FindAndPrintUsersById(users, id);
}

void HandleFindByNameField(const std::vector<User>& users)
{
    using namespace std;

    string name;
    cout << "Введите '-' в имени, чтобы выйти." << endl;
    while (true) {
        cout << "Введите имя (30 символов макс.): ";
        getline(cin, name);

        if (name == "-") {
            return;
        }

        if (name.length() == 0) {
            cout << "Имя не может быть пустым. Попробуйте снова." << endl;
            continue;
        }

        if (name.length() > 30) {
            cout << "Имя не должно содержать более 30 символов. Попробуйте снова." << endl;
            continue;
        }

        break;
    }

    FindAndPrintUsersByName(users, name);
}

void HandleFindByAgeField(const std::vector<User>& users)
{
    using namespace std;

    short age;
    while (true) {
        cout << "Введите возраст (введите 0 для выхода) (от 0 до 100): ";
        cin >> age;
        if (cin.fail()) {
            cout << "Неверный ввод возраста. Попробуйте снова." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (age == 0) {
            return;
        }

        if (age < 0 || age > 100) {
            cout << "Возраст должен быть от 0 до 100. Попробуйте снова." << endl;
            continue;
        }

        break;
    }

    FindAndPrintUsersByAge(users, age);
}

void HandleFindBySalaryField(const std::vector<User>& users)
{
    using namespace std;

    unsigned int salary;
    while (true) {
        cout << "Введите зарплату (введите -1 для выхода): ";
        cin >> salary;
        if (cin.fail()) {
            cout << "Неверный ввод зарплаты. Попробуйте снова." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (salary == -1) {
            return;
        }

        break;
    }

    FindAndPrintUsersBySalary(users, salary);
}
