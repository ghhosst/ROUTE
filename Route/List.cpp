#include "List.h"

Element* List::GetHead() { return Head; };

void List::SetHead(Element* Head) { this->Head = Head; };

Element* List::GetTail() { return Tail; };

void List::SetTail(Element* Tail) { this->Tail = Tail; };

Element* List::GetIndex() { return Index; };

void List::SetIndex(Element* Index) { this->Index = Index; };

List::List() {
	system("cls");
	std::cout << "\n------|������ ����������� ������ List (��� ����������)|------\n";
	system("pause");

	Head = nullptr;
	Tail = nullptr;
	Index = nullptr;
}

List::List(Element* Head, Element* Tail, Element* Index) {
	std::cout << "\n------|������ ����������� ������ List (� ����������)|------\n";
	system("pause");

	this->Head = Head;
	this->Tail = Tail;
	this->Index = Index;
}

List::List(const List& other) {
	std::cout << "\n------|������ ����������� ������ List (�����������)|------\n";
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
	std::cout << "\n------|������ ���������� ������ List|------\n";
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
	cout << "������� ����� ��������: ";
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
		throw MyException("\n\n������� � ����� ������� ��� ���� � ������ !\n����� �������� ������ ���� ����������.\n\n");

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
			cout << "\n\n����� ��������: " << (Index->GetInformationROUTE())->GetNumberRoute();
			cout << "\n��������� �����: " << (Index->GetInformationROUTE())->GetNameStart();
			cout << "\n�������� �����: " << (Index->GetInformationROUTE())->GetNameFinish();
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
		cout << "\n\n\n������� ����� ��������, ������� ������ ������� �� �����...\n";
		cin >> choiceNumRoute;
		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceNumRoute) {
			Index = Index->GetNext();
			if (Index == nullptr) {
				Index = Head;
				throw "\n\n�������� � ����� ������� ��� � ������ !!!\n\n";
			}
		}
		cout << "\n\n����� ��������: " << (Index->GetInformationROUTE())->GetNumberRoute();
		cout << "\n��������� �����: " << (Index->GetInformationROUTE())->GetNameStart();
		cout << "\n�������� �����: " << (Index->GetInformationROUTE())->GetNameFinish();
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
		cout << "\n\n������� ����� ��������, ������ �������� �� ������ ��������: ";
		cin >> choiceChange;
		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceChange) {
			Index = Index->GetNext();
			if (Index == nullptr) {
				Index = Head;
				throw "\n\n�������� � ����� ������� ��� � ������ !!!\n\n";
			}
		}
		Index = Head;
		system("cls");

		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceChange) {
			Index = Index->GetNext();
		}
		cout << "\n\n����� ��������: " << (Index->GetInformationROUTE())->GetNumberRoute();
		cout << "\n��������� �����: " << (Index->GetInformationROUTE())->GetNameStart();
		cout << "\n�������� �����: " << (Index->GetInformationROUTE())->GetNameFinish();


		cout << "\n\n�������� �����, ������� ������ ��������..." << endl
			<< "1) ����� ��������" << endl
			<< "2) ��������� �����" << endl
			<< "3) �������� �����" << endl
			<< "��������� �����: ";
		cin >> choicePoint;
		switch (choicePoint) {
		case 1:
			cout << "\n������� ����� ��������: ";
			cin >> changeNumberRoute;
			(Index->GetInformationROUTE())->SetNumberRoute(changeNumberRoute);
			break;
		case 2:
			cout << "\n������� ��������� ����� ��������: ";
			(Index->GetInformationROUTE())->SetNameStart(getString(&len));
			break;
		case 3:
			cout << "\n������� �������� ����� ��������: ";
			(Index->GetInformationROUTE())->SetNameFinish(getString(&len));
			break;
		default:
			throw MyException("\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 3.\n\n");
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
		cout << "\n\n\n������� ����� ��������, ������� ������ �������: ";
		cin >> choiceDelete;

		while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceDelete) {
			Index = Index->GetNext();
			if (Index == nullptr) {
				Index = Head;
				throw "\n\n�������� � ����� ������� ��� � ������ !!!\n\n";
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

	// ���������� ���������

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
