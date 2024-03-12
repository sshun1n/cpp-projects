#pragma once

// main includes
#include <string>

using namespace std;

class User {
private:
	// cariables
	string login, password;
	int id;

	size_t& Count() {

		static size_t user_id_counter = 0; return user_id_counter;

	}

public:
	// default constructor
	User() {
		login = "None"; password = "None"; ++Count();
	}

	// constructor
	User(string login, string password) {

		this->login = login; this->password = password; id = Count();

	}

	// methodes
	bool authenticate(string login, string password) {

		if (this->login == login && this->password == password) return true;
		else return false;

	} // login and password comparison
	void setUserData(string login, string password) {

		this->login = login; this->password = password; id = Count();

	} // User data setting method
	string getUserLogin() { return login; }
};