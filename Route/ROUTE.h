#pragma once

class ROUTE{
private:
	char* NameStart;	// �������� ���������� ������ ��������
	char* NameFinish;	// �������� ��������� ������ ��������
	int NumberRoute;	// ����� ��������
public:
	char* GetNameStart();
	void SetNameStart(char* NameStart);
	char* GetNameFinish();
	void SetNameFinish(char* NameFinish);
	int GetNumberRoute();
	void SetNumberRoute(int NumberRoute);
};