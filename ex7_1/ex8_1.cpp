#include <iostream> 
using namespace std;

class Complex
{
private:
    int real;
    int image;
public:
    Complex(int r = 0, int i = 0);
    void ShowComplex();
    // Operator overloading declaration (member function)
    Complex operator+(Complex &c);
	Complex operator-(Complex &c);
	Complex operator*(Complex &c);
};

void Complex::ShowComplex()
{
    if (image > 0)
        cout << "(" << real << "+" << image << "i)" << endl;
    else if (image < 0)
        cout << "(" << real << image << "i)" << endl;
    else
        cout << real << endl;
}

Complex::Complex(int r, int i)
{
    real = r;
    image = i;
}

// Operator overloading definition (member function)
Complex Complex::operator+(Complex &c)
{
	return Complex(real+c.real,image+c.image);
}
Complex Complex::operator-(Complex &c)
{
	return Complex(real-c.real,image-c.image);
}
Complex Complex::operator*(Complex &c)
{
	return Complex(real*c.real-image*c.image,real*c.image+image*c.real);
}


int main()
{
    Complex x(1, 2), y(2, 4), z;

    cout << "-- Addition of two Complex objects --\n";
    z = x + y;
    x.ShowComplex();
    y.ShowComplex();
    z.ShowComplex();

    cout << "\n-- Subtraction of two Complex objects --\n";
    z = x - y;
    x.ShowComplex();
    y.ShowComplex();
    z.ShowComplex();

    cout << "\n-- Multiplication of two Complex objects --\n";
    z = x * y;
    x.ShowComplex();
    y.ShowComplex();
    z.ShowComplex();

    return 0;	
}
