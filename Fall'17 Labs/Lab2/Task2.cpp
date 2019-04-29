//program to calculate the average of 10 elements of array
#include <iostream>
using namespace std;
double average(long long int array[],int size);
int main()
{
  int size = 10;
  long long int array[size];
  for(int i=0;i<size;i++)
  {
    cout<<"Please enter the element at index["<<i<<"]:";
    cin>>array[i];
  }
  double result = average(array,size);
  cout<<"The result is:"<<result<<endl;
  return 0;
}
double average(long long int array[],int size)
{
  double avg = 0;
  for(int i=0;i<size;i++)
  {
    avg+=array[i];
  }
  avg=avg/(double)size;
  return avg;
}
