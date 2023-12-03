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

	this->Head = nullptr;
	this->Tail = nullptr;
	this->Index = nullptr;

	if (other.Tail == nullptr)
		return;

	Element* firstElement = new Element();
	this->Head = firstElement;
	Element* newRear_tmp = firstElement;

	Element* rear_tmp = other.Head->GetNext(); 
	while (rear_tmp != nullptr) {
		Element* element = new Element();
		this->Tail = element;
		element->SetPrev(newRear_tmp);
		newRear_tmp->SetNext(element);
		newRear_tmp = newRear_tmp->GetNext();

		rear_tmp = rear_tmp->GetNext();
	}

	Index = Head;
}

List::~List() {
	std::cout << "\n------|Вызван деструктор класса List|------\n";
	system("pause");

	while (Index != nullptr) {
		if (Index == nullptr) {
			return;
		}

		if (Index == Tail) {
			delete Tail;
			Index = nullptr;
			Tail = nullptr;
			Head = nullptr;
			return;
		}

		Element* tmp_element = Index;
		Index = tmp_element->GetNext();
		delete tmp_element;
	}
}

void List::Insert() {
	Element* element = nullptr;
	int choiceNumberRoute;
	system("cls");
	cout << "Введите номер маршрута: ";
	cin >> choiceNumberRoute;
	bool ExistNum = false;
	while (Index != nullptr) {
		if (choiceNumberRoute == (Index->GetInformationROUTE())->GetNumberRoute()) {
			ExistNum = true;
			break;
		}
		Index = Index->GetNext();
	}
	Index = Head;
	if (!ExistNum)
		element = new Element(choiceNumberRoute);
	else
		throw MyException("\n\nМаршрут с таким номером уже есть в списке !\nНомер маршрута должен быть уникальным.\n\n");

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
	try {
		if (Tail == nullptr)
			throw MyException();

		bool notSorting = true;

		while (Index != nullptr) {
			if (Index->GetNext() == nullptr)
				break;
			if ((Index->GetInformationROUTE())->GetNumberRoute() < ((Index->GetNext())->GetInformationROUTE())->GetNumberRoute())
				notSorting = false;
			else {
				notSorting = true;
				break;
			}
			Index = Index->GetNext();
		}
		Index = Head;

		if (notSorting)
			Sorting();

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
	catch (MyException& ex) {
		ex.GetNumError();
		system("pause");
	}
}

void List::ShowOnlyOne() {
	try {
		if (Tail == nullptr)
			throw MyException();

		int choiceNumRoute;
		system("cls");
		cout << "\n\n\nВведите номер маршрута, который хотите вывести на экран...\n";
		cin >> choiceNumRoute;
		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceNumRoute) {
			Index = Index->GetNext();
			if (Index == nullptr) {
				Index = Head;
				throw "\n\nМаршрута с таким номером нет в списке !!!\n\n";
			}
		}
		cout << "\n\nНомер маршрута: " << (Index->GetInformationROUTE())->GetNumberRoute();
		cout << "\nНачальный пункт: " << (Index->GetInformationROUTE())->GetNameStart();
		cout << "\nКонечный пункт: " << (Index->GetInformationROUTE())->GetNameFinish();
		Index = Head;
		cout << "\n\n";
		system("pause");
	}
	catch (const char* str) {
		cout << str;
		system("pause");
	}
	catch (MyException& ex) {
		ex.GetNumError();
		system("pause");
	}
}

void List::Change() {
	try {
		if (Tail == nullptr)
			throw MyException();

		int len;
		int choiceChange;
		int choicePoint;
		int changeNumberRoute;
		Show();
		cout << "\n\nВведите номер маршрута, данные которого вы хотите изменить: ";
		cin >> choiceChange;
		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceChange) {
			Index = Index->GetNext();
			if (Index == nullptr) {
				Index = Head;
				throw "\n\nМаршрута с таким номером нет в списке !!!\n\n";
			}
		}
		Index = Head;
		system("cls");

		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceChange) {
			Index = Index->GetNext();
		}
		cout << "\n\nНомер маршрута: " << (Index->GetInformationROUTE())->GetNumberRoute();
		cout << "\nНачальный пункт: " << (Index->GetInformationROUTE())->GetNameStart();
		cout << "\nКонечный пункт: " << (Index->GetInformationROUTE())->GetNameFinish();


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
			throw MyException("\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 3.\n\n");
			break;
		}
		Index = Head;
	}
	catch (const char* str) {
		cout << str;
		system("pause");
	}
	catch (MyException& ex) {
		ex.GetNumError();
		system("pause");
	}
}

void List::operator!() {
	try {
		if (Tail == nullptr)
			throw MyException();

		int cnt = 1;
		int choiceDelete;
		Show();
		cout << "\n\n\nВведите номер маршрута, который хотите удалить: ";
		cin >> choiceDelete;

		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceDelete) {
			Index = Index->GetNext();
			if (Index == nullptr) {
				Index = Head;
				throw "\n\nМаршрута с таким номером нет в списке !!!\n\n";
			}
		}
		Index = Head;


		while ((Index->GetInformationROUTE()->GetNumberRoute()) != choiceDelete) {
			Index = Index->GetNext();
		}

		if (Head == Tail) {
			Head = nullptr;
			Tail = nullptr;
			delete Index;
			Index = nullptr;
			return;
		}
		else {
			if (Index == Tail) {
				Tail = Index->GetPrev();
				Tail->SetNext(nullptr);
				delete Index;
				Index = Tail;
			}
			else {
				if (Index == Head) {
					Head = Index->GetNext();
					Head->SetPrev(nullptr);
					delete Index;
					Index = Head;
				}
				else {
					(Index->GetPrev())->SetNext(Index->GetNext());
					(Index->GetNext())->SetPrev(Index->GetPrev());
					delete Index;
					Index = Head;
				}
			}
		}
		Index = Head;
	}
	catch (const char* str) {
		cout << str;
		system("pause");
	}
	catch (MyException& ex) {
		ex.GetNumError();
		system("pause");
	}
}

void List::Sorting() {

	// сортировка пузырьком

	while (Tail->GetPrev() != nullptr) {
		Element* Index2 = Index->GetNext();
		while (Index != Tail) {
			if ((Index2->GetInformationROUTE())->GetNumberRoute() < (Index->GetInformationROUTE())->GetNumberRoute()) {
				Index2->SetPrev(Index->GetPrev());
				if (Index->GetPrev() != nullptr)
					(Index->GetPrev())->SetNext(Index2);
				Index->SetPrev(Index2);
				Index->SetNext(Index2->GetNext());
				if (Index2->GetNext() != nullptr)
					(Index2->GetNext())->SetPrev(Index);
				Index2->SetNext(Index);
				while (Head->GetPrev() != nullptr)
					Head = Head->GetPrev();
				while (Tail->GetNext() != nullptr)
					Tail = Tail->GetNext();
			}
			else {
				Index = Index->GetNext();
				Index2 = Index->GetNext();
				continue;
			}
			Index2 = Index->GetNext();
		}
		Index = Head;
		Tail = Tail->GetPrev();
	}
	Index = Head;
	while (Head->GetPrev() != nullptr)
		Head = Head->GetPrev();
	while (Tail->GetNext() != nullptr)
		Tail = Tail->GetNext();
}
