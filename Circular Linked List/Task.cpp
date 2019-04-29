#include <iostream>
using namespace std;

struct Node
{
  Node*next;
  int data;
};
class CLL
{
private:
  Node*last;
public:
  CLL();
  CLL(int d);
  Node*getNode(int d);
  void insert(int d);
  void remove(int d);
  bool isEmpty();
  bool find(int d);
  void clear();
  void print();
  CLL&operator =(const CLL&C);// = operator overloading
  CLL(const CLL&C);
  void copy(CLL C);
  ~CLL();
};
CLL::CLL()
{
  last = NULL;
}
CLL::CLL(int d)
{
  Node*temp = getNode(d);
  temp->next = temp;
  last = temp;
}
Node*CLL::getNode(int d)
{
  Node*temp = new Node;
  temp->data = d;
  temp->next = NULL;
  return temp;
}
void CLL::insert(int d)
{
  if(!last)
  {
    last = getNode(d);
    last->next = last;
  }
  else
  {
    // cout<<"I entered here"<<endl;
      Node*temp = getNode(d);

      Node*temp2 = last->next;
      last->next = temp;
      temp->next = temp2;
      // cout<<temp<<endl;
      // cout<<temp2<<endl;
      // cout<<last<<endl;
  }
}
void CLL::print()
{
  if(last)
  {

    Node*temp = last->next;
    if(temp->next!=temp)
    {


      while(temp!=last)
      {
        cout<<temp->data<<"->";
        temp = temp->next;
      }
      cout<<temp->data<<endl;
    }
    else
    {
      cout<<temp->data<<endl;
    }
  }
}
void CLL::remove(int d)
{
  if(last->data==d&&last->next==last)
  {
    delete last;
    last = NULL;
  }
  else if(last->data==d&&last->next!=last)
  {
    Node*temp = last->next;
    while(temp->next!=last)
    {
      temp = temp->next;
    }
    temp->next = last->next;
    delete last;
    last = temp;
  }
  else
  {
    Node*temp = last;
    while(temp->data!=d)
    {
      if(temp->data == d)
      {
        break;
      }
      temp = temp->next;
    }
    Node*temp2 = last;
    while(temp2->next!=temp)
    {
      temp2 = temp2->next;
    }
    temp2->next = temp->next;
    delete temp;
  }
}
bool CLL::find(int d)
{
  Node*temp = last;
  bool flag = true;
  while(temp!=last||flag)
  {
    flag = false;
    if(temp->data == d)
    {
      return true;
    }
    temp = temp->next;
  }
  return false;
}
bool CLL::isEmpty()
{
  if(!last)
  {
    return true;
  }
  return false;
}
void CLL::clear()
{
  Node*temp = last->next;
  bool flag = true;
  while(temp!=last||flag)
  {
    flag = false;
    temp = temp->next;
    delete last;
    last = temp;
  }
  last = NULL;
}
CLL &CLL::operator =(const CLL&C)
{
  if(this==&C)
  {
    return *this;
  }
  else
  {
    this->clear();
    this->copy(C);
    return *this;

  }
}
CLL::CLL(const CLL&C)
{
  this->clear();
  this->copy(C);
}
void CLL::copy(CLL C)
{

  Node*temp = C.last;
  bool flag = true;
  while(temp!=C.last||flag)
  {
    flag = false;
    this->insert(temp->data);
    temp = temp->next;
  }
}
CLL::~CLL()
{
  clear();
}
int main()
{
  CLL C(9);
  for(int i=0;i<10;i++)
  {
    C.insert(i);
  }
  C.clear();
  C.insert(100);
  C.insert(101);
  C.print();
  CLL C2(C);
  C2.print();
  return 0;
}
