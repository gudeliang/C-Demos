// 类的相关定义.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#pragma warning(disable: 4996)

using namespace std;


#pragma region 创建类 MyClass

class MyClass
{
public:
	MyClass();
	MyClass(int v);
	~MyClass();
	string  GetMyName();

private:
	string Name;
};

MyClass::MyClass()
{
}

MyClass::MyClass(int v)
{
}

MyClass::~MyClass()
{
}

#pragma endregion


#pragma region 创建类PhoneClass

class PhoneClass {
public: PhoneClass();
		~PhoneClass();
		string GetPhoneName();
		PhoneClass GetMy();
		double Price;
};

PhoneClass::PhoneClass() {};
PhoneClass::~PhoneClass() {};

string PhoneClass::GetPhoneName() {
	return "apple";
};

PhoneClass PhoneClass::GetMy() {
	Price = 5000;
	return *this;
}

string MyClass::GetMyName() {
	Name = "特朗普";
	return Name;
}

class PhoneTest
{
public:
	PhoneTest();
	~PhoneTest();
	int A;
	int *P = &A;

private:

};

PhoneTest::PhoneTest()
{
}

PhoneTest::~PhoneTest()
{
}

#pragma endregion

#pragma region 小Demo，人员  工资

class CEmployee
{
public:
	CEmployee();
	~CEmployee();
	void SetName(string n);
	string GetName();
	void SetSalary(int s);
	int Getsalary();
	double AverageSalary(CEmployee ce);

private:
	string name;
	int salary;
};

CEmployee::CEmployee()
{
}

CEmployee::~CEmployee()
{
}

void CEmployee::SetName(string n) { name = n; }
string CEmployee::GetName() { return name; };

void CEmployee::SetSalary(int n) { salary = n; }
int CEmployee::Getsalary() { return salary; };

double CEmployee::AverageSalary(CEmployee c) { return (salary + c.salary) / 2; };

#pragma endregion

#pragma region 变量作用域

int M = 10;

#pragma endregion

#pragma region 冒泡排序

void maopao() {
	int arr[5]{ 0,1,2,3,4 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < arrLength - 1; i++)
	{
		for (int j = i + 1; j < arrLength; j++)
		{
			int t = arr[i];
			if (arr[i] < arr[j])
			{
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}

	std::cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << endl;
}

#pragma endregion

#pragma region nine * nine

void nine() {

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << '*' << i << '=' << j * i << "  ";
		}
		cout << endl;
	}

}

#pragma endregion

#pragma region 大写字母转换成相应小写字母

void to_lower(string a)
{
	// 字符串是以  \0   结束 
	for (int i = 0; i < 10 && a[i] != '\0'; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] += 32;
		}
	}
	cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
}

#pragma endregion

#pragma region 复制构造函数

class cpy_Constructors
{

public:
	cpy_Constructors();
	cpy_Constructors(cpy_Constructors &cpy);
	~cpy_Constructors();
	string name;

private:

};

cpy_Constructors::cpy_Constructors()
{
}

cpy_Constructors::cpy_Constructors(cpy_Constructors &cpy) {
	name = cpy.name;
}

cpy_Constructors ::~cpy_Constructors()
{
}

#pragma endregion

#pragma region 静态成员

class StaticMyClass
{
public:
	static int A;
	int b;
	StaticMyClass();
	~StaticMyClass();

private:

};
//类体内的静态变量，只能在类体外边进行赋值   进行一次性定义
int StaticMyClass::A = 10;
StaticMyClass::StaticMyClass()
{
}

StaticMyClass::~StaticMyClass()
{
}

#pragma endregion

#pragma region 判断两个字符串是否包含

int strContains(string a, string b)
{
	string::size_type st = a.find(b);
	if (st == string::npos)
	{
		return -1;
	}

	return st;
}

#pragma endregion

#pragma region 常量成员

class constClass
{
public:
	constClass();
	~constClass();
	const int a;
	void VoidFunc() const;

private:

};

constClass::constClass() :a(10)
{
	VoidFunc();
}

constClass::~constClass()
{
}

//常函数
void constClass::VoidFunc() const {

}


#pragma endregion

#pragma region 友元函数
class friendTest
{ 
	friend class friendClass;
public:
	friendTest();
	~friendTest(); 

private:
	int x = 10;
	int y = 11;
};

friendTest::friendTest()
{
	x = 100;
}

