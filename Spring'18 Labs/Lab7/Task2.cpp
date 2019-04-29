//program to find prime numbers through SOE
#include <iostream>
#include <cmath>
using namespace std;

void SOE(int numbers)
{
  bool array[numbers];
  for(int i=0;i<numbers;i++)
  {
    array[i] = true;
  }
  array[0] = false;
  array[1] = false;

  for(int i=2;i<numbers;i++)
  {
    if(array[i])
    {
      for(int j=i*i,k=0;j<numbers;j=i*i+k*i)
      {
        //cout<<"Doing false:"<<j<<endl;
        array[j] = false;
        k++;
      }

    }
  }
  cout<<"Prime numbers are:"<<endl;
  for(int i=0;i<numbers;i++)
  {
    if(array[i])
    {
      cout<<i<<endl;
    }
  }
}

int main()
{
  cout<<"Please enter the number up to which to find prime numbers:";
  int numbers;
  cin>>numbers;
  SOE(numbers+1);
  return 0;
}
