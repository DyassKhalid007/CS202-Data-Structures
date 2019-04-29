//program to find the second max element from array
#include <iostream>
using namespace std;

int secondMax(int array[], int size);
int main()
{
  //promp the user for the size of the array
  cout<<"Please enter the size of the array:";
  int size;
  cin>>size;
  //initializing the array and  getting elements from the user
  int array[size];
  for(int i=0;i<size;i++)
  {
    cout<<"Please enter the element at index["<<i<<"]:";
    cin>>array[i];
  }
  int result = secondMax(array,size);
  cout<<"The second max element is:"<<result<<endl;

}
int secondMax(int array[],int size)
{
  //finding the max element first and then finding the second max element
  int max = 0;
  max = array[0];
  for(int i=0;i<size;i++)
  {
    if(array[i]>max)
    {
      max = array[i];
    }
  }
  //now searching the next largest element that is not max by using the if conditional
  int second_max = array[0];
  for(int i=0;i<size;i++)
  {
    if(array[i]>second_max&&array[i]!=max)
    {
      second_max = array[i];
    }
  }
  return second_max;
}
