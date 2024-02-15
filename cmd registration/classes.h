#pragma once

// main includes
#include <string>

using namespace std;

class User {
private:
	// cariables
	string login, password;

public:
	// default constructor
	User() {
		login = "None"; password = "None";
	}

	// constructor
	User(string login, string password) {

		this->login = login; this->password = password;

	}

	// methodes
	bool authenticate(string login, string password) {

		if (this->login == login && this->password == password) return true;
		else return false;

	} // login and password comparison
	void setUserData(string login, string password) {

		this->login = login; this->password = password;

	} // User data setting method
	string getUserLogin() { return login; }

};
