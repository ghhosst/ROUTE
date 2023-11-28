#define _CRT_SECURE_NO_WARNINGS   
#include "ROUTE.h"

char* ROUTE::GetNameStart() { return NameStart; };

void ROUTE::SetNameStart(char* NameStart) { this->NameStart = NameStart; };

char* ROUTE::GetNameFinish() { return NameFinish; };

void ROUTE::SetNameFinish(char* NameFinish) { this->NameFinish = NameFinish; };

int ROUTE::GetNumberRoute() { return NumberRoute; };

void ROUTE::SetNumberRoute(int NumberRoute) { this->NumberRoute = NumberRoute; };

ROUTE::ROUTE() {
	cout << "\n------|Вызван конструктор класса ROUTE (без параметров)|------\n";
	system("pause");

	int choiceNumberRoute;
	int len;
	system("cls");
	cout << "Введите номер маршрута: ";
	cin >> choiceNumberRoute;
	SetNumberRoute(choiceNumberRoute);
	cout << "\nВведите начальный пункт маршрута: ";
	SetNameStart(getString(&len));
	cout << "\nВведите конечный пункт маршрута: ";
	SetNameFinish(getString(&len)); 
}

ROUTE::ROUTE(int NumberRouteForCopy, ROUTE& _route) { 
	cout << "\n------|Вызван конструктор класса ROUTE (с параметрами)|------\n";
	system("pause");

	NameStart = new char[sizeof(_route.NameStart)];
	strcpy(NameStart, _route.NameStart);
	NameFinish = new char[sizeof(_route.NameFinish)];
	strcpy(NameFinish, _route.NameFinish);  
	NumberRoute = NumberRouteForCopy;  
}

ROUTE::ROUTE(int p) {
	cout << "\n------|Вызван конструктор класса ROUTE (с параметром p)|------\n";
	system("pause");

	NameStart = nullptr;
	NameFinish = nullptr;
	NumberRoute = 0;
}

ROUTE::ROUTE(const ROUTE& other) {
	cout << "\n------|Вызван конструктор класса ROUTE (копирования)|------\n";
	system("pause");
	
	NameStart = new char[sizeof(other.NameStart)];
	strcpy(this->NameStart, other.NameStart);
	NameFinish = new char[sizeof(other.NameFinish)]; 
	strcpy(this->NameFinish, other.NameFinish);
	this->NumberRoute = NumberRoute;
}

ROUTE::~ROUTE() {
	cout << "\n------|Вызван деструктор класса ROUTE|------\n";
	system("pause");

	delete[] NameStart; 
	NameStart = nullptr;
	delete[] NameFinish;
	NameFinish = nullptr;
	NumberRoute = 0;
}