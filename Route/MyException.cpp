#include "MyException.h"


MyException::MyException() {
	NumError = 1;
	std::cout << "\n\n� ������ ��� �� ������ �������� !!!\n\n";
}

void MyException::GetNumError() { std::cout << "\n��� ������: " << NumError << "\n\n"; };