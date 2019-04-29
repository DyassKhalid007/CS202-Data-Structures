#include <iostream>
using namespace std;

class Person
{
private:
  string name;
  string gender;
  int age;
public:
  Person();
  Person(string n,string g,int a);
  void setName(string n);
  void setGender(string g);
  void setAge(int a);
  string getName();
  string getGender();
  int getAge();
};
Person::Person()
{
  name = "NONE";
  gender = "NONE";
  age = 0;
}
Person::Person(string n,string g,int a)
{
  name = n;
  gender = g;
  age = a;
}
void Person::setName(string n)
{
  name = n;
}
void Person::setGender(string g)
{
  gender = g;
}
void Person::setAge(int a)
{
  age = a;
}
string Person::getName()
{
  return name;
}
string Person::getGender()
{
  return gender;
}
int Person::getAge()
{
  return age;
}
class Date
{
private:
  int day;
  int month;
  int year;
public:
  Date();
  Date(int d,int m,int y);
  void setDay(int d);
  void setMonth(int m);
  void setYear(int y);
  int getDay();
  int getMonth();
  int getYear();
};
Date::Date()
{
  day = 0;
  month = 0;
  year = 0;
}
Date::Date(int d,int m,int y)
{
  day = d;
  month = m;
  year = y;
}
void Date::setDay(int d)
{
  day = d;
}
void Date::setMonth(int m)
{
  month = m;
}
void Date::setYear(int y)
{
  year = y;
}
int Date::getDay()
{
  return day;
}
int Date::getMonth()
{
  return month;
}
int Date::getYear()
{
  return year;
}
class Student:public Person
{
private:
  Date admission;
  double cgpa;
  string level;
public:
  Student();
  Student(string n,string g,int a,int d,int m,int y,double Cgpa,string l);
  void setCgpa(double Cgpa);
  void setLevel(string l);
  void setDate(int d,int m,int y);
  double getCgpa();
  string getLevel();
  int getDay();
  int getMonth();
  int getYear();

};
Student::Student()
{
  admission.setDay(0);
  admission.setMonth(0);
  admission.setYear(0);
  cgpa = 0.0;
  level = "NONE";
}
Student::Student(string n,string g,int a,int d,int m,
  int y,double Cgpa,string l):Person(n,g,a)
  {
    admission.setDay(d);
    admission.setMonth(m);
    admission.setYear(y);
    cgpa = Cgpa;
    level = l;
  }
void Student::setCgpa(double Cgpa)
{
  cgpa = Cgpa;
}
void Student::setLevel(string l)
{
  level = l;
}
void Student::setDate(int d,int m,int y)
{
  admission.setDay(d);
  admission.setMonth(m);
  admission.setYear(y);
}
double Student::getCgpa()
{
  return cgpa;
}
string Student::getLevel()
{
  return level;
}
int Student::getDay()
{
  return admission.getDay();
}
int Student::getMonth()
{
  return admission.getMonth();
}
int Student::getYear()
{
  return admission.getYear();
}
class Employee:public Person
{
private:
  Date joining;
  string department;
  double salary;
public:
  Employee();
  Employee(string n,string g,int a,int d,int m,int y,string dept,double sal);
  void setDept(string d);
  void setSalary(double sal);
  void setDay(int d);
  void setMonth(int m);
  void setYear(int y);
  string getDept();
  double getSalary();
  int getDay();
  int getMonth();
  int getYear();
};
Employee::Employee()
{
  department = "NONE";
  salary = 0;
  joining.setDay(0);
  joining.setMonth(0);
  joining.setYear(0);
}
Employee::Employee(string n,string g,int a,int d,int m,
  int y,string dept,double sal):Person(n,g,a)
{
  joining.setDay(d);
  joining.setMonth(m);
  joining.setYear(y);
  department = dept;
  salary = sal;
}
void Employee::setDept(string d)
{
  department = d;
}
void Employee::setSalary(double sal)
{
  salary = sal;
}
void Employee::setDay(int d)
{
  joining.setDay(d);
}
void Employee::setMonth(int m)
{
  joining.setMonth(m);
}
void Employee::setYear(int y)
{
  joining.setYear(y);
}
string Employee::getDept()
{
  return department;
}
double Employee::getSalary()
{
  return salary;
}
int Employee::getDay()
{
  return joining.getDay();
}
int Employee::getMonth()
{
  return joining.getMonth();
}
int Employee::getYear()
{
  return joining.getYear();
}
class Doctor:public Employee
{
private:
  string specialty;
public:
  Doctor();
  Doctor(string n,string g,int a,int d,int m,int y,string dept,double sal,string spec);
  void setSpecialty(string spec);
  string getSpecialty();
};
Doctor::Doctor()
{
  specialty = "NONE";
}
Doctor::Doctor(string n,string g,int a,int d,
  int m,int y,string dept,double sal,string spec):Employee(n,g,a,d,m,y,dept,sal)
  {
    specialty = spec;
  }
