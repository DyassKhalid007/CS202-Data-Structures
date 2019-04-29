//program: GPA Calculator
#include <iostream>
using namespace std;

struct semester
{
  int credits;
  int gradePoints;
};
class Student
{
private:
  string name;
  string major;
  semester s[8];
public:
  Student();
  Student(string n,string m);
  void calCGPA();
};
Student::Student()
{
  name = "NONE";
  major = "NONE";
}
Student::Student(string n,string m)
{
  name = n;
  major = m;
}
void Student::calCGPA()
{
  double cgpa = 0;
  double credits = 0;
  double gradePoints = 0;
  for(int i=0;i<8;i++)
  {
    //due to use of int in semester struct some precision is lost
    cout<<"Please enter your credit:";
    cin>>s[i].credits;
    credits+=s[i].credits;
    cout<<"Please enter your grade points:";
    cin>>s[i].gradePoints;
    gradePoints+=s[i].gradePoints;
  }
  cgpa = gradePoints/credits;
  cout<<"Your CGPA is:"<<cgpa<<endl;
}
int main()
{
  Student s;
  s.calCGPA();
}
