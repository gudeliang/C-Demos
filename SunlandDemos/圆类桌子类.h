#include <string>
using namespace std;
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

class table
{
public:
	table(double h);
	double getheight() { return height; };

private:
	double height;
};

class roundtable : public table, public circle
{
private:
	string color;

public:
	roundtable(double a, double b, string c) :table(a), circle(b) { color = c; };
	string getcolor();


};

