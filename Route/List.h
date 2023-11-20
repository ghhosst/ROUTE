#pragma once
#include "Element.h"

class List {
private:
	Element* Head;
	Element* Tail;
	Element* Index;
public:
	List();
	List(Element* Head, Element* Tail, Element* Index);
	List(const List& other);
	~List();

	Element* GetHead();
	void SetHead(Element* Head);
	Element* GetTail();
	void SetTail(Element* Tail);
	Element* GetIndex();
	void SetIndex(Element* Index);

	void Insert();
	void Show();
	void ShowOnlyOne();
	void Change();
	//void Delete();
};