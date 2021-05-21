#include <stdio.h>
#include <string.h>
#define Max 100
using namespace std;

//设计一个Bank类，实现银行某账号的资金往来账目管理，
//	包括建账号、存入、取出等。解：Bank类包括私有数据成员top(当前账指针)，date(日期)，money(金额)，rest(余额)和sum(累计余额)。
//	有三个成员函数bankin()(处理存入账)，bankout()(处理取出账)和disp()(输出明细账)请完成函数的实现。

class Bank
{

private:
	int top;
	char date[Max][10];//日期
	int money[Max];//金额
	int rest[Max];//余额
	static int sum;//累计余额

public:
	Bank();
	void bankin(char d[], int m);//处理存入账
	void bankout(char d[], int m);//处理取出账
	void disp();//输出明细账
};

