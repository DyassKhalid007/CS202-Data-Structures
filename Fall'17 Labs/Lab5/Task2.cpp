//program to reverse the array through function using pointer arithmetic
#include <iostream>
using namespace std;

void reverse(int array[],int size);
int main()
{
  cout<<"Please enter the size of the array:";
  int size;
  cin>>size;
  int*array = new int[size];
  for(int i=0;i<size;i++)
  {
    cout<<"Please enter the element at index ["<<i<<"]:";
    cin>>*(array+i);
  }
  reverse(array,size);
  cout<<"The array after reversal is:";
  for(int i=0;i<size;i++)
  {
    cout<<*(array+i)<<endl;
  }
  //freeing the memory allocated
  delete []array;
}
void reverse(int array[],int size)
{
  int array2[size];
  // cout<<array[0]<<endl;
  for(int i=0,j=size-1;i<size;i++,j--)
  {
    *(array2+j) = *(array+i);
  }
  for(int i=0;i<size;i++)
  {
    *(array+i) = *(array2+i);
  }
}
