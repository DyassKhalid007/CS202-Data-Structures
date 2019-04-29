#include <iostream>
using namespace std;

bool compare(int array[],int reverse_array[],int length);

int main()
{
  //prompting the user for a number
  cout<<"Please enter your number:";
  int number;
  cin>>number;
  //Now calculating the length of the number for array initialization
  int copyN = number;
  int length = 0;
  while (true)
  {
    copyN = copyN/10;
    length++;
    if(!copyN)
    {
      break;
    }
  }
  //length is calculated till Now
  //Now initializing the integer array of length length

  int array[length];
  copyN = number;
  for(int i=0;i<length;i++)
  {
    array[i] = copyN%10;
    copyN = copyN/10;
  }
  //Now the array has the reverse number
  //Now creating another array by reversing the array already created
  int reverse_array[length];
  int j = 0;
  for(int i = length-1;i>=0;i--)
  {
    reverse_array[j] = array[i];
    j++;
  }
  //Now the array have the reverse of the reverse number meaning the orignal number
  //Now comparing the number using boolean functions
  bool result = compare(array,reverse_array,length);
  if(result)
  {
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }
  return 0;

}
bool compare(int array[],int reverse_array[],int length)
{
  for(int i=0;i<length;i++)
  {
    if(array[i]!=reverse_array[i])
    {
      return false;
    }
  }
  return true;
}
