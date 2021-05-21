#include "Bank类.h"
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

///存入账号
void Bank::bankin(char d[], int m)
{
	//日期赋值
	strcpy(date[top], d);

	//金额赋值
	money[top] = m;

	//累计余额
	sum += m;

	//余额     *******本次操作后剩下的余额
	rest[top] = sum;

	top++;
}


///取出金额
void Bank::bankout(char d[], int m)
{
	//日期赋值
	strcpy(date[top], d);

	//金额赋值
	money[top] = -m;

	//累计余额
	sum -= m;

	//余额     *******本次操作后剩下的余额
	rest[top] = sum;

	top++;
}

void Bank::disp()
{ 
	for (int i = 0; i < top; i++)
	{
		cout << "日期：" << date[i] << endl;
		cout << "金额：" << money[i] << endl;
		cout << "余额：" << rest[i] << endl;
	} 
}

Bank::Bank() { top = 0; };

//静态变量,在类体外再定义一次
int Bank::sum = 0;