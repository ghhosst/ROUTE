#pragma once

class ROUTE{
private:
	char* NameStart;	// Название начального пункта маршрута
	char* NameFinish;	// Название конечного пункта маршрута
	int NumberRoute;	// Номер маршрута
public:
	char* GetNameStart();
	void SetNameStart(char* NameStart);
	char* GetNameFinish();
	void SetNameFinish(char* NameFinish);
	int GetNumberRoute();
	void SetNumberRoute(int NumberRoute);
};