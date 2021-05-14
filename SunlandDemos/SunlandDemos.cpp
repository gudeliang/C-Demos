#include <iostream>
#include "string"

using namespace std;
//设计一个圆类circle 和一个桌子类 table。circle类包含私有数据成员 radius 和求圆面积函数 getarea()
//table类包含了私有数据成员 height 和返回高度的成员函数 getheight() 。roundtable 类继承所有上述类和成员函数
//添加了私有数据成员 color 和相应的成员函数 getcolor 。其中 main 函数已经给出。请完成程序部分

#pragma region 圆
class  circle
{
public:
	circle(double r);
	double getarea() {
		return radius
			* radius
			*3.14;
	};

private:
	double radius;

};

circle::circle(double r)
{
	radius = r;
}

#pragma endregion

#pragma region 桌子

class table
{
public:
	table(double h);
	double getheight() { return height; };

private:
	double height;
};

table::table(double h)
{
	height = h;
}

#pragma endregion

#pragma region roundtable

class roundtable : public table, public circle
{
public:
	roundtable(double a, double b, string c);
	string getcolor();

private:
	string color;
};

roundtable::roundtable(double a, double b, string c) : circle(a), table(b)
{
	color = c;
}

string roundtable::getcolor() { return color; };

#pragma endregion


int main()
{
	roundtable rt(0.8, 1.2, "黑色");

	cout << "圆桌属性数据" << endl;
	cout << "高度:" << rt.getheight() << "米" << endl;
	cout << "面积:" << rt.getarea() << "平方米" << endl;
	cout << "颜色:" << rt.getcolor() << endl;

	std::cout << "Hello World!\n";
}
