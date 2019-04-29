#include <iostream>
using namespace std;

string code(char a)
{
  string alphabets="abcdefghijklmnopqrstuvwxyz";
  int size = 26;
  string array[size] = {"2","3","5","7","11","13","17","19","23","29","31","37","41","43","47"
                      ,"53","59","61","67","71","73","79","83","89","97","101"};
  for(int i=0;i<alphabets.length();i++)
  {
    if(a==alphabets[i])
    {
      return array[i];
    }
  }
}
int code_divided(string array[],int length)
{
  
}

void Test_Code()
{
  string word = "abcdefghh";
  string coded[word.length()];
  for(int i=0;i<word.length();i++)
  {
    coded[i]=code(word[i]);
  }
  for(int i=0;i<word.length();i++)
  {
    cout<<coded[i]<<endl;
  }
}

int main()
{
  Test_Code();
  return 0;
}
