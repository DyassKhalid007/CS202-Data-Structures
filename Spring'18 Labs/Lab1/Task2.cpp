#include <iostream>
using namespace std;

class Rectangle
{
private:
  int length;
  int width;
public:
  Rectangle();
  Rectangle(int l,int w);
  void setLength(int l);
  void setWidth(int w);
  void setBoth(int l,int w);
  int perimetre();
  int area();
  void is_square();
  void print();
};
Rectangle::Rectangle()
{
  //if no paremetres are provided set length and width to zero
  length = 0;
  width = 0;
}
Rectangle::Rectangle(int l,int w)
{
  //if both parameters are provided then set length and width to parameters
  length = l;
  width = w;
}
void Rectangle::setLength(int l)
{
  //setting length to l
  length = l;
}
void Rectangle::setWidth(int w)
{
  //setting width to w
  width = w;
}
void Rectangle::setBoth(int l,int w)
{
  //setting both length and width to l and  w respectively
  length = l;
  width = w;
}
int Rectangle::perimetre()
{
  //perimeter of rectangle is 2*length+2*width = 2*(length+width)
  return 2*(length+width);
}
int Rectangle::area()
{
  //calculating area of rectangle by length*width
  return length*width;
}
void Rectangle::is_square()
{
  //checking if a rectangle is square or not
  //A rectangle is square if its length is equal to its width
  if(length == width)
  {
    cout<<"Yes it is a square"<<endl;
  }
  else
  {
    cout<<"No is is not a square"<<endl;
  }
}
void Rectangle::print()
{
  for(int i = 0;i<length;i++)
  {
    cout<<"*";
  }
  cout<<endl;
  for(int i = 0;i<width;i++)
  {
    cout<<"*";
    for(int j = 0;j<length-2;j++)
    {
      cout<<" ";
    }
    cout<<"*"<<endl;
  }
  for(int i = 0;i<length;i++)
  {
    cout<<"*";
  }
}
void Test_Rectangle()
{
  //testing the parameterized constructor and then testing print function
  Rectangle R(5,5);
  R.print();
  cout<<endl;
  //testing the area,perimetre and is_square function
  cout<<R.area()<<endl;
  cout<<R.perimetre()<<endl;
  R.is_square();
  cout<<endl;
  //now testing the is_square function of not a square instance
  Rectangle R2(3,2);
  R2.is_square();
  cout<<endl;
  //Now testing default constructor and set functions
  Rectangle R3;
  R3.setLength(10);
  R3.setWidth(10);
  R3.print();
  cout<<endl;
  R3.setBoth(5,5);
  R3.print();

}
int main()
{
  Test_Rectangle();
  return 0;
}
