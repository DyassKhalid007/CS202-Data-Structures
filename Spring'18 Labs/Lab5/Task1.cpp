//Train using linked list
#include <iostream>
using namespace std;

struct Node
{
  int capacity = 0;
  Node*next;
};
class Train
{
private:
  Node*head;
public:
  Train();
  Train(int p);//p is number of passengers.
  void addCabin(int p);
  void checkAddCabin(int p);
  void print();
  void dropPassengers();
  void transferPassengers(Train &t);
  void returnJourney();
  bool check(int p);
  ~Train();
};
Train::Train()
{
  head = NULL;
}
Train::Train(int p)
{
  if(p<=10&&p>=0)
  {
    head = new Node;
    head->next = NULL;
    head->capacity = p;
  }
  else if(p>10)
  {
    cout<<"Passengers greater than 10 are not accomodated"<<endl;
  }
  else
  {
    cout<<"Passengers cannot be negative"<<endl;
  }
}
void Train::addCabin(int p)
{
  if(check(p))
  {
    if(head!=NULL)
    {
      for(Node*temp=head;temp!=NULL;temp=temp->next)
      {
        if(!temp->next)
        {
          temp->next = new Node;
          temp = temp->next;
          temp->next = NULL;
          temp->capacity = p;
          break;
        }
      }
    }
    else
    {
      head = new Node;
      head->next = NULL;
      head->capacity = p;
    }
  }
  else
  {
    cout<<"Cabin cannot be added due to passengers"<<endl;
  }
}
void Train::checkAddCabin(int p)
{
  if(check(p))
  {
    if(head)
    {
      for(Node*temp=head;temp!=NULL;temp=temp->next)
      {
        if(!temp->next)
        {
          if(temp->capacity<10)
          {
            //add to this cabin untill p==0 or capacity==10
            while (p!=0&&temp->capacity<10)
            {
              temp->capacity++;
              p--;
            }
          }
            if(p)
            {
              temp->next = new Node;
              temp = temp->next;
              temp->next = NULL;
              temp->capacity = p;
              break;
          }
        }
      }
    }
    else
    {
      head = new Node;
      head->next = NULL;
      head->capacity = p;
    }
  }
  else
  {
    cout<<"Cabin cannot be added due to passengers"<<endl;
  }
}
void Train::print()
{
  if(head)
  {
    for(Node*temp=head;temp!=NULL;temp=temp->next)
    {
      cout<<temp->capacity<<"->";
    }
  }
  else
  {
    cout<<"Train has no cabin"<<endl;
  }
}
void Train::dropPassengers()
{
  if(head)
  {
    for(int j=0;j<3;j++)
    {
      int i=0;
      for(Node*temp=head;temp!=NULL;temp=temp->next,i++)
      {
        if(i%2!=0)
        {
          if(temp->capacity>0)
          {
            temp->capacity--;
          }
        }
      }
      cout<<"After "<<j+1<<" stop:";
      this->print();
      cout<<endl;
    }
  }
}
void Train::transferPassengers(Train &t)
{
  if(head)
  {
    Node*temp = head;
    while (temp!=NULL)
    {
      t.addCabin(temp->capacity);
      temp = temp->next;
    }
    for(Node*temp=head;temp!=NULL;temp=temp->next)
    {
      temp->capacity = 0;
    }
  }
  cout<<"The default train now has:"<<endl;
  this->print();
  cout<<endl;
  cout<<"The new train now has:"<<endl;
  t.print();
  cout<<endl;
}
void Train::returnJourney()
{
  int length = 0;
  for(Node*temp=head;temp!=NULL;temp=temp->next)
  {
    length++;
  }
  //cout<<"length:"<<length<<endl;
  int array[length];
  int i=0;
  for(Node*temp=head;temp!=NULL;temp=temp->next)
  {
    array[i] = temp->capacity;
    i++;
  }
  for(Node*temp=head;temp!=NULL;temp=temp->next)
  {
    temp->capacity = array[--length];
  }


}
bool Train::check(int p)
{
  if(p<=10&&p>=0)
  {
    return true;
  }
  return false;
}
Train::~Train()
{
  if(head)
  {
    Node*temp = head;
    while(temp!=NULL)
    {
      temp = temp->next;
      delete head;
      head = temp;
    }

  }
}
void Test_Train_deafult()
{
  //Parameterized,addCabin,print
  Train t(10);

  for(int i=0;i<50;i++)
  {

    t.addCabin(i);//exhaustive checking of add function
  }
  t.print();
  cout<<endl;
  Train t2;
  t2.addCabin(10);
  t2.addCabin(12);
  t2.addCabin(1);
  t2.print();
}
void Test_Train()
{
  Train t(5);
  t.checkAddCabin(10);
  t.checkAddCabin(2);
  t.checkAddCabin(2);
  t.checkAddCabin(1);
  t.checkAddCabin(5);
  t.checkAddCabin(7);
  t.print();
}
void Test_Drop()
{
  Train t(5);
  for(int i=0;i<10;i++)
  {
    t.addCabin(i);
  }
  t.print();
  cout<<"Performing drop operation"<<endl;
  t.dropPassengers();
  t.print();
}
void Test_Transfer()
{
  Train t(10);
  for(int i=0;i<10;i++)
  {
    t.addCabin(i);
  }
  Train t2;
  t.transferPassengers(t2);
  t2.print();

}
void Test_Return()
{
  Train t(10);
  for(int i=0;i<10;i++)
  {
    t.addCabin(i);
  }
  t.print();
  t.returnJourney();
  t.print();
}
int main()
{
  Test_Train_deafult();
  Test_Train();
  Test_Drop();
  Test_Transfer();
  Test_Return();
  return 0;
}
