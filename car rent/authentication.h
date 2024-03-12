#pragma once

// main includes
#include <iostream>
#include <fstream>
#include <sstream>

// headers
#include "users.h"

using namespace std;

int users_counter(string path) {

	ifstream file(path); string temp; int counter = 0;

	while (getline(file, temp)) counter++;

	file.close();
	return counter;

} // file strings counter

bool authentication(string input_login, string input_password, User* user_data, string path) {
	int users_amount = users_counter(path);

	for (int i = 0; i < users_amount; i++) {

		if (user_data[i].authenticate(input_login, input_password)) return true;

	}

	return false;

} // login and password comparison

bool availabilityCheck(User* user_data, string path, string input_login) {
	int users_amount = users_counter(path);

	for (int i = 0; i < users_amount; i++) {

		if (user_data[i].getUserLogin() == input_login) return false;

	}

	return true;
}

void fileExistenceCheck(string path) {
	ifstream check_file(path);

	if (!check_file) { check_file.close(); ofstream file(path); file.close(); }

}

void addNewUser(User* user_data, string path) {
	system("cls"); string input_login, input_password;
	int users_amount = users_counter(path);

	cout << "Введите желаемый логин: "; cin >> input_login;
	if (!availabilityCheck(user_data, path, input_login)) { system("cls"); cout << "[ ОШИБКА ] Имя пользователя '" << input_login << "' уже занято.\n"; system("pause"); addNewUser(user_data, path); }
	else {
		cout << "Введите желаемый пароль "; cin >> input_password;

		ofstream file(path, ios::app); if (users_amount != 0) { file << '\n'; }
		file << users_amount << '|' << input_login << '|' << input_password; file.close(); system("cls");
		cout << "Успешно добавлен пользователь " << input_login << '\n'; system("pause"); system("cls");
	}

} // Adding a new user data

User* readFile(string path) {
	int counter = 0, users_amount = users_counter(path);
	string line, temp; fileExistenceCheck(path);
	ifstream file(path);

	User* user_data = new User[users_amount];

	while (getline(file, line)) {
		istringstream iss(line); int current_item = 0;
		string current_login, current_password;

		while (getline(iss, temp, '|')) {

			if (current_item == 1) current_login = temp;
			if (current_item == 2) current_password = temp;

			current_item++;
		}

		user_data[counter].setUserData(current_login, current_password); counter++;
	}

	file.close();
	return user_data;
} // file reading function + init users vector

void MainWindowInit(string path) {
	int function; string input_login, input_password;
	User* user_data; bool call_user;

	cout << "Главное меню\n-----------------\n\n[1] Авторизация\n[2] Регистрация\n\n-----------------\n" << "Ввод: "; cin >> function; system("cls");

	if (function == 1) {
		user_data = readFile(path);

		cout << "Авторизация\n-----------------\n\nВведите логин: "; cin >> input_login;
		cout << "\nВведите пароль: "; cin.ignore(); getline(cin, input_password);
		system("cls");

		call_user = authentication(input_login, input_password, user_data, path);

		if (call_user) { cout << "Успешно!\n"; system("pause"); }
		else { cout << "[ ОШИБКА ] Имя пользователя или пароль введены неверно.\n"; system("pause"); }
	}
	if (function == 2) {
		user_data = readFile(path);

		addNewUser(user_data, path); MainWindowInit(path);
	}

} // Initialise menu