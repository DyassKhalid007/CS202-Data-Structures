//program to calculate number of digits recursively
#include <iostream>
using namespace std;
int digits(int n);
void Test()
{
  cout<<"Please enter a number:";
  int number;
  cin>>number;

  cout<<"The number of digits are:"<<digits(number);
}
int main()
{
  Test();
  return 0;
}
int digits(int n)
{
  if(n<10)
  {
    return 1;
  }
  else
  {
    return (1+digits(n/10));
  }
}
