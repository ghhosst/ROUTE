#pragma once
#include <iostream>
#include <fstream>
using std::exception, std::ifstream;

class MyException : public exception {
private:
	int NumError; // код ошибки, 1 - Keeper пустой.
public:
	MyException(const char* msg) :exception(msg) {}
	MyException();
	void GetNumError();
};