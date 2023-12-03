#pragma once
#include "ROUTE.h"
using std::cout, std::cin, std::endl; 


class Element {
private:
	Element* Next;
	Element* Prev;
	ROUTE* InformationROUTE;
	int NumRoute;
public:
	Element();
	Element(int NumberRoute);  
	Element(const Element& other);
	~Element();

	Element* GetNext();
	void SetNext(Element* Next);
	Element* GetPrev();
	void SetPrev(Element* Prev);
	ROUTE* GetInformationROUTE();
	void SetInformationROUTE(ROUTE* InformationROUTE);
	int GetNumRoute();
	void SetNumRoute(int NumRoute);
};