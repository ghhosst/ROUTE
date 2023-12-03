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

			cout << "Меню" << endl
				<< "1) Стандартные потоки (задание 1)" << endl
				<< "2) Файловые и строковые потоки (задание 2)" << endl
				<< "3) Выход из программы" << endl
				<< "Выбранный пункт: ";
			try {
				cin >> choice1;

				switch (choice1) {
				case 1:
					do {
						system("cls");
						cout << "Маршрут" << endl
							<< "1) Добавить маршрут" << endl
							<< "2) Вывести все маршруты на экран" << endl
							<< "3) Вывести один определённый маршрут на экран" << endl
							<< "4) Изменить данные о маршруте" << endl
							<< "5) Удалить маршрут" << endl
							<< "6) Выйти из программы" << endl
							<< "Выбранный пункт: ";
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
							throw MyException("\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт меню от 1 до 6.\n\n");
							break;
						}
					} while (choice2 != 6);
					break;
				case 2:
					system("cls");
					cout << "Считать текст из файла ?" << endl
						<< "1) Да" << endl
						<< "2) Нет" << endl
						<< "Выбранный пункт: ";
					cin >> choice3;
					switch (choice3) {
					case 1:
						cout << "\n\nСлова, начинающиеся и заканчивающиеся на гласные буквы:\n\n";
						Words();
						system("pause");
						break;
					case 2:
						break;
					default:
						throw MyException("\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт меню от 1 до 2.\n\n");
						break;
					}
					break;
				case 3:
					break;
				default:
					throw MyException("\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт меню от 1 до 3.\n\n");
					break;
				}
			}
			catch (const std::istream::failure& ex) {
				system("cls");
				cout << "\n\nВведено некорректное значение !!!" << endl
					<< ex.what() << "\n" << ex.code() << endl
					<< "Повторите ввод...\n\n";
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