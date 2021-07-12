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


class A {
	int an;
public:
	A() {};
	A(int n) {
		an = n;
	};
	~A() { cout << "A析构函数" << endl; };

	void print() {
		cout << "A对象" << endl;
		cout << an << endl;
	};
	void print(int x) {
		cout << an << endl;
	};
};

class C {
	int cn;
public:
	C(int n) {
		cn = n;
	};
	~C() { cout << "C析构函数" << endl; };

};

class B :public A, public C //基类构造函数的调用顺序 取决于继承的顺序
{
	int bn;
public:
	B(int n) :A(2 * n), C(n) {
		bn = n;
	};
	~B() { cout << "B析构函数" << endl; }

	void print() {
		cout << "基类";  A::print(1);
		cout << "B对象" << endl;
		cout << bn << endl;
	};
};


class  D
{
	int n = 0;
public:
	D()
	{

	};
	D(D &d) { cout << "构造函数" << endl; };
	~D() {};
};


class E : D
{
};



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

	//派生类基类赋值
	{
		A a(10);
		B b(20);
		a.print();
		b.print();
		cout << "华丽分割线---------------" << endl;
		a = b; //b的基类a  会覆盖  对象a   ****
		a.print();
		b.print();

	}

	std::cout << "Hello World!\n";
}

