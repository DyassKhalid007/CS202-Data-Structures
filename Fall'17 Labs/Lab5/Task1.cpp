//implementation of queues using arrays
#include <iostream>
using namespace std;

class queue
{
private:
  int*p;
  int size;
  int current_capcity;
public:
  queue();
  queue(int s);
  void enqueue(int element);
  void dequeue();
  int min();
  int capcaity();
  void print();
};
queue::queue()
{
  size = 10;
  current_capcity = 0;
  p = new int[size];
}
queue::queue(int s)
{
  size = s;
  current_capcity = 0;
  p = new int[size];
}
void queue::enqueue(int element)
{
  if(current_capcity!=size)
  {
    p[current_capcity] = element;
    current_capcity++;
  }
  else
  {
    cout<<"Queue is full."<<endl;
  }
}
void queue::dequeue()
{
  if(current_capcity>0)
  {
    current_capcity--;
  }
}
int queue::min()
{
    int minimum = p[0];
    for(int i=0;i<current_capcity;i++)
    {
      if(p[i]<minimum)
      {
        minimum = p[i];
      }
    }
    return minimum;
}
int queue::capcaity()
{
  return current_capcity;
}
void queue::print()
{
    for(int i=0;i<current_capcity;i++)
    {
      cout<<p[i]<<endl;
    }
}
int main()
{
  //Testing queue in main
  queue q;
  for(int i=0;i<10;i++)
  {
    q.enqueue(i);
  }

  for(int i=0;i<10;i++)
  {
    q.print();
    q.dequeue();
    cout<<endl;
  }
  q.print();
  cout<<q.capcaity()<<endl;
  for(int i=0;i<10;i++)
  {
    q.enqueue(i);
    cout<<"Cureent cap:"<<q.capcaity()<<endl;
    q.print();
    cout<<endl;
  }
  cout<<"The minimum element is:"<<q.min()<<endl;




  return 0;
}
