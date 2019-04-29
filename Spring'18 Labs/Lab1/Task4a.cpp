#include <iostream>
#include <string>
using namespace std;

class STUDENT
{
private:
  string name;

  string major;
public:
  int roll_number;
  STUDENT();
  STUDENT(string n,int r,string m);
  void setName(string n);
  void setRollnum(int r);
  void setMajor(string m);
  void print();
};
STUDENT::STUDENT()
{
  roll_number = 0;
}
STUDENT::STUDENT(string n,int r,string m)
{
  name = n;
  roll_number = r;
  major = m;
}
void STUDENT::setName(string n)
{
  name = n;
}
void STUDENT::setRollnum(int r)
{
  roll_number = r;
}
void STUDENT::setMajor(string m)
{
  major = m;
}
void STUDENT::print()
{
  cout<<"Name:"<<name<<endl;
  cout<<"Roll Number:"<<roll_number<<endl;
  cout<<"Major:"<<major<<endl;
}
void sort(STUDENT array[],int length)
{

}
int main()
{
  cout<<"Please press q to quit or any other key to continue:";
  char operation;
  cin>>operation;
  int length =3;
  while(operation!='q')
  {
    STUDENT S[length];
    for(int i =0;i<length;i++)
    {
      cout<<"Please enter name:";
      int roll;
      cin>>roll;
      S[i].setRollnum(roll);
    }
    //now sorting on the basis of roll number
    for(int i = 0;i<length;i++)
    {
      STUDENT max = S[i];
      int maxindex = i;
        for(int j=i;j<length;j++)
        {
          if(S[j].roll_number<max.roll_number)
          {
            max = S[j];
            maxindex = j;
          }
        }
        STUDENT temp = S[i];
        S[i] = max;
        S[maxindex] = temp;
    }
    for(int i=0;i<length;i++)
    {
      S[i].print();
    }
  }
}
