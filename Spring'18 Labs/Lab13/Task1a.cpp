//programm for linear search using recursion
#include <iostream>
using namespace std;
bool linearSearch(int array[],int s,int e);
void Test()
{
  cout<<"Please enter the size of array:";
  int size;
  cin>>size;
  int array[size];
  for(int i=0;i<size;i++)
  {
    cout<<"Please enter the element at index ["<<i<<"]:";
    cin>>array[i];
  }
  cout<<"Please enter the element to search:";
  int ele;
  cin>>ele;
  size--;
  cout<<"The element is:"<<linearSearch(array,size,ele);
}
bool linearSearch(int array[],int s,int e)
{

  if(s<0)
  {
    return false;
  }
  if(array[s]==e)
  {
    return true;
  }
  return linearSearch(array,--s,e);
}
int main()
{
  Test();
  return 0;
}
