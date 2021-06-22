#include <iostream>
using namespace std;

#pragma region BaseClass_1

class BaseClass_1 {
	friend void Nothing();//友元函数
	friend class BaseClass_2;//友元类 
public:
	int v1, v2;
	int static staticv;
	BaseClass_1();
};

BaseClass_1::BaseClass_1() {
}
//静态成员变量，必须在类的外边赋值
int BaseClass_1::staticv = 10;

//友元函数
void Nothing() {}
#pragma endregion


#pragma region BaseClass_2

class BaseClass_2 {
public:
	char c;
	string s;
	void friendFunc();
};

//友元类可以用私有属性
void BaseClass_2::friendFunc() {
	BaseClass_1 bc;
	bc.v1;

	DerivedClass dc;
	dc.v4;
}

#pragma endregion


#pragma region DerivedClass

class DerivedClass : public BaseClass_1, BaseClass_2
{
	void  friendFunc();
public:
	int v3;
private:
	int v4;

	//声明base的一个方法为友元函数
	friend void	BaseClass_2::friendFunc();
};

void DerivedClass::friendFunc() {}

#pragma endregion

int main()
{
	//对象大小，是 基类size+派生类size
	{

		BaseClass_1 bc_1;
		BaseClass_2 bc_2;
		DerivedClass dc;
		std::cout << sizeof(bc_1) << endl;
		std::cout << sizeof(bc_2) << endl;
		std::cout << sizeof(dc) << endl;
	}


	std::cout << "Hello World!\n";
}

