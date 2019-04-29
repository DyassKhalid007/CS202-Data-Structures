#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*next;
};
class LList
{
private:
    Node*head;
    int index;
public:
    LList();
    LList(int x);
    Node*getNode(int x);
    void headInsert(int x,int i=0);
    void tailInsert(int x,int i=0);
    void deleteHead();
    void deleteTail();
    void deleteIndex(int i);
    void insert(int i,int x);
    void display();
    ~LList();
};
LList::LList()
{
    head = NULL;
    index = 0;
}
LList::LList(int x)
{
    index=0;
    head = getNode(x);
}
Node*LList::getNode(int x)
{
    Node*temp = new Node;
    temp->data = x;
    temp->next = NULL;
    index++;
    return temp;
}
void LList::insert(int i,int x)
{
    Node*temp = getNode(x);
    if(i==0)
    {
        cout<<"Entered c1"<<endl;
        //insert at head
        temp->next = head;
        head = temp;
    }
    else if(i==index)
    {
        cout<<"Entered c2"<<endl;
        Node*endNode = head;
        while(endNode->next!=NULL)
        {
            endNode = endNode->next;
        }
        endNode->next = temp;
    }
    else if(i>0&&i<index)
    {
        cout<<"Entered c3"<<endl;
        cout<<"index"<<i<<endl;
        int j=0;
        Node*reachNode = head;
        while(i-1!=j)
        {
            reachNode = reachNode->next;
            j++;
        }
        cout<<"j"<<j<<endl;
        Node*nextNode = reachNode->next;
        reachNode->next = temp;
        temp->next = nextNode;
    }
    else
    {
        cout<<"Invalid index is entered"<<endl;
    }
}
void LList::headInsert(int x,int i)
{
    insert(i,x);
}
void LList::tailInsert(int x,int i)
{
    i = index+1;
    insert(i,x);
}
void LList::display()
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
void LList::deleteIndex(int i)
{
    if(index==1)
    {
        //delete head
        Node*temp = head;
        head = head->next;
        delete temp;
        index--;
    }
    else if(i==index)
    {
        //delete the tail
        Node*reachEnd = head;
        while(reachEnd->next->next!=NULL)
        {
            reachEnd = reachEnd->next;
        }
        Node*temp2 = reachEnd->next;
        reachEnd->next = NULL;
        delete temp2;
        index = index-1;
    }
    else if(i>0&&i<index)
    {
        cout<<"entered here"<<endl;
        Node*reachNode = head;
        int j=0;
        Node*reachBefore;
        while(j!=i)
        {
            reachNode = reachNode->next;
            j++;
        }
        cout<<"Reached here"<<endl;
        cout<<reachNode->data<<endl;
        reachBefore = head;
        while(reachBefore->next!=reachNode)
        {
            reachBefore = reachBefore->next;
        }
        Node*reachAfter = reachNode->next;
        reachBefore->next = reachAfter;
        delete reachNode;
        index = index-1;
    }
}
void LList::deleteHead()
{
    deleteIndex(0);
}
void LList::deleteTail()
{
    deleteIndex(index);
}
LList::~LList()
{
    Node*temp = head;
    while(head)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
    head = NULL;
}
int main()
{
    LList L;
    L.insert(0,1);
    L.deleteTail();
    L.display();
}
