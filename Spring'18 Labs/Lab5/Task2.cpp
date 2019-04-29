#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node*next;
};
class stack
{
private:
  Node*top;
  int size;
public:
  stack();
  stack(int d);
  void push(int e);
  void pop();
  void clear();
  bool duplicate();
  stack& operator =(const stack&s);//This is new
  bool operator ==(const stack&s);
  void print();
  ~stack();
};
stack::stack()
{
  size=0;
  top = NULL;
}
stack::stack(int d)
{
  size=0;
  top = new Node;
  top->next = NULL;
  top->data = d;
  size++;

}
void stack::push(int e)
{
  if(top)
  {
    Node* newN = new Node;
    newN->data = e;
    newN->next = top;
    top = newN;
  }
  else
  {
    top = new Node;
    top->data = e;
    top->next = NULL;
  }
  size++;
}
void stack::pop()
{
  if(top)
  {
    Node*temp = top;
    top = top->next;
    delete temp;
    size--;
  }
}
stack& stack::operator =(const stack&s)
{
  //checking for self assignment
  if(this==&s)
  {
    return *this;
  }
  //Now deallocating the memory in previous Stack
  this->clear();
  //Now deep copying
  for(Node*temp=s.top;temp!=NULL;temp=temp->next)
  {
    this->push(temp->data);
  }
  return *this;

}
bool stack::operator ==(const stack&s)
{
  if(s.size!=this->size)
  {
    return false;
  }
  Node*temp2 = this->top;
  for(Node*temp=s.top;temp!=NULL;temp=temp->next,temp2=temp2->next)
  {
    if(temp->data!=temp2->data)
    {
      return false;
    }
  }
  return true;

}
void stack::clear()
{
  if(top)
  {
    Node*temp = top;
    while(temp!=NULL)
    {
      temp = temp->next;
      delete top;
      top = temp;
    }
    size=0;
  }
}
bool stack::duplicate()
{
  if(top)
  {
    for(Node*temp=top;temp!=NULL;temp=temp->next)
    {
      for(Node*temp2=temp->next;temp2!=NULL;temp2=temp2->next)
      {
        if(temp->data==temp2->data)
        {
          return true;
        }
      }
    }
    return false;
  }
  return false;
}
void stack::print()
{
  if(top)
  {
    Node*temp = top;
    while (temp!=NULL)
    {
      cout<<temp->data<<"->";
      temp = temp->next;
    }
  }
  else
  {
    cout<<"Stack is empty"<<endl;
  }
}
stack::~stack()
{
  clear();
}
void Test_Stack_default()
{
  stack s;//working fine
  for(int i=0;i<10;i++)
  {
    s.push(i);//working fine
    s.pop();//working fine

  }

  s.print();//working fine
  cout<<endl;

  s.print();
  cout<<endl;
  stack s2(10);//working fine
  for(int i=0;i<1000;i++)
  {
    s2.push(i);//working fine
  }
  s2.clear();//working fine
  s2.print();
}
void Test_Duplicate()
{
  stack s;
  for(int i=0;i<10;i++)
  {
    s.push(i);
  }
  s.push(5);
  cout<<s.duplicate()<<endl;//working fine
}
void Test_Assignment()
{
  stack s(10);
  stack s2;
  s2 = s;//working fine
  s.push(12);
  s2.push(9);
  s2.print();
}
void Test_Equality()
{
  stack s(10);
  for(int i=0;i<10;i++)
  {
    s.push(i);
  }
  stack s2(10);
  for(int i=0;i<9;i++)
  {
    s2.push(i);
  }
  s2.push(9);
  bool result=s==s2;//working fine
  cout<<"The result is:"<<result<<endl;
}
int main()
{
  //Test_Stack_default();
  //Test_Duplicate();
  //Test_Assignment();
  //Test_Equality();

}
