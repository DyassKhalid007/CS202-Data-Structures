//program to find largest,smalles and sum of elements of array using pointer arithmetic
#include <iostream>
using namespace std;

typedef int data;

data largest(data array[],int size);
data smallest(data array[],int size);
data sum(data array[],int size);

int main()
{
  cout<<"Pleasee enter the size of the array:";
  int size;
  cin>>size;
  data array[size];
  for(int i=0;i<size;i++)
  {
    cout<<"Please enter the element at index["<<i<<"]:";
    cin>>*(array+i);
  }
  data max = largest(array,size);
  cout<<"The largest element in array is:"<<max<<endl;
  data min = smallest(array,size);
  cout<<"The smallest element in the array is:"<<min<<endl;
  data add = sum(array,size);
  cout<<"The sum of elements in the array is:"<<add<<endl;
}
data largest(data array[],int size)
{
  data max = *(array);
  for(int i=0;i<size;i++)
  {
    if(max<*(array+i))
    {
      max = *(array+i);
    }
  }
  return max;
}
data smallest(data array[],int size)
{
  data min = *(array);
  for(int i=0;i<size;i++)
  {
    if(min>*(array+i))
    {
      min = *(array+i);
    }
  }
  return min;
}
data sum(data array[],int size)
{
  data sum = 0;
  for(int i=0;i<size;i++)
  {
    sum+=*(array+i);
  }
  return sum;
}