void Doctor::setSpecialty(string spec)
{
  specialty = spec;
}
string Doctor::getSpecialty()
{
  return specialty;
}
class Patient:public Person
{
private:
  int pid;
  Date admission;
  Date discharge;
  string ward;
  int bedNumber;
  int billedAmmount;
  Doctor D;
public:
  Patient();
  Patient(string n,string g,int a,int pd,int d,int m,int y,int d1,
  int m1,int y1,string w,int bnumber,int bammount,Doctor doc);
  void setPatientId(int p);
  void setDAdmission(int d,int m,int y);
  void setDDischarge(int d,int m,int y);
  void setWard(string w);
  void setbedNumber(int b);
  void setbilledAmmount(int b);
  void setDoctor(Doctor doc);
  void print();
};
Patient::Patient()
{
  pid = 0;
  admission.setDay(0);
  admission.setMonth(0);
  admission.setYear(0);
  discharge.setDay(0);
  discharge.setMonth(0);
  discharge.setYear(0);
  ward = "NONE";
  bedNumber = 0;
  billedAmmount = 0;
}
Patient::Patient(string n,string g,int a,int pd,int d,int m,int y,int d1,
int m1,int y1,string w,int bnumber,int bammount,Doctor doc):Person(n,g,a)
{
  pid = pd;
  admission.setDay(d);
  admission.setMonth(m);
  admission.setYear(y);
  discharge.setDay(d1);
  discharge.setMonth(m1);
  discharge.setYear(y1);
  ward = w;
  bedNumber = bnumber;
  billedAmmount = bammount;
  D = doc;
}
void Patient::setPatientId(int p)
{
  pid = p;
}
void Patient::setDAdmission(int d,int m,int y)
{
  admission.setDay(d);
  admission.setMonth(m);
  admission.setYear(y);
}
void Patient::setDDischarge(int d,int m,int y)
{
  discharge.setDay(d);
  discharge.setMonth(m);
  discharge.setYear(y);
}
void Patient::setWard(string w)
{
  ward = w;
}
void Patient::setbedNumber(int b)
{
  bedNumber = b;
}
void Patient::setbilledAmmount(int b)
{
  billedAmmount = b;
}
void Patient::setDoctor(Doctor doc)
{
  D = doc;
}
void Patient::print()
{
  cout<<"Name"<<getName()<<endl;
  cout<<"Gender"<<getGender()<<endl;
  cout<<"Age:"<<getAge()<<endl;
  cout<<"Patient-ID:"<<pid<<endl;
  cout<<"Date of admission:"<<admission.getDay()<<":"<<admission.getMonth()<<":"<<admission.getYear()<<endl;
  cout<<"Date of discharge:"<<discharge.getDay()<<":"<<discharge.getMonth()<<":"<<discharge.getYear()<<endl;
  cout<<"Ward:"<<ward<<endl;
  cout<<"Bed Number:"<<bedNumber<<endl;
  cout<<"Billed Ammount:"<<billedAmmount<<endl;
  cout<<"Doctor Name:"<<D.getName()<<endl;
}
void TestPerson()
{
  Person D;
  D.setName("Dyass");
  D.setGender("M");
  D.setAge(19);
  cout<<"Name:"<<D.getName()<<endl;
  cout<<"Gender:"<<D.getGender()<<endl;
  cout<<"Age:"<<D.getAge()<<endl;
  //Testing parameterized constructor now
  cout<<"Testing parameterized constructor now"<<endl;
  Person U("Usama Z Mahi","M",20);
  cout<<"Name:"<<U.getName()<<endl;
  cout<<"Gender:"<<U.getGender()<<endl;
  cout<<"Age:"<<U.getAge()<<endl;
}
void TestDate()
{
  Date d;
  d.setDay(13);
  d.setMonth(3);
  d.setYear(1999);
  cout<<"Day:"<<d.getDay()<<endl;
  cout<<"Month:"<<d.getMonth()<<endl;
  cout<<"Year:"<<d.getYear()<<endl;
  cout<<"Testing parameterized constructor now"<<endl;
  Date d2(19,9,2012);
  cout<<"Day:"<<d2.getDay()<<endl;
  cout<<"Month:"<<d2.getMonth()<<endl;
  cout<<"Year:"<<d2.getYear()<<endl;
}
void TestStudentDefault()
{
  Student D;
  D.setName("Dyass");
  D.setGender("M");
  D.setAge(19);
  D.setCgpa(3.2);
  D.setLevel("UG");
  D.setDate(13,3,1999);
  cout<<"Name:"<<D.getName()<<endl;
  cout<<"Gender:"<<D.getGender()<<endl;
  cout<<"Age:"<<D.getAge()<<endl;
  cout<<"CGPA:"<<D.getCgpa()<<endl;
  cout<<"Level:"<<D.getLevel()<<endl;
  cout<<"DD:MM:YYYY:"<<D.getDay()<<":"<<D.getMonth()<<":"<<D.getYear()<<endl;
}
void TestStudentP()
{
  Student D("Dyass k","M",19,13,3,1999,3.2,"G");
  cout<<"Name:"<<D.getName()<<endl;
  cout<<"Gender:"<<D.getGender()<<endl;
  cout<<"Age:"<<D.getAge()<<endl;
  cout<<"CGPA:"<<D.getCgpa()<<endl;
  cout<<"Level:"<<D.getLevel()<<endl;
  cout<<"DD:MM:YYYY:"<<D.getDay()<<":"<<D.getMonth()<<":"<<D.getYear()<<endl;
}
void TestEmployee()
{
  Employee D;
  D.setName("Dyass");
  D.setGender("M");
  D.setAge(19);
  D.setSalary(80000);
  D.setDept("BioChemistry");
  D.setDay(13);
  D.setMonth(3);
  D.setYear(1999);
  cout<<"Name:"<<D.getName()<<endl;
  cout<<"Gender:"<<D.getGender()<<endl;
  cout<<"Age:"<<D.getAge()<<endl;
  cout<<"DD:MM:YYYY:"<<D.getDay()<<":"<<D.getMonth()<<":"<<D.getYear()<<endl;
  cout<<"Salary:"<<D.getSalary()<<endl;
  cout<<"Department:"<<D.getDept()<<endl;

  //Testing parameterized constructor now
  cout<<"Testing parameterized constructor now"<<endl;
  Employee U("Usama Z","M",20,9,9,2017,"Genetics",110000.0);
  cout<<"Name:"<<U.getName()<<endl;
  cout<<"Gender:"<<U.getGender()<<endl;
  cout<<"Age:"<<U.getAge()<<endl;
  cout<<"DD:MM:YYYY:"<<U.getDay()<<":"<<U.getMonth()<<":"<<U.getYear()<<endl;
  cout<<"Salary:"<<U.getSalary()<<endl;
  cout<<"Department:"<<U.getDept()<<endl;

}
void TestDoctor()
{
  Doctor D;
  D.setName("Dyass");
  D.setGender("M");
  D.setAge(19);
  D.setSalary(80000);
  D.setDept("BioChemistry");
  D.setDay(13);
  D.setMonth(3);
  D.setYear(1999);
  D.setSpecialty("Computational Biology");
  cout<<"Name:"<<D.getName()<<endl;
  cout<<"Gender:"<<D.getGender()<<endl;
  cout<<"Age:"<<D.getAge()<<endl;
  cout<<"DD:MM:YYYY:"<<D.getDay()<<":"<<D.getMonth()<<":"<<D.getYear()<<endl;
  cout<<"Salary:"<<D.getSalary()<<endl;
  cout<<"Department:"<<D.getDept()<<endl;
  cout<<"Specialty:"<<D.getSpecialty()<<endl;

  //Testing parameterized constructor now
  cout<<"Testing parameterized constructor now"<<endl;
  Doctor U("Usama Z","M",20,9,9,2017,"Genetics",110000.0,"Physical Chemistry");
  cout<<"Name:"<<U.getName()<<endl;
  cout<<"Gender:"<<U.getGender()<<endl;
  cout<<"Age:"<<U.getAge()<<endl;
  cout<<"DD:MM:YYYY:"<<U.getDay()<<":"<<U.getMonth()<<":"<<U.getYear()<<endl;
  cout<<"Salary:"<<U.getSalary()<<endl;
  cout<<"Department:"<<U.getDept()<<endl;
  cout<<"Specialty:"<<U.getSpecialty()<<endl;
}
void TestPatient()
{
  Patient P;
  P.setName("Abdullah");
  P.setGender("M");
  P.setAge(18);
  P.setPatientId(12);
  P.setDAdmission(1,1,1999);
  P.setDDischarge(9,9,2008);
  P.setbilledAmmount(10000);
  P.setbedNumber(10);
  P.setWard("Medical");
  //Assigning a doctor
  Doctor D;
  D.setName("Dyass");
  D.setGender("M");
  D.setAge(19);
  D.setSalary(80000);
  D.setDept("BioChemistry");
  D.setDay(13);
  D.setMonth(3);
  D.setYear(1999);
  D.setSpecialty("Computational Biology");
  P.setDoctor(D);
  //Now printing
  P.print();
}
void admitGraduates()
{
  Student D("Dyass k","M",19,13,3,1999,3.2,"G");
  Student D2;
  D2.setName("Usama");
  D2.setGender("M");
  D2.setAge(19);
  D2.setCgpa(3.29);
  D2.setLevel("UG");
  D2.setDate(13,31,1999);
}
void HireDoctors()
{
  TestDoctor();//2 are hired
  Doctor U2("Farhan","M",20,9,9,2017,"Chemeo",110000.0,"Physical Chemistry");
}
void admitPatients()
{
  //Admit a patient and assign a Doctor
  TestPatient();
  //Bill is billed ammount and if billedamoount == paid patient is discharged
  //Do it yourself.
}

int main()
{
  // TestPerson();
  // TestDate();
  // TestStudentDefault();
  // TestStudentP();
  // TestEmployee();
  // TestDoctor();
  // TestPatient();

  return 0;
}
