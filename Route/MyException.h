#pragma once
#include <iostream>
#include <fstream>
using std::exception, std::ifstream;

class MyException : public exception {
private:
	int NumError; // ��� ������, 1 - Keeper ������.
public:
	MyException(const char* msg) :exception(msg) {}
	MyException();
	void GetNumError();
};