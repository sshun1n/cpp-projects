
// main includes
#include <iostream>
#include <fstream>
#include <string>

// headers
#include "classes.h"
#include "functions.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "RU"); system("cls");

	// Main data file path
	string path = "data.txt";

	MainWindowInit(path); main();

	return 0;
}