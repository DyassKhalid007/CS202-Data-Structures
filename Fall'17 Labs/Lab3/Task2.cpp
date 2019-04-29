//Program to print date and two date using a structure
#include <iostream>
using namespace std;
struct Date
{
  int Month;
  int Day;
  int Year;
};
void print(const Date &D)
{
  //function to print date in a specific format
  cout<<D.Day<<":"<<D.Month<<":"<<D.Year<<endl;
}
void setDate(Date&d)
{
  //Function to set date in specified manner
  do
  {
    cout<<"Please enter the day:";
    cin>>d.Day;
  }while(d.Day<=0||d.Day>30);
  do
  {
    cout<<"Please enter the month:";
    cin>>d.Month;
  }while(d.Month<=0||d.Month>12);
  cout<<"Please enter the year:";
  cin>>d.Year;
}
Date add(Date d1,Date d2)
{
  //function to add two dates
  //no need to worry about format due to setDate Function
  Date d3;
  d3.Day = d1.Day + d2.Day;
  d3.Month = d1.Month + d2.Month;
  d3.Year = d1.Year + d2.Year;
  return d3;
}
Date subtract(Date d1,Date d2)
{
  //function to subtract two dates
  Date d3;
  d3.Day = d1.Day - d2.Day;
  d3.Month = d1.Month - d2.Month;
  d3.Year = d1.Year - d2.Year;
  return d3;
}
int main()
{
  Date d1;
  setDate(d1);
  print(d1);
  Date d2 = d1;
  Date d3 = add(d1,d2);
  print(d3);
  d3 = subtract(d1,d2);
  print(d3);
}
