#include <iostream>
#include "string"
using namespace std;

#include "圆类桌子类.h"
#include "Bank类.h"

int main()
{

#pragma region 圆类桌子类
	//设计一个圆类circle 和一个桌子类 table。circle类包含私有数据成员 radius 和求圆面积函数 getarea()
//table类包含了私有数据成员 height 和返回高度的成员函数 getheight() 。roundtable 类继承所有上述类和成员函数
//添加了私有数据成员 color 和相应的成员函数 getcolor 。其中 main 函数已经给出。请完成程序部分
	roundtable rt(0.8, 1.2, "黑色");
	cout << "圆桌属性数据" << endl;
	cout << "高度:" << rt.getheight() << "米" << endl;
	cout << "面积:" << rt.getarea() << "平方米" << endl;
	cout << "颜色:" << rt.getcolor() << endl;
#pragma endregion

#pragma region Bank存入取出

	Bank bk;

	//存入
	char date[] = "2018-05-06";
	bk.bankin(date, 100);

	//取出
	*date = *"2018-05-07";
	bk.bankout(date, 50);

	//输出记录
	bk.disp();

#pragma endregion

	std::cout << "Hello World!\n";
}
