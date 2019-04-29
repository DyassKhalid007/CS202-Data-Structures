#include <iostream>
#include <queue>
using namespace std;

class Stack
{
private:
    queue<int> s;
public:
    Stack();
    void push(int e);
    void pop();
    void display();
};
Stack::Stack()
{

}
void Stack::push(int e)
{

    queue<int>q;
    q.push(e);
    while(!s.empty())
    {
        q.push(s.front());
        s.pop();
    }

    s = q;

}
void Stack::pop()
{
    s.pop();
}
void Stack::display()
{
    queue<int>q2 = s;
    while(!q2.empty())
    {
        cout<<q2.front()<<endl;
        q2.pop();
    }
}

int main()
{
   Stack s;
   s.push(9);
   s.push(99);
   s.pop();
   s.display();
}
