#pragma once

#include <string>

using namespace std;

class Car {
private:
	// variables
	string brand, model, plate_num, color, transmission;
	float mileage, engine, price; bool available; int id;

	// counter
	size_t& Count() {

		static size_t car_id_counter = 0; return car_id_counter;

	}
public:
	// default constructor
	Car() {
		
		++Count();

		brand = model = plate_num = color = transmission = "Not specified";
		mileage = engine = 0; available = false;

		id = Count();

	}

	// deconstructor
	~Car() { --Count(); }

	// custom constructor
	Car(string brand, string model, string plate_num, string color, string transmission, float mileage, float engine, float price) {

		this->brand = brand; this->model = model; this->plate_num = plate_num; this->color = color; this->transmission = transmission; this->mileage = mileage; this->engine = engine; this->price = price;
		id = Count();
	}

	// methodes
	bool call(); float get_price(float time);
	string* get_info();

};

bool Car::call() { return available; }

string* Car::get_info() {

	string temp[8];

	temp[0] = to_string(id); temp[1] = brand; temp[2] = model; temp[3] = plate_num; temp[4] = color; temp[5] = transmission; temp[6] = to_string(mileage); temp[7] = to_string(engine);

	return temp;
}

float Car::get_price(float time) { return price * time; }