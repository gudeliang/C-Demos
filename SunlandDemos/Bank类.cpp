#include "Bank��.h"
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

///�����˺�
void Bank::bankin(char d[], int m)
{
	//���ڸ�ֵ
	strcpy(date[top], d);

	//��ֵ
	money[top] = m;

	//�ۼ����
	sum += m;

	//���     *******���β�����ʣ�µ����
	rest[top] = sum;

	top++;
}


///ȡ�����
void Bank::bankout(char d[], int m)
{
	//���ڸ�ֵ
	strcpy(date[top], d);

	//��ֵ
	money[top] = -m;

	//�ۼ����
	sum -= m;

	//���     *******���β�����ʣ�µ����
	rest[top] = sum;

	top++;
}

void Bank::disp()
{ 
	for (int i = 0; i < top; i++)
	{
		cout << "���ڣ�" << date[i] << endl;
		cout << "��" << money[i] << endl;
		cout << "��" << rest[i] << endl;
	} 
}

Bank::Bank() { top = 0; };

//��̬����,���������ٶ���һ��
int Bank::sum = 0;