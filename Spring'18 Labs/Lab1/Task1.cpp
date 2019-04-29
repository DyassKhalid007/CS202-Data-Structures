#include <iostream>
#include <string>
using namespace std;

class STUDENT
{
private:
  string name;
  int roll_number;
  string major;
public:
  STUDENT(string n,int r,string m);
  void setName(string n);
  void setRollnum(int r);
  void setMajor(string m);
  void print();
};
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
void Test_STUDENT()
{
  //setting a student and printing the contents
  STUDENT Dyass("Dyass Khalid",20100004,"Computer Science");
  Dyass.print();
  cout<<endl;
  //testing the setName function and printing the content again
  Dyass.setName("Dyass Asif");
  Dyass.print();
  cout<<endl;
  //testing the setMajor function and printing the content again
  Dyass.setMajor("Biology");
  Dyass.print();
  cout<<endl;
  //testing the setRollnum function and printing the content again
  Dyass.setRollnum(20100001);
  Dyass.print();
  cout<<endl;
}
int main()
{
  Test_STUDENT();
  return 0;
}
