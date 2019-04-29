#include <iostream>
using namespace std;

void reverse_order(int array[],int size);
void display(int array[],int size);
int main()
{
  cout<<"Please enter the size of the array:";
  int size;
  cin>>size;
  int array[size];
  for(int i=0;i<size;i++)
  {
    cout<<"Please enter the array at index["<<i<<"]:";
    cin>>array[i];
  }
  reverse_order(array,size);
  display(array,size);
}
void reverse_order(int array[],int size)
{
  int copy[size];
  if(size%2==0)
  {
    int j=size;
    for(int i=0;i<size;i++,j--)
    {
      //cout<<"i:"<<i<<endl;
      if(i%2!=0)
      {
        copy[i] = array[j];
      }
    }
    for(int i=0;i<size;i++)
    {
      if(i%2!=0)
      {
        array[i] = copy[i];
      }
    }
  }
  else
  {
    int j = size-1;
    for(int i=0;i<size;i++,j--)
    {
      if(i%2!=0)
      {
        copy[i] = array[j];
      }
    }
    for(int i=0;i<size;i++)
    {
      if(i%2!=0)
      {
        array[i] = copy[i];
      }
    }
  }

}
void display(int array[],int size)
{
  for(int i=0;i<size;i++)
  {
    cout<<array[i]<<endl;
  }
}
