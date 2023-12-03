#include "MyException.h"


MyException::MyException() {
	NumError = 1;
	std::cout << "\n\nВ списке нет ни одного маршрута !!!\n\n";
}

void MyException::GetNumError() { std::cout << "\nКод ошибки: " << NumError << "\n\n"; };