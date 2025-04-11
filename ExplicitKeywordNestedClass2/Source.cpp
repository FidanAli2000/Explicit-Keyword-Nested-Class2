#include<iostream>
#include"Car.h"
#include"CarGalery.h"
using namespace std;

void main() {
	int count=6;
	Car* c1 = new Car("Mercedes", "X-5", 1988);
	Car* c2 = new Car("BMW", "X-4", 2010);
	Car* c3 = new Car("Nissan", "X-3", 1999);
	Car* c4 = new Car("Lamborghini", "X-2", 2003);
	Car** cars = new Car * [count] {c1, c2, c3, c4};

	CarGalery cg("Vintage Vehicle Gallery", 4, cars);
	cg.CarGaleryInfo();

	cout << "Adding new car to gallery...\n";
	Car* newCar = new Car("Tesla", "Model S", 2022);
	cg.AddCar(newCar); 

	cg.CarGaleryInfo();
	int searchId;
	cout << "\nEnter search ID : ";
	cin >> searchId;


	cg.SearchCarById(searchId);

	int sellId;
	cout << "\nEnter sell id : ";
	cin >> sellId;
	cg.Sell(sellId);
	
	//cg.CarGaleryInfo();
}