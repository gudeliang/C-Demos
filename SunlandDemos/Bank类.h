#include <stdio.h>
#include <string.h>
#define Max 100
using namespace std;

//���һ��Bank�࣬ʵ������ĳ�˺ŵ��ʽ�������Ŀ����
//	�������˺š����롢ȡ���ȡ��⣺Bank�����˽�����ݳ�Աtop(��ǰ��ָ��)��date(����)��money(���)��rest(���)��sum(�ۼ����)��
//	��������Ա����bankin()(���������)��bankout()(����ȡ����)��disp()(�����ϸ��)����ɺ�����ʵ�֡�

class Bank
{

private:
	int top;
	char date[Max][10];//����
	int money[Max];//���
	int rest[Max];//���
	static int sum;//�ۼ����

public:
	Bank();
	void bankin(char d[], int m);//���������
	void bankout(char d[], int m);//����ȡ����
	void disp();//�����ϸ��
};

