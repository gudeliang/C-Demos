#include "圆类桌子类.h"
#include <iostream>
#include "string"
using namespace std;
//设计一个圆类circle 和一个桌子类 table。circle类包含私有数据成员 radius 和求圆面积函数 getarea()
//table类包含了私有数据成员 height 和返回高度的成员函数 getheight() 。roundtable 类继承所有上述类和成员函数
//添加了私有数据成员 color 和相应的成员函数 getcolor 。其中 main 函数已经给出。请完成程序部分

#pragma region 圆


circle::circle(double r)
{
	radius = r;
}

#pragma endregion

#pragma region 桌子



table::table(double h)
{
	height = h;
}

#pragma endregion

#pragma region roundtable
 

string roundtable::getcolor() { return color; };

#pragma endregion