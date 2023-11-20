#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h" 
using std::cout, std::cin, std::endl;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	List TheList;

	int choice1, choice2;

	do {
		system("cls");

		cout << "Меню" << endl
			<< "1) Стандартные потоки (задание 1)" << endl
			<< "2) Файловые и строковые потоки (задание 2)" << endl
			<< "3) Выход из программы" << endl
			<< "Выбранный пункт: ";
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

					break;
				case 6:
					break;
				default:

					break;
				}
			} while (choice2 != 6);
			break;
		case 2:

			break;
		case 3:
			break;
		default:

			break;
		}
	} while (choice1 != 3);

	return 0;
}