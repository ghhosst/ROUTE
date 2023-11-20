#include "List.h"

Element* List::GetHead() { return Head; };

void List::SetHead(Element* Head) { this->Head = Head; };

Element* List::GetTail() { return Tail; };

void List::SetTail(Element* Tail) { this->Tail = Tail; };

Element* List::GetIndex() { return Index; };

void List::SetIndex(Element* Index) { this->Index = Index; };

List::List() {
	system("cls");
	std::cout << "\n------|Вызван конструктор класса List (без параметров)|------\n";
	system("pause");

	Head = nullptr;
	Tail = nullptr;
	Index = nullptr;
}

List::List(Element* Head, Element* Tail, Element* Index) {
	std::cout << "\n------|Вызван конструктор класса List (с параметром)|------\n";
	system("pause");

	this->Head = Head;
	this->Tail = Tail;
	this->Index = Index;
}

List::List(const List& other) {
	std::cout << "\n------|Вызван конструктор класса List (копирования)|------\n";
	system("pause");

	this->Head = other.Head;
	this->Tail = other.Tail;
	this->Index = other.Index;
}

List::~List() {
	std::cout << "\n------|Вызван деструктор класса List|------\n";
	system("pause");

}

void List::Insert() {
	Element* element = new Element();

	element->SetPrev(Tail);
	if (Head == nullptr) { // list empty
		Head = element;
		Index = element;
	}
	if (Tail != nullptr)
		Tail->SetNext(element);
	Tail = element;
}

void List::Show() {
	if (Tail == nullptr)
		return;

	system("cls");
	while (Index != nullptr) {
		cout << "\n\nНомер маршрута: " << (Index->GetInformationROUTE())->GetNumberRoute();
		cout << "\nНачальный пункт: " << (Index->GetInformationROUTE())->GetNameStart();
		cout << "\nКонечный пункт: " << (Index->GetInformationROUTE())->GetNameFinish();
		Index = Index->GetNext();
	}
	Index = Head;
	cout << "\n\n";
	system("pause");
}

void List::ShowOnlyOne() {
	if (Tail == nullptr)
		return;

	int choiceNumRoute;
	system("cls");
	cout << "\n\n\nВведите номер маршрута, который хотите вывести на экран...\n";
	cin >> choiceNumRoute;
	while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceNumRoute) {
		Index = Index->GetNext();
	}
	cout << "\n\nНомер маршрута: " << (Index->GetInformationROUTE())->GetNumberRoute();
	cout << "\nНачальный пункт: " << (Index->GetInformationROUTE())->GetNameStart();
	cout << "\nКонечный пункт: " << (Index->GetInformationROUTE())->GetNameFinish();
	Index = Head;
	cout << "\n\n";
	system("pause");
}

void List::Change() {
	if (Tail == nullptr)
		return;

	int len;
	int choiceChange;
	int choicePoint;
	int changeNumberRoute;
	Show();
	cout << "\n\nВведите номер маршрута, данные которого вы хотите изменить: ";
	cin >> choiceChange;
	system("cls");

	while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceChange) {
		Index = Index->GetNext();
	}
	cout << "\n\nНомер маршрута: " << (Index->GetInformationROUTE())->GetNumberRoute();
	cout << "\nНачальный пункт: " << (Index->GetInformationROUTE())->GetNameStart();
	cout << "\nКонечный пункт: " << (Index->GetInformationROUTE())->GetNameFinish();
	Index = Head;
	cout << "\n\nВыберете пункт, который хотите изменить..." << endl
		<< "1) Номер маршрута" << endl
		<< "2) Начальный пункт" << endl
		<< "3) Конечный пункт" << endl
		<< "Выбранный пункт: ";
	cin >> choicePoint;
	switch (choicePoint) {
	case 1:
		cout << "\nВведите номер маршрута: ";
		cin >> changeNumberRoute;
		(Index->GetInformationROUTE())->SetNumberRoute(changeNumberRoute);
		break;
	case 2:
		cout << "\nВведите начальный пункт маршрута: ";
		(Index->GetInformationROUTE())->SetNameStart(getString(&len));
		break;
	case 3:
		cout << "\nВведите конечный пункт маршрута: ";
		(Index->GetInformationROUTE())->SetNameFinish(getString(&len));
		break;
	default:
		cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
		system("pause");
		break;
	}
}