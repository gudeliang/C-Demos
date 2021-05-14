// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//给a起别名
	{
		int a = 10;
		int &b = a;
	}

	//指针 b 是 a的地址
	{
		int a = 10;
		int * b = &a;
	}

	{
		//创建数组，释放数组
		int *pArray;
		pArray = new int[10];
		delete[]pArray;
	}

	{

		int n = 2, *p = &n, *q = p;
		n = *p;
		p = q;
		*p = *q;
	}

	{

		//初始化一个 int类型指针， 这个指针初始值是10
		int *P = new int(10);

	}

	{
		//string 类型
		string str = "四2";

		//可以用数组给字符串赋值
	/*	char ch[] = { '3','2','1' };
		str = ch;
*/
		std::cout << str << "长度" << str.size() << endl;


		string strArray[] = { "我","13","1","1" };

		std::cout << sizeof(strArray) / sizeof(strArray[1]) << endl;

	}

	{

		string a = "";
		if (a[0] == 0) {
			printf("这是空字符串\n");
		}

	}

	{
		char p[] = "as";
		char pp = 'a';
		std::cout << sizeof(p) << sizeof(pp);
	}

	std::cout << "Hello World!\n";
	std::cin;
}

void CreateCahr(string str) {

	char c[10];
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
