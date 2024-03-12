
// main includes
#include <iostream>

// headers
#include "authentication.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU"); system("chcp 1251"); system("cls");

	string path = "users_data.txt";

	MainWindowInit(path); main();

	return 0;
}