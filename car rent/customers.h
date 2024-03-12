#pragma once

#include <string>

using namespace std;

class Customer {
private:
	// variables
	string name, phone_number, address, login, password;
	int id;

	// counter
	size_t& Count() {

		static size_t customer_id_counter = 0; return customer_id_counter;

	}
public:
	// default constructor
	Customer() {

		++Count();


	}

	// deconstructor
	~Customer() {
		
		--Count();

	}

	// custom constructor
	Customer(string login, string password, string name, string phone_number, string address) {

		this->login = login; this->password = password;
		this->name = name; this->phone_number = phone_number; this->address = address;
		id = Count();

	}
};