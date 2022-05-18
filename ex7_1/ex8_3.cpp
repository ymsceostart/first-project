#include <iostream>
using namespace std;


class Circle
{
	int radius;

public:
	Circle(int radius = 0){ this->radius = radius; }
	void show() { cout << "radius = " << radius << endl; }
	friend Circle operator + (int a, Circle &a1);
	friend Circle operator ++(Circle& a1);
	friend Circle operator ++(Circle& a1, int );
	friend ostream& operator << (ostream&, Circle& c);
};
 
Circle operator++(Circle& a1)
{
	a1.radius = a1.radius + 1;
	return a1;
}

Circle operator +(int a, Circle &a1)
{
	return Circle(a1.radius + a);
}
Circle operator++(Circle& a1, int a)
{
	Circle temp;
	temp.radius = a1.radius;
	a1.radius = a1.radius + 1;
	return temp;
	
}
ostream& operator <<(ostream& output, Circle& c)
{
	cout << "radius = " << c.radius << endl;
	return output;
}


int main() {
	Circle a(5), b(4);

	++a;
	b = a++;
	a.show();
	b.show();
	cout << endl;
	b = 1 + a;
	cout << a << b;

	return 0;
}