#include <iostream>
using namespace std;

class Point
{
private:
  int x;
  int y;
  int z;
public:
  Point();
  Point(int a);
  Point(int a,int b);
  Point(int a,int b,int c);
  void setX(int a);
  void setY(int b);
  void setZ(int c);
  int getX();
  int getY();
  int getZ();
  bool operator ==(Point a);
  friend istream& operator >>(istream&input,Point& a);
  friend ostream&operator <<(ostream&output,Point&a);
};
Point::Point()
{
  x=0;
  y=0;
  z=0;
}
Point::Point(int a)
{
  x = a;
  y = 0;
  z = 0;
}
Point::Point(int a,int b)
{
  x = a;
  y = b;
  z = 0;
}
Point::Point(int a,int b,int c)
{
  x = a;
  y = b;
  z = c;
}
void Point::setX(int a)
{
  x = a;
}
void Point::setY(int b)
{
  y = b;
}
void Point::setZ(int c)
{
  z = c;
}
int Point::getX()
{
  return x;
}
int Point::getY()
{
  return y;
}
int Point::getZ()
{
  return z;
}
bool Point::operator ==(Point a)
{
  if(a.x==this->x&&a.y==this->y&&a.z==this->z)
  {
    return true;
  }
  return false;
}
istream& operator >>(istream&input,Point& a)
{
  input>>a.x;
  input>>a.y;
  input>>a.z;
}
ostream&operator <<(ostream&output,Point&a)
{
  output<<"x:"<<a.x<<endl;
  output<<"y:"<<a.y<<endl;
  output<<"z:"<<a.z<<endl;
}
void Test_Point()
{
  //testing the parameterized construtor and setters and getters and overloaded operators
  Point p;
  p.setX(1);
  p.setY(2);
  p.setZ(3);
  cout<<p.getX()<<endl;
  cout<<p.getY()<<endl;
  cout<<p.getZ()<<endl;
  cout<<p;
  cin>>p;
  cout<<p;
  //Testing the default and 2 parametre constructors
  Point p2(2);
  cout<<p2;
  Point p3(2,4);
  cout<<p3;
  Point p4(1,2,3);
  cout<<p4;
}
int main()
{
  Test_Point();
  return 0;
}
