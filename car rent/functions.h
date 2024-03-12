#pragma once

// main includes
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

// headers
#include "customers.h"
#include "cars.h"

using namespace std;

string path = "customers.txt";

int users_counter(string path) {

	ifstream file(path); string temp; int counter = 0;

	while (getline(file, temp)) counter++;

	file.close();
	return counter;

} // file strings counter

void fileExistenceCheck(string path) {
	ifstream check_file(path);

	if (!check_file) { check_file.close(); ofstream file(path); file.close(); }

}

Customer* readFile(string path) {
	int counter = 0, users_amount = users_counter(path);
	string line, temp; fileExistenceCheck(path);
	ifstream file(path);

	Customer* user_data = new Customer[users_amount];

	while (getline(file, line)) {
		istringstream iss(line); int current_item = 0;
		string name, phone_number, address, login, password;

		while (getline(iss, temp, '|')) {

			if (current_item == 0) name = temp;
			if (current_item == 1) phone_number = temp;
			if (current_item == 2) address = temp;
			if (current_item == 3) login = temp;
			if (current_item == 4) password = temp;

			current_item++;
		}

		user_data[counter].setUserData(current_login, current_password); counter++;
	}

	file.close();
	return user_data;
} // file reading function + init users vector

void getUserData(int user_id) {
	int users_amount = users_counter(path);

	if (user)

}

void MenuInit() {
	system("cls");



}