friendTest::~friendTest()
{
}

class friendClass
{
	//友元函数
	friend void SetName(friendClass p);
	friend class friendTest;

public:
	friendTest ft;
	int ftValue = ft.x;
	friendClass();
	~friendClass();
private:
	int ala = 10;
};

friendClass::friendClass()
{
}

friendClass::~friendClass()
{
}

void SetName(friendClass p) {
	//可以直接使用私有成员变量
	p.ala;
}



#pragma endregion

#pragma region 判断两个字符串是否包含，不包含返回-1， 包含返回首字符位置值
 
void cts(string a, string b)
{
	size_t st = a.find(b);
	if (st == string::npos)
	{
		cout << "1" << endl;
	}
	else
		cout << st + 1 << endl;
}

void cts2(string a, string b)
{
	int j = 0;//存储b的下标
	int k = 0;//起始位置
	for (int i = 0; i < (int)a.size(); i++)
	{
		if (a[i] == b[j])
		{
			j++;
			if (j == 1)
				k = i + 1;
			if (j == b.size())
			{
				cout << k << endl; return;
			}
		}
		else
			j = 0;
	}

	cout << -1 << endl;
}

#pragma endregion

#pragma region 比较字符串大小strcmp

void m()
{
	const char *a[5] = { "new","class","double","main","public" };
	const char *p1, *p2;
	p1 = p2 = a[0];
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(a[i], p1) > 0) p1 = a[i];
		if (strcmp(a[i], p2) < 0) p2 = a[i];
	}
	cout << p1 << "," << p2 << endl;
}

#pragma endregion


int main()
{
	//指针调用方法
	MyClass *p = new MyClass();
	std::cout << p->GetMyName();

	//调用PhoneClass类方法
	PhoneClass PhoneClass1;
	std::cout << PhoneClass1.GetPhoneName() << "价格" << PhoneClass1.GetMy().Price << endl;

	//调用MyClass类方法
	MyClass MyClass1;
	std::cout << MyClass1.GetMyName() << endl;

	//给MyClass起个别名
	MyClass &mc = MyClass1;

	//用指针给PhoneTest1中的A赋值
	PhoneTest PhoneTest1;
	*PhoneTest1.P = 10;

	//小Demo，人员  工资
	CEmployee ce_zs;
	CEmployee ce_ls;
	ce_zs.SetName("张三");
	ce_zs.SetSalary(10000);

	ce_ls.SetName("李四");
	ce_ls.SetSalary(5000);

	std::cout << ce_zs.GetName() << "工资是" << ce_zs.Getsalary() << endl;
	std::cout << ce_ls.GetName() << "工资是" << ce_ls.Getsalary() << endl;
	std::cout << "俩人平均工资是" << ce_zs.AverageSalary(ce_ls) << endl;

	//输入个name  再输出
	string name;
	std::cout << "请输入名称 ：\t";
	std::cin >> name;
	std::cout << "输入的名称是 ：\t" << name << endl;

	//求数组长度
	std::cout << "求数组长度 ：" << endl;
	float float_array[12];
	cout << sizeof(float_array) / sizeof(float_array[0]);

	//冒泡排序
	std::cout << "冒泡排序 ：" << endl;
	maopao();

	//九九乘法表
	nine();

	//大写转换小写
	char to_lowerChar[10]{   };
	to_lower("CSDs啊");

	//强制转换
	{
		int zh_1 = 10; int *zz_zh_1 = &zh_1;
		cout << "强制转换为string ：" << to_string(zh_1) << endl;
		cout << "强制转换为double ：" << static_cast<double>(zh_1) << endl;
		cout << "指针强制转换为double ：" << static_cast<double>(*zz_zh_1) << endl;
	}

	//复制构造函数
	{
		cpy_Constructors cpy_Con_1; cpy_Con_1.name = "张三";
		cpy_Constructors cpy_Con_2(cpy_Con_1);
		cout << "复制构造函数：" << cpy_Con_2.name << endl;

		cpy_Constructors ss[2];
		ss[0] = cpy_Constructors(cpy_Con_1);
		ss[1] = cpy_Constructors();
	}

	//静态变量
	{
		//访问静态变量
		int a = StaticMyClass::A;

		//对象访问
		StaticMyClass sc; sc.A;

		//指针访问
		StaticMyClass *p = &sc;
		p->A;

	}


	std::cout << "Hello World!\n";
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
