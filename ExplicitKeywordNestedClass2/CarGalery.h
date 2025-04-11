#pragma once
#include<iostream>
#include"Car.h"
using namespace std;

class CarGalery {
private:
	const char* _GaleryName;
	int _CarCount;
	Car** _cars;

public:
	CarGalery(const char* galeryname,int carcount, Car** cars) {
		_GaleryName = galeryname;
		_CarCount = carcount;
		_cars = cars;
	}


	void CarGaleryInfo() {
		cout << "Galery name : " << _GaleryName << endl;
		cout << "Car count   : " << _CarCount << endl << endl;
		for (size_t i = 0; i < _CarCount; i++)
		{
			_cars[i]->AllCarS();
			cout << endl;
		}
	}

	void AddCar(Car* car) {
		Car** newCars = new Car * [_CarCount + 1];

		for (size_t i = 0; i < _CarCount; i++) {
			newCars[i] = _cars[i];
		}

		newCars[_CarCount] = car;
		_CarCount++;

		delete[] _cars;
		_cars = newCars;
	}

	void SearchCarById(int id) {
		bool found = false;
		for (int i = 0; i < _CarCount; i++) {
			if (_cars[i]->GetId() == id) {
				_cars[i]->AllCarS();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Error: Car with ID " << id << " not found." << endl;
		}
	}

	void Sell(int id) {
		for (int i = 0; i < _CarCount; i++) {
			if (_cars[i]->GetId() == id) {
				for (int j = i; j < --_CarCount; j++) {
					_cars[j] = _cars[j + 1];
				}
				cout << "Car with ID " << id << " successfully." << endl;
				return;
			}
		}
		cout << "Error: Car with ID " << id << " not found." << endl;
	}
	~CarGalery() {

		for (int i = 0; i < _CarCount; i++) {
			delete _cars[i]; 
		}
		delete[] _cars; 
	}
};


