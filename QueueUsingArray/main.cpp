#include <iostream>
using namespace std;
class Queue
{
private:
    int maxFront;
    int front;
    int back;
    int*values;
public:
    Queue(int size=10);
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};
Queue::Queue(int size)
{
    values = new int[size];
    maxFront = size-1;
    front=0;
    back = -1;
}
void Queue::enqueue(int x)
{
    if(!isFull())
    {
        values[++back] = x;
    }
    else
    {
        cout<<"Error Queue is full"<<endl;
    }
}
void Queue::dequeue()
{
    if(!isEmpty())
    {
        for(int i=0;i<back;i++)
        {
            values[i] = values[i+1];
        }
        back--;
    }
    else
    {
        cout<<"Queue is already empty."<<endl;
    }
}
bool Queue::isEmpty()
{
    return back==-1;
}
bool Queue::isFull()
{
    return back==maxFront;
}
void Queue::display()
{
    if(back==0)
    {
        cout<<values[0]<<endl;
    }
    else
    {
        for(int i=0;i<=back;i++)
        {
        cout<<values[i]<<"->";
        }
    }
}
int main()
{
    Queue Q;
    for(int i=0;i<10;i++)
    {
        Q.enqueue(i);
    }
    Q.display();
    Q.enqueue(1);
    for(int i=0;i<12;i++)
    {
        Q.dequeue();
    }
    Q.enqueue(123);
    Q.display();
}
