#include <iostream>
#include <stack>
using namespace std;

class Stack
{
private:
    stack<int>remainders;
public:
    Stack(int e);
    void display();
};
Stack::Stack(int e)
{
    if(e>=0)
    {
        while(e>0)
        {

           remainders.push(e%2);
           e = e/2;
           cout<<e<<endl;
        }
    }
}
void Stack::display()
{
    cout<<"The number in base 2 is:"<<endl;
    int size = remainders.size();
    for(int i=0;i<size;i++)
    {
        int e = remainders.top();
        remainders.pop();
        cout<<e;
    }
}

int main()
{
    Stack s(9999);
    s.display();
}
