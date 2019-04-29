#include <iostream>
using namespace std;

class Complex
{
private:
  int real;
  int imaginary;
public:
  Complex();
  Complex(int r,int i);
  void setReal(int r);
  void setImaginary(int i);
  int getReal();
  int getImaginary();
  Complex add(Complex a,Complex b);
  Complex sub(Complex a,Complex b);
  void print();
  Complex operator +(Complex a);
  Complex operator -(Complex a);
};
Complex::Complex()
{
  real = 0;
  imaginary = 0;
}
Complex::Complex(int r,int i)
{
  real = r;
  imaginary = i;
}
void Complex::setReal(int r)
{
  real = r;
}
void Complex::setImaginary(int i)
{
  imaginary = i;
}
int Complex::getReal()
{
  return real;
}
int Complex::getImaginary()
{
  return imaginary;
}
Complex Complex::add(Complex a,Complex b)
{
  Complex c;
  c.real = a.real + b.real;
  c.imaginary = a.imaginary + b.imaginary;
  return c;
}
Complex Complex::sub(Complex a,Complex b)
{
  Complex c;
  c.real = a.real - b.real;
  c.imaginary = a.imaginary - b.imaginary;
  return c;
}
void Complex::print()
{
  cout<<real<<"+"<<imaginary<<"i"<<endl;
}
Complex Complex::operator + (Complex a)
{
  Complex c;
  c.real = a.real + this->real;
  c.imaginary = a.imaginary + this->imaginary;
  return c;
}
Complex Complex::operator - (Complex a)
{
  Complex c;
  c.real = this->real - a.real;
  c.imaginary = this->imaginary - a.imaginary;
  return c;
}
void Test_Complex()
{
  //Testing the parameterized and add and sub functions
  Complex a(3,4);
  Complex b(5,7);
  Complex c;
  c = c.add(a,b);
  c.print();
  c = c.sub(a,b);
  c.print();
  //Testing default constrructor and setters and getters
  Complex d;
  d.setReal(8);
  d.setImaginary(10);
  cout<<d.getReal()<<endl;
  cout<<d.getImaginary()<<endl;
  //Testing the overloaded + operator
  d = a + b;
  d.print();
  //Testing the overloaded - operator
  d = a - b;
  d.print();
}
int main()
{
  Test_Complex();
  return 0;
}
