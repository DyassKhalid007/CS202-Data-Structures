#include <iostream>
using namespace std;

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
  void setYear(int y)
  void setDate(int d,int m,int y);
  int getDay();
  int getMonth();
  int getYear();
  ~Date();
};
Date::Date()
{
  day=0;
  month=0;
  year=0;
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
void Date::setDate(int d,int m,int y)
{
  day = d;
  month = m;
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
Date::~Date()
{
  cout<<"Date destructor called"<<endl;
}
class Appointment
{
private:
  string description;
  int timee;
  Date d;
public:
  Appointment();
  Appointment(string d,int t,int d1,int m1,int y1);
  void setDescription(string d);
  void setTime(int t);
  void setDate(int d,int m,int y);
  string getDescription();
  int getTime();
  int getDay();
  int getMonth();
  int getYear();
  virtual void occurs_on(int d,int m,int y);
  ~Appointment();
};
Appointment::Appointment()
{
  description = "NONE";
  timee = 0;
  d.setDate(0,0,0);
}
Appointment::Appointment(string d,int t,int d1,int m1,int y1)
{
  description = d;
  timee = t;
  d.setDate(d1,m1,y1);
}
void Appointment::setDescription(string d)
{
  description = d;
}
void Appointment::setTime(int t)
{
  timee = t;
}
void Appointment::setDate(int d,int m,int y)
{
  d.setDate(d,m,y)
}
string Appointment::getDescription()
{
  return description;
}
int Appointment::getTime()
{
  return timee;
}
int Appointment::getDay()
{
  return d.getDay();
}
int Appointment::getMonth()
{
  return d.getMonth();
}
int Appointment::getYear()
{
  return d.getYear();
}
void Appointment::occurs_on(int d,int m,int y)
{

}
Appointment::~Appointment()
{
  cout<<"Appointment destructor called"<<endl;
}
class Onetime:public Appointment
{
public:
  Onetime();
  Onetime(string d,int d1,int m,int y);
  void occurs_on(int d,int m,int y);

}
Onetime::Onetime()
{

}
Onetime::Onetime(string d,int t,int d1,int m,int y):Appointment(d,t,d1,m,y)
{

}
void Onetime::occurs_on(int d,int m,int y)
{
  if(d.getDay()==d&&d.getMonth()==m&&d.getYear()==y)
  {
    cout<<"Onetime Appointment occurs"<<endl;
  }
  else
  {
    cout<<"Onetime Appointment does not occur"<<endl;
  }
}
class Daily:public Appointment
{
public:
  Daily();
  Daily(string d,int t,int d1,int m,int y);
  void occurs_on(int d,int m,int y);
}
Daily::Daily()
{

}
Daily::Daily(string d,int t,int d1,int m,int y):Appointment(d,t,d1,m,y)
{

}
void Daily::occurs_on(int d,int m,int y)
{
  cout<<"Daily Appointment occur always"<<endl;
}
class Weekly:public Appointment
{
public:
  Weekly();
  Weekly(string d,int t,int d1,int m,int y);
  void occurs_on(int d,int m,int y);
}
Weekly::Weekly()
{

}
Weekly::Weekly(string d,int t,int d1,int m,int y):Appointment(d,t,d1,m,y)
{

}
void Weekly::occurs_on(int d,int m,int y)
{
  if(getMonth()==m&&getDay()==d)
  {
    cout<<"Weekly Appointment occurs"<<endl;
  }
  else
  {
    cout<<"Weekly Appointment does not occur"<<endl;
  }
}
class Monthly:public Appointment
{
public:
  Monthly();
  Monthly(string d,int t,int d1,int m,int y);
  void occurs_on(int d,int m,int y);
}
Monthly::Monthly()
{

}
Monthly::Monthly(string d,int t,int d1,int m,int y):Appointment(d,t,d1,m,y)
{

}
void Monthly::occurs_on(int d,int m,int y)
{
  if(getMonth()==m)
  {
    cout<<"Monthly Appointment occurs"<<endl;
  }
  else
  {
    cout<<"Monthly Appointment does not occur"<<endl;
  }
}
int main()
{
  //I don't understand what is role of onetime,daily,weekly and monthly
  return 0;
}
