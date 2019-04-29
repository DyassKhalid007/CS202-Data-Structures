#include "stack.h"
void Test_Stack()
{
  stack s;
  cout<<"The stack is empty:"<<s.isEmpty()<<endl;
  s.push("5");
  cout<<"The stack is empty:"<<s.isEmpty()<<endl;
  cout<<"The stack is full:"<<s.isFull()<<endl;
  s.push("1");
  s.push("9");
  s.pop();
  s.pop();
  s.pop();
  s.push("1");
  s.push("2");
  s.push("3");
  cout<<"The stack is full:"<<s.isFull()<<endl;
  s.print();
}
void Test_push()
{
  stack s;
  s.push("8");
  s.push("9");
  s.push("99");
  s.print();
}
int main()
{
  // Test_Stack();
  Test_push();
  return 0;
}
