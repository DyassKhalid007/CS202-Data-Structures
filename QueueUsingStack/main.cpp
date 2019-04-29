#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> q;
public:
    Queue();
    Queue(int d);
    void pop();
    void top();
    void display();
    void push(int e);
};
Queue::Queue()
{

}
Queue::Queue(int d)
{
    q.push(d);
}
void Queue::push(int e)
{
    q.push(e);
}

void Queue::pop()
{
    stack<int> s2;
    while(!q.empty())
    {
        s2.push(q.top());
        q.pop();
    }
    s2.pop();
    while(!s2.empty())
    {
        q.push(s2.top());
        s2.pop();
    }
}
void Queue::display()
{
    stack<int> s = q;
    while(!s.empty())
    {
        cout<<s.top()<<"->";
        s.pop();
    }
}
int main()
{
  Queue q;
  q.push(9);
  q.push(99);
  q.push(102);
  q.display();
  cout<<endl;
  q.pop();
  q.pop();
  q.pop();
  q.display();
}
