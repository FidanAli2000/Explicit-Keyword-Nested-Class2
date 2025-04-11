#pragma once
#include<iostream>
using namespace std;

class Car {
private:
	static int staticId;
	int _id;
	const char* _marka;
	const char* _model;
	int _year;

public:
	Car(const char* marka, const char* model, int year) {
		SetId(staticId++);
		SetMarka(marka);
		SetModel(model);
		SetYear(year);
	}

	void AllCarS() {
		cout << "ID    : " << _id << endl;
		cout << "Marka : " << _marka << endl;
		cout << "Model : " << _model << endl;
		cout << "Year  : " << _year << endl;
	}

	int GetId() {
		return _id;
	}

	const char* GetMarka() {
		return _marka;
	}

	const char* GetModel() {
		return _model;
	}

	int GetYear() {
		return _year;
	}

	void SetId(int id) {
		if (id > 0) {
			_id = id;
		}
		else {
			cout << "Error : Incorrect id" << endl;
		}
	}

	void SetMarka(const char* marka) {
		int len = strlen(marka);
		if (len > 0 && len < 50) {
			_marka = marka;
		}
		else {
			cout << "Error : Incorrect marka" << endl;
		}
	}

	void SetModel(const char* model) {
		int len = strlen(model);
		if (len > 0 && len < 50) {
			_model = model;
		}
		else {
			cout << "Error : Incorrect model" << endl;
		}
	}

	void SetYear(int year) {
		if (year > 0 && year < 2026) {
			_year = year;
		}
		else {
			cout << "Error : Incorrect year" << endl;
		}
	}
	
};
int Car::staticId = 1200;