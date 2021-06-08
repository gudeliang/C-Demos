#include <iostream>
#include <string>
using namespace std;

class coutIn
{
public:
	int a = 15, b = 25;
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
	//cout  cin 重载
	friend void operator<< (const coutIn &c1, const coutIn &c2);
	friend void operator>> (const coutIn &c1, const coutIn &c2);


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

void operator<< (const coutIn &c1, const coutIn &c2) {


};
void operator>> (const coutIn &c1, const coutIn &c2) {


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

	std::cout << "Hello World!\n";
}



