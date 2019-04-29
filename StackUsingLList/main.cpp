#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
class Stack
{
private:
    Node*head;
public:
    Stack();
    Node*getNode(int e);
    void insertHead(int d);
    void deleteHead();
    int topElement();
    bool Find(int e);
    bool isEmpty();
    void display();
    ~Stack();
};
Node*Stack::getNode(int e)
{
    Node*temp = new Node;
    temp->data = e;
    temp->next = NULL;
    return temp;
}
Stack::Stack()
{
    head = NULL;
}
void Stack::insertHead(int d)
{
    if(head==NULL)
    {
        head = getNode(d);
    }
    else
    {
        Node*temp = getNode(d);
        temp->next = head;
        head = temp;
    }
}
void Stack::deleteHead()
{
    if(!isEmpty())
    {
        Node*temp = head;
        head = head->next;
        delete temp;
    }
}
int Stack::topElement()
{
    if(!isEmpty())
    {
        return head->data;
    }
    else
    {
        cout<<"Error stack is empty"<<endl;
        return -1;
    }
}
bool Stack::isEmpty()
{
    if(head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Stack::Find(int e)
{
    if(!isEmpty())
    {
        Node*temp = head;
        while(temp)
        {
            if(temp->data==e)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
    else
    {
        return 0;
    }
}
void Stack::display()
{


        Node*temp = head;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }

}
Stack::~Stack()
{
    if(!isEmpty())
    {
        Node*temp = head;
        while(temp)
        {
            temp = temp->next;
            delete head;
            head = temp;
        }
        head = NULL;
    }
}
int main()
{
    Stack s;
    s.insertHead(99);
    s.insertHead(102);
    //s.deleteHead();
    //s.deleteHead();
    s.insertHead(1022);
    //cout<<s.Find(10222)<<endl;
    //s.deleteHead();
    //cout<<s.isEmpty()<<endl;
    s.display();
}
