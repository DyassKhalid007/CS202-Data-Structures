//binary search using pointer arithmetic
#include <iostream>
using namespace std;

int binary_search(int array[],int low,int high,int element)
{
  if(high>=low)
  {
    int mid = (low+high)/2;
    if(*(array+mid)==element)
    {
      return 1;
    }
    if(*(array+mid)>element)
    {
      return binary_search(array,low,mid-1,element);
    }
    return binary_search(array,mid+1,high,element);
  }
  return -1;
}
int main()
{
  int array[] = {1,5,9,10,12};
  int high = sizeof(array)/sizeof(array[0]);
  int element = 11;
  int low = 0;
  int result = binary_search(array,low,high-1,element);
  cout<<"The result of binary search is:"<<result<<endl;
}
