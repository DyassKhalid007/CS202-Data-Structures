//function to reverse an array using pointer arithmetic only
//array size is last two digits of roll number:20100004
//only using 4 since 04 will mean octal
//Method is quite different from what I have been using
#include <iostream>
using namespace std;

typedef int data;
void reverseArray(data array[],int size);

int main()
{
  int size = 4;
  data array[size];
  for(int i=0;i<size;i++)
  {
    array[i] = i;
    cout<<array[i]<<endl;
  }
  reverseArray(array,size);
  cout<<"The array after reversal is:";
  for(int i=0;i<size;i++)
  {
    cout<<array[i]<<endl;
  }
}
void reverseArray(data array[],int size)
{
  size--;
  for(int i=0;size>=i;size--,i++)
  {
    data temp = array[i];
    array[i] = array[size];
    array[size] = temp;
  }
}
