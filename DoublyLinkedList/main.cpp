#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*next;
    Node*previous;
};
class DList
{
private:
    Node*head;
    Node*tail;
public:
    DList();
    DList(int x);
    Node*getNode(int d);
    void HeadInsert(int d);
    void TailInsert(int d);
    void deleteHead();
    void deleteTail();
    void display();
};
DList::DList()
{
    head = NULL;
    tail = NULL;
}
DList::DList(int x)
{
    head = getNode(x);
    tail = head;
}
Node*DList::getNode(int d)
{
    Node*temp = new Node;
    temp->next = NULL;
    temp->previous = NULL;
    temp->data = d;
    return temp;
}
void DList::HeadInsert(int d)
{
    Node*temp = getNode(d);
    if(!head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }

}
void DList::TailInsert(int d)
{
    Node*temp = getNode(d);
    if(!tail)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }

}
void DList::display()
{
    if(head)
    {
        Node*temp = head;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
}
void DList::deleteHead()
{
    if(head==tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node*temp = head;
        head = head->next;
        head->previous = NULL;
        temp->next = NULL;
        delete temp;
    }
}
void DList::deleteTail()
{
    if(head==tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node*temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        temp->previous = NULL;
        delete temp;
    }
}

int main()
{
    DList D;
    D.TailInsert(0);
    D.TailInsert(1);
    D.HeadInsert(11);
    D.display();
    D.deleteTail();
    D.deleteHead();
    D.deleteHead();
    D.TailInsert(1);
    D.HeadInsert(12);
    cout<<endl;
    D.display();


}
