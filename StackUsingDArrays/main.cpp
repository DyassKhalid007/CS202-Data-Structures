#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int maxtop;
    double *values;
public:
    Stack(int size=10);
    void push(double e);
    double pop();
    bool isFull();
    bool isEmpty();
    void display();
    double Top();
    ~Stack();
};
Stack::Stack(int size)
{
    values = new double[size];
    top = -1;
    maxtop = size-1;
}
void Stack::push(double e)
{
    if(isFull())
    {
        cout<<"Error:Stack is full"<<endl;
    }
    else
    {
        values[++top] = e;
    }
}
double Stack::pop()
{
    if(isEmpty())
    {
        cout<<"Error:Stack is empty"<<endl;
        return -1;
    }
    else
    {
        return values[top--];
    }
}
bool Stack::isEmpty()
{
    return top==-1;
}
bool Stack::isFull()
{
    return top==maxtop;
}
void Stack::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<values[i]<<endl;
    }
}
Stack::~Stack()
{
    delete []values;
}
double Stack::Top()
{
    if(!isEmpty())
    {
        return values[top];
    }
}
int main()
{
    Stack s;
    for(int i=0;i<10;i++)
    {
        s.push(i);
    }
    s.display();
    cout<<s.pop()<<endl;
    cout<<"Printing stack again"<<endl;
    s.display();
    cout<<"The top of stack is:"<<endl;
    cout<<s.Top()<<endl;


}

