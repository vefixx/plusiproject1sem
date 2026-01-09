#include "io_utils.h"
#include "choice_handlers.h"
#include "table_utils.h"
#include <string>
#include <iostream>

bool HandleChoice(short choice, std::vector<User>& users)
{
	using namespace std;

	switch (choice) {
	case 1: {
		HandleLoadFromFile(users);
		break;
	}
	case 2: {
		PrintTable(users);
		break;
	}
	case 3: {
		HandleDeleteUserById(users);
		break;
	}
	case 4: {
		HandleSaveToFile(users);
		break;
	}
	case 5: {
		HandleAddUser(users);
		break;
	}
	default:
		return false;
	}

	return true;
}
