#include "pch.h"
#include "题库练习.h"
#include<iostream>
#include<math>

题库练习::题库练习()
{
}

//在三角形类TRI实现两个函数，功能是输入三个顶点坐标判断是否构成三角形

class point {
	private：float x，y；
		public：point(float a，float b) { x = a；y = b； }
	point() { x = 0；y = 0； }
	void set(float a，float b) { x = a；y = b； }
	float getx() { return x； }
	float gety() { return y； }
}；
class tri {
	point x，y，z；
		float s1，s2，s3；
public:....settri(....)；／／用于输入三个顶点坐标
		....test(....)；／／用于判断是否构成三角形
}；请写出两个函数的过程(如果需要形式参数，请给出形参类型和数量，以及返回值类型)


题库练习::~题库练习()
	{
	}
