#include <iostream>
using namespace std;
class Queue
{
private:
    int maxSize;
    int back;
    int front;
    int counter;
    int *values;
public:
    Queue(int size=10);
    void enqueue(int x);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void display();
    ~Queue();
};
Queue::Queue(int size)
{
    values = new int[size];
    maxSize = size;
    front = 0;
    counter = 0;
    back = -1;
}
void Queue::enqueue(int x)
{
    if(!isFull())
    {
        back = (back+1)%maxSize;
        values[back] = x;
        counter++;
    }
    else
    {
        cout<<"Queue is full"<<endl;
    }
}
void Queue::dequeue()
{
    if(!isEmpty())
    {
        front = (front+1)%maxSize;
        counter--;
    }
}
bool Queue::isEmpty()
{
    if(counter)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Queue::isFull()
{
    if(counter<maxSize)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Queue::display()
{
    for(int i=0;i<counter;i++)
    {
        cout<<values[(front+i)%maxSize]<<"->"<<endl;
        cout<<i<<endl;
    }
}
Queue::~Queue()
{
    delete[]values;
}
int main()
{
    Queue Q(2);
    Q.enqueue(99);
    Q.enqueue(123);
    Q.display();
}
