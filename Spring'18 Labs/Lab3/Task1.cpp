//program to swap value using pointers for ints
//oveloaded function for doubles and long also
#include <iostream>
using namespace std;

void swap(int*a,int*b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void swap(double*a,double*b)
{
  double temp = *a;
  *a = *b;
  *b = temp;
}
void swap(long*a,long*b)
{
  long temp = *a;
  *a = *b;
  *b = temp;
}
void Test_Int()
{
  //testing int swapping
  int a = 5;
  int b =8;
  swap(a,b);
  cout<<"The value of a is:"<<a<<endl;
  cout<<"The value of b is:"<<b<<endl;
}
void Test_double()
{
  double a = 5.4;
  double b =8.2;
  swap(a,b);
  cout<<"The value of a is:"<<a<<endl;
  cout<<"The value of b is:"<<b<<endl;
}
void Test_long()
{
  long a = 56789;
  long b = 12345;
  swap(a,b);
  cout<<"The value of a is:"<<a<<endl;
  cout<<"The value of b is:"<<b<<endl;
}
int main()
{
  Test_Int();
  Test_double();
  Test_long();
}
