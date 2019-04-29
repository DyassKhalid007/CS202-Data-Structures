#include <iostream>
using namespace std;

class Vehicle
{
private:
  string make;
  string model;
  string color;
  int year;
  double mileage;
public:
  Vehicle();
  Vehicle(string m,string m1,string c,int y,double m2);
  void setMake(string m);
  void setModel(string m);
  void setColor(string c);
  void setYear(int y);
  void setMileage(double m);
  string getMake();
  string getModel();
  string getColor();
  int getYear();
  double getMileage();
  virtual void details();
};
Vehicle::Vehicle()
{
  make = " ";
  model = " ";
  color = " ";
  year = 0;
  mileage = 0.0;
}
Vehicle::Vehicle(string m,string m1,string c,int y,double m2)
{
  make = m;
  model = m1;
  color = c;
  year = y;
  mileage = m2;
  if(mileage<0)
  {
    mileage = 0;
  }
}
void Vehicle::setMake(string m)
{
  make = m;
}
void Vehicle::setModel(string m)
{
  model = m;
}
void Vehicle::setColor(string c)
{
  color = c;
}
void Vehicle::setYear(int y)
{
  year = y;
}
void Vehicle::setMileage(double m)
{
  mileage = m;
  if(mileage<0)
  {
    mileage = 0;
  }
}
string Vehicle::getMake()
{
  return make;
}
string Vehicle::getModel()
{
  return model;
}
string Vehicle::getColor()
{
  return color;
}
int Vehicle::getYear()
{
  return year;
}
double Vehicle::getMileage()
{
  return mileage;
}
void Vehicle::details()
{
  //virtual function
}
class Car:public Vehicle
{
public:
  Car();
  Car(string m,string m1,string c,int y,double m2);
  void details();
};
Car::Car()
{

}
Car::Car(string m,
string m1,string c,int y,double m2):Vehicle(m,m1,c,y,m2)
{

}
void Car::details()
{
  cout<<"Make:"<<getMake()<<endl;
  cout<<"Model:"<<getModel()<<endl;
  cout<<"Color:"<<getColor()<<endl;
  cout<<"Year:"<<getYear()<<endl;
  cout<<"Mileage:"<<getMileage()<<endl;
}
class Truck:public Vehicle
{
private:
  int bedSize;
public:
  Truck();
  Truck(string m,string m1,string c,int y,double m2,int bsize);
  void setBedSize(int b);
  int getBedSize();
  void details();
};
Truck::Truck()
{
  bedSize = 0;
}
Truck::Truck(string m,
string m1,string c,int y,double m2,int bsize)
:Vehicle(m,m1,c,y,m2),bedSize(bsize)
{

}
void Truck::setBedSize(int b)
{
  bedSize = b;
}
int Truck::getBedSize()
{
  return bedSize;
}
void Truck::details()
{
  cout<<"Make:"<<getMake()<<endl;
  cout<<"Model:"<<getModel()<<endl;
  cout<<"Color:"<<getColor()<<endl;
  cout<<"Year:"<<getYear()<<endl;
  cout<<"Mileage:"<<getMileage()<<endl;
  cout<<"Bed Size:"<<getBedSize()<<endl;
}
void TestCar()
{
  Car C;
  C.setMake("Mercedes");
  C.setModel("PKR");
  C.setColor("Blue");
  C.setYear(2018);
  C.setMileage(12);
  C.details();
  cout<<"New object being created"<<endl;
  Car D("Dyass","DKR","Red",2020,1000);
  D.details();
}
void TestTruck()
{
  Truck C;
  C.setMake("Mercedes");
  C.setModel("PKR");
  C.setColor("Blue");
  C.setYear(2018);
  C.setMileage(12);
  C.setBedSize(1000);
  C.details();

  Truck D("Dyass","DKR","Red",2020,1000,2000);
  D.details();

}
void Test()
{
  Car C1("Porsche","911","Silver",2005,1);
  Car C2("Ford","Mustang","Red",2007,2);
  Truck T1("Ford","F150","White",2007,3,10);
  Car C3("Voltzwagon","Jetta","Black",2006,4);
  Truck T2("Toyota","Tacoma","Blue",2002,5,12);
  Vehicle*array[5];
  array[0] = &C1;
  array[1] = &C2;
  array[2] = &T1;
  array[3] = &C3;
  array[4] = &T2;
  for(int i=0;i<5;i++)
  {
    cout<<"Printing Now"<<endl;
    array[i]->details();
  }

}

int main()
{
  // TestCar();
  // TestTruck();
  Test();
  return 0;
}
