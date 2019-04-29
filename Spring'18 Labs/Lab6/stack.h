//stack class using array
//no need of destructor since no dynamic memory is allocated
#include <iostream>
using namespace std;

const int size = 25;
class stack
{
private:
  string array[size];//string array is requirement
  int cap;//capacity
public:
  stack();
  stack(string e);
  void push(string e);
  void pop();
  string top();
  bool isEmpty();
  bool isFull();
  void print();
};
stack::stack()
{
  cap = 0;
}
stack::stack(string e)
{
  cap = 0;
  array[cap] = e;
  cap++;
}
void stack::push(string e)
{
  if(cap!=size)
  {
    for(int i=cap;i>0;i--)
    {
      array[i] = array[i-1];
    }
    array[0] = e;
    cap++;
  }
  else
  {
    cout<<"Stack is full"<<endl;
  }
}
void stack::pop()
{
  if(cap)
  {
    for(int i=0;i<cap-1;i++)
    {
      //move elements to lower indexed and decrease the capacity
      array[i] = array[i+1];
    }
    cap--;
  }
  else
  {
    cout<<"Nothing to pop"<<endl;
  }
}
string stack::top()
{
  if(cap)
  {
    return array[0];
  }
}
bool stack::isEmpty()
{
  if(cap)
  {
    return false;
  }
  return true;
}
bool stack::isFull()
{
  if(cap==size)
  {
    return true;
  }
  return false;
}
void stack::print()
{
  if(cap)
  {
    for(int i=0;i<cap;i++)
    {
      cout<<array[i]<<"->";
    }
    cout<<endl;
  }
  else
  {
    cout<<"Stack is empty"<<endl;
  }
}
