#define _CRT_SECURE_NO_WARNINGS   
#include "ROUTE.h"

char* ROUTE::GetNameStart() { return NameStart; };

void ROUTE::SetNameStart(char* NameStart) { this->NameStart = NameStart; };

char* ROUTE::GetNameFinish() { return NameFinish; };

void ROUTE::SetNameFinish(char* NameFinish) { this->NameFinish = NameFinish; };

int ROUTE::GetNumberRoute() { return NumberRoute; };

void ROUTE::SetNumberRoute(int NumberRoute) { this->NumberRoute = NumberRoute; };

ROUTE::ROUTE() {
	cout << "\n------|������ ����������� ������ ROUTE (��� ����������)|------\n";
	system("pause");

	int choiceNumberRoute;
	int len;
	system("cls");
	cout << "������� ����� ��������: ";
	cin >> choiceNumberRoute;
	SetNumberRoute(choiceNumberRoute);
	cout << "\n������� ��������� ����� ��������: ";
	SetNameStart(getString(&len));
	cout << "\n������� �������� ����� ��������: ";
	SetNameFinish(getString(&len)); 
}


ROUTE::ROUTE(int NumberRoute) {
	cout << "\n------|������ ����������� ������ ROUTE (� ���������� NumberRoute)|------\n";
	system("pause");

	int len;
	system("cls");
	cout << "������� ����� ��������: " << NumberRoute << endl;
	SetNumberRoute(NumberRoute);
	cout << "\n������� ��������� ����� ��������: ";
	SetNameStart(getString(&len));
	cout << "\n������� �������� ����� ��������: ";
	SetNameFinish(getString(&len));
}

ROUTE::ROUTE(const ROUTE& other) {
	cout << "\n------|������ ����������� ������ ROUTE (�����������)|------\n";
	system("pause");
	
	NameStart = new char[sizeof(other.NameStart)];
	strcpy(this->NameStart, other.NameStart);
	NameFinish = new char[sizeof(other.NameFinish)]; 
	strcpy(this->NameFinish, other.NameFinish);
	this->NumberRoute = NumberRoute;
}

ROUTE::~ROUTE() {
	cout << "\n------|������ ���������� ������ ROUTE|------\n";
	system("pause");

	delete[] NameStart; 
	NameStart = nullptr;
	delete[] NameFinish;
	NameFinish = nullptr;
	NumberRoute = 0;
}