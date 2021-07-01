#include <iostream>
using namespace std;

class  DerivedClass;
class  BaseClass_1;
class  BaseClass_2;


#pragma region BaseClass_1

class BaseClass_1 {
	friend void Nothing();//友元函数
	friend class BaseClass_2;//友元类 
public:
	int v1, v2;
	int static staticv;
	BaseClass_1();
	void WriteLineText() { cout << "输出一段Text" << endl; };
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

#pragma endregion

#pragma region DerivedClass

class DerivedClass : public BaseClass_1, public BaseClass_2
{


	void  friendFunc();
public:
	int v3;
	DerivedClass() :BaseClass_1() {};
private:
	int v4;

	//声明base的一个方法为友元函数
	friend void	BaseClass_2::friendFunc();
};

void DerivedClass::friendFunc() {}

#pragma endregion

//友元类可以用私有属性
void BaseClass_2::friendFunc() {
	BaseClass_1 bc;
	bc.v1;

	DerivedClass dc;
	dc.v4;
}

int main()
{
	//对象大小，是 基类size+派生类size
	{
		BaseClass_1 bc_1;
		BaseClass_2 bc_2;
		DerivedClass dc;
		dc.BaseClass_1::WriteLineText();//调用基类方法
		std::cout << sizeof(bc_1) << endl;
		std::cout << sizeof(bc_2) << endl;
		std::cout << sizeof(dc) << endl;

		//派生类可以赋值给基类 
		bc_1 = dc;
		bc_2 = dc;

		//派生类对象可以初始化基类对象的引用
		BaseClass_1 &dz = dc;

		//派生类的地址可以隐式转换味基类的指针
		BaseClass_1 *zz = &dc;
	}

	std::cout << "Hello World!\n";
}

