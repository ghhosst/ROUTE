#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h" 
#include "Words.h"
using std::cout, std::cin, std::endl, std::streamsize, std::numeric_limits;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	cin.exceptions(std::istream::failbit);

	List TheList;

	int choice1, choice2, choice3;

	
		do {
			system("cls");

			cout << "����" << endl
				<< "1) ����������� ������ (������� 1)" << endl
				<< "2) �������� � ��������� ������ (������� 2)" << endl
				<< "3) ����� �� ���������" << endl
				<< "��������� �����: ";
			try {
				cin >> choice1;

				switch (choice1) {
				case 1:
					do {
						system("cls");
						cout << "�������" << endl
							<< "1) �������� �������" << endl
							<< "2) ������� ��� �������� �� �����" << endl
							<< "3) ������� ���� ����������� ������� �� �����" << endl
							<< "4) �������� ������ � ��������" << endl
							<< "5) ������� �������" << endl
							<< "6) ����� �� ���������" << endl
							<< "��������� �����: ";
						cin >> choice2;
						switch (choice2) {
						case 1:
							TheList.Insert();
							break;
						case 2:
							TheList.Show();
							break;
						case 3:
							TheList.ShowOnlyOne();
							break;
						case 4:
							TheList.Change();
							break;
						case 5:
							!TheList;
							break;
						case 6:
							break;
						default:
							throw MyException("\n\n������������ �����!!!\n����������, �������� ����� ���� �� 1 �� 6.\n\n");
							break;
						}
					} while (choice2 != 6);
					break;
				case 2:
					system("cls");
					cout << "������� ����� �� ����� ?" << endl
						<< "1) ��" << endl
						<< "2) ���" << endl
						<< "��������� �����: ";
					cin >> choice3;
					switch (choice3) {
					case 1:
						cout << "\n\n�����, ������������ � ��������������� �� ������� �����:\n\n";
						Words();
						system("pause");
						break;
					case 2:
						break;
					default:
						throw MyException("\n\n������������ �����!!!\n����������, �������� ����� ���� �� 1 �� 2.\n\n");
						break;
					}
					break;
				case 3:
					break;
				default:
					throw MyException("\n\n������������ �����!!!\n����������, �������� ����� ���� �� 1 �� 3.\n\n");
					break;
				}
			}
			catch (const std::istream::failure& ex) {
				system("cls");
				cout << "\n\n������� ������������ �������� !!!" << endl
					<< ex.what() << "\n" << ex.code() << endl
					<< "��������� ����...\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
			}
			catch (const MyException& ex) {
				cout << ex.what();
				system("pause");
			}
		} while (choice1 != 3);

	

	return 0;
}