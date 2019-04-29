#include <iostream>
#include <string>
using namespace std;
bool is_substring(string first,string second);
int main()
{
  cout<<"Please enter the main string:";
  string first;
  cin>>first;
  cout<<"Please enter the string to find in main string:";
  string second;
  cin>>second;
  bool result = is_substring(first,second);
  cout<<"The result is:"<<result<<endl;
}
bool is_substring(string first,string second)
{
  if(second.length()>first.length())
  {
    return 0;
  }
  if(second.length()==first.length())
  {
    for(int i=0;i<first.length();i++)
    {
      if(first[i]!=second[i])
      {
        return 0;
      }
    }
    return 1;
  }
  for(int i=0;i<first.length();i++)
  {
    int k = 0;
    for(int j=0,l=i;j<second.length();j++,l++)
    {

      if(first[l]!=second[j])
      {
        k=0;
        break;
      }
      else
      {
        //cout<<"I entered here"<<endl;
        k++;
      }
      if(k==second.length())
      {
        return 1;
      }
      //cout<<"l:"<<l<<endl;
      //cout<<"k:"<<k<<endl;
    }

  }
  return 0;
}
