//string and some functions implemented using char arrays
#include <iostream>
using namespace std;

class my_string
{
private:
  char *p;
  int size;
public:
  my_string();
  my_string(char array[],int size);
  bool substr(char array[],int s);
  int length();
  char get(int word);
  int compare(char array[],int s);
  void print();
  ~my_string();
};
my_string::my_string()
{
  size = 10;
  p = new char[size+1];
  cout<<"Please enter char in array:";
  for(int i=0;i<size;i++)
  {
    cin>>p[i];
  }
  p[size] = '\0';

}
my_string::my_string(char array[],int s)
{
  size = s;
  p = new char[size+1];
  for(int i=0;i<size;i++)
  {
    p[i] = array[i];
  }
  p[size] = '\0';
}
bool my_string::substr(char array[],int s)
{
  //checks if the passed string is substr of class's string
  if(s>size)
  {
    return false;
  }
  for(int i=0;i<size;i++)
  {
    int l=0;
    for(int j=0,k=i;j<s;j++,k++)
    {
      //cout<<"I entered the second loop"<<endl;
      if(p[k]!=array[j])
      {
        //cout<<"I entered first conditional"<<endl;
        l=0;
        break;
      }
      else
      {
        //cout<<"I entered second conditional"<<endl;
        l++;
      }
      if(l==s)
      {
        return true;
      }
    }
    //cout<<"iteration completed"<<endl;

  }
  return false;
}
int my_string::length()
{
  return size;
}
char my_string::get(int word)
{
  char j ='0';
  for(int i=0;i<word;i++)
  {
    j = j+1;
  }
  return j;
}
int my_string::compare(char array[],int s)
{
  if(size>s)
  {
    return 1;
  }
  else if(size<s)
  {
    return -1;
  }
  else
  {
    for(int i=0;i<size;i++)
    {
      if(p[i]>array[i])
      {
        return 1;
      }
      else if(p[i]<array[i])
      {
        return -1;
      }
    }
    return 0;
  }
}
void my_string::print()
{
  for(int i=0;i<size;i++)
  {
    cout<<p[i];
  }
}
my_string::~my_string()
{
  delete[]p;
}

int main()
{
  cout<<"Please enter ths size of char array:";
  int size;
  cin>>size;
  char array[size+1];
  for(int i=0;i<size;i++)
  {
    cin>>array[i];
  }
  array[size]='\0';

   my_string s(array,size);
   char array2[3]={'p','p','l'};
   cout<<s.compare(array2,3)<<endl;
   cout<<s.substr(array2,3)<<endl;
   cout<<"Length of my_string s is:"<<s.length()<<endl;
   cout<<"Character of 6 is:"<<s.get(6)<<endl;


  return 0;
}
