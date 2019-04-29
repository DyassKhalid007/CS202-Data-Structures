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
  while(true)
  {
    cout<<"Press q to quit or any other key to continue:";
    char operation;
    cin>>operation;
    if(operation == 'q')
    {
      break;
    }
    int size = 5;
    Complex C[size];
    for(int i =0;i<size;i++)
    {
      cout<<"Please enter the real part of complex number:";
      int real;
      cin>>real;
      cout<<"Please enter the imaginary part of complex number:";
      int imaginary;
      cin>>imaginary;
      C[i].setReal(real);
      C[i].setImaginary(imaginary);
    }
    Complex Sum;
    for(int i=0;i<size;i++)
    {
      Sum=Sum + C[i];
    }
    Sum.print();


  }
}
int main()
{
  Test_Complex();
  return 0;
}
