#pragma once
#include <iostream>
#include "getString.h"
using std::cout, std::cin, std::endl;

class ROUTE{
private:
	char* NameStart;	// Название начального пункта маршрута
	char* NameFinish;	// Название конечного пункта маршрута
	int NumberRoute;	// Номер маршрута
public:
	ROUTE();
	ROUTE(int NumberRouteForCopy, ROUTE& _route); 
	ROUTE(int p);
	ROUTE(const ROUTE& other);
	~ROUTE();

	char* GetNameStart();
	void SetNameStart(char* NameStart);
	char* GetNameFinish();
	void SetNameFinish(char* NameFinish);
	int GetNumberRoute();
	void SetNumberRoute(int NumberRoute);
};