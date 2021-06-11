#include <iostream>
#include <string>
using namespace std;

class coutIn
{
	//cout  cin 重载
	friend ostream & operator<< (ostream &os, const coutIn &c2);
	friend istream & operator>> (istream &is, coutIn &c2);

public:
	int a = 15, b = 25;
	//重载强制转换运算符
	operator double() { return a; }
private:

};

class myComplex
{
public:
	myComplex();
	myComplex(double r, double i);
	~myComplex();
	void outCom();
	myComplex operator-(const myComplex &c);
	friend myComplex operator+(const myComplex &c1, const myComplex &c2);//友元运算符重载
	myComplex operator+(const myComplex &c1); //基本运算符重载
	friend myComplex operator+(const myComplex &c1, int i);//友元运算符重载
	friend myComplex operator+(int i, const myComplex &c2);//友元运算符重载 
	//++ -- 运算符重载
	myComplex& operator++();// 前置++
	myComplex operator++(int);// 后置++

private:
	double ral, imag;
};

myComplex::myComplex() { ral = 0; imag = 0; }
myComplex::myComplex(double r, double i) { ral = r; imag = i; }
myComplex::~myComplex() {}
void myComplex::outCom() { cout << ral << "," << imag; };
myComplex myComplex ::operator-(const myComplex &c) { return myComplex(this->ral - c.ral, this->imag - c.imag); }
myComplex operator+(const myComplex &c1, const myComplex &c2) { return myComplex(c1.ral + c2.ral, c1.imag + c2.imag); }//友元运算符重载
myComplex myComplex :: operator+(const myComplex &c) { return myComplex(this->ral + c.ral, this->imag + c.imag); };//基本运算符重载
myComplex operator+(const myComplex &c1, int i) { return myComplex(c1.imag + i, c1.ral); } //友元运算符重载
myComplex operator+(int i, const myComplex &c2) { return myComplex(c2.imag, c2.ral + i); } //友元运算符重载 

myComplex& myComplex :: operator++ () {// 前置++
	this->imag++;
	this->ral++;
	return *this;
}
myComplex myComplex :: operator++ (int) {// 后置++
	myComplex cp = *this;
	this->imag++;
	this->ral++;
	return cp;
}

ostream & operator<< (ostream & os, const coutIn & c2) {
	os << c2.a << "--------" << c2.b << endl;
	return os;
};
istream & operator>> (istream & is, coutIn & c2) {
	int num;
	is >> num;
	c2.a += num;
	return is;
};

struct car {
	double price;
	string color;
	enum types
	{
		hld = 0,
		klz = 1
	};
	int set() { return 1; };
};


int main()
{
	myComplex c1(1, 2), c2(3, 4), res;
	c1.outCom();
	cout << "operator+"; cout << "=";
	c2.outCom();
	res = c1 + c2;
	cout << endl << "---------------------------------" << endl;
	res.outCom(); //输出结果
	cout << endl << "---------------------------------" << endl;

	res = c1 - c2;
	res.outCom(); //输出结果

	cout << endl << "------- 前置++--------华丽的分割线----------------" << endl;
	{
		myComplex test = c1++;
		test.outCom();
	}

	cout << endl << "--------后置++-------华丽的分割线----------------" << endl;
	{
		myComplex test = ++c1;
		test.outCom();
	}

#pragma region 流插操作算符重载
	{
		coutIn c;

		cout << endl << "--------流插入运算符重载----<<---华丽的分割线----------------" << endl;
		cout << c << endl;
		//也可以这么用
		operator <<(cout, c);

		cout << endl << "--------流读取运算符重载---->>---华丽的分割线----------------" << endl;
		cin >> c;
		cout << c << endl;
	}
#pragma endregion

#pragma region 重载强制转换运算符

	{
		cout << endl << "--------重载强制转换运算符---华丽的分割线----------------" << endl;
		coutIn c;
		cout << (double)c << endl;
	}

#pragma endregion


	std::cout << "Hello World!\n";
}



