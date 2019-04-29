#include <iostream>
using namespace std;

bool is_fibonacci(int number);
int main()
{
  //prompt the user for the number
    cout<<"Please enter your fibonacci number:";
    int number;
    cin>>number;
    //Now inputting the number into a boolean function
    bool result = is_fibonacci(number);
    if(result)
    {
      cout<<"Yes"<<endl;
    }
    else
    {
      cout<<"No"<<endl;
    }

}
bool is_fibonacci(int number)
{
  //checks if a number is part of fib sequence or not
  int first = 0;
  int second = 1;
  int fib = 0;
  while(number>fib)
  {
    fib = first+second;
    first = second;
    second = fib;
  }
  if(number == fib)
  {
    return true;
  }
  return false;

}
