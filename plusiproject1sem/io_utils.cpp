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
		HandleSaveToFile(users);
		break;
	}
	case 3: {
		PrintTable(users);
		break;
	}
	case 4: {
		HandleAddUser(users);
		break;
	}
	case 5: {
		HandleDeleteUserById(users);
		break;
	}
	case 6: {
		HandleFindByField(users);
		break;
	}
	case 7: {
		HandleSortByField(users);
		break;
	}
	default:
		return false;
	}

	return true;
}
