#include "Բ��������.h"
#include <iostream>
#include "string"
using namespace std;
//���һ��Բ��circle ��һ�������� table��circle�����˽�����ݳ�Ա radius ����Բ������� getarea()
//table�������˽�����ݳ�Ա height �ͷ��ظ߶ȵĳ�Ա���� getheight() ��roundtable ��̳�����������ͳ�Ա����
//�����˽�����ݳ�Ա color ����Ӧ�ĳ�Ա���� getcolor ������ main �����Ѿ�����������ɳ��򲿷�

#pragma region Բ


circle::circle(double r)
{
	radius = r;
}

#pragma endregion

#pragma region ����



table::table(double h)
{
	height = h;
}

#pragma endregion

#pragma region roundtable
 

string roundtable::getcolor() { return color; };

#pragma endregion