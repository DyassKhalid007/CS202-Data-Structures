#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
};
class BST
{
private:
    Node*root;
    Node* insert(Node*r,int d);
    Node*remove(Node*r,int d);
    void InOrderPrint(Node*r);//Left Root Right
    void PreOrderPrint(Node*r);//Root Left Right
    void PostOrderPrint(Node*r);//Left Right Root
    void clear(Node*r);
    Node*findMin(Node*r);
public:
    BST();
    Node*getNode(int d);
    void insert(int d);
    void remove(int d);
    void print();
    ~BST();
};
BST::BST()
{
    root = NULL;
}
Node*BST::getNode(int d)
{
    Node*temp = new Node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = d;
    return temp;
}
void BST::insert(int d)
{
    root = insert(root,d);
}
Node*BST::insert(Node*r,int d)
{
    if(r==NULL)
    {
        r = getNode(d);
    }
    else if(d>r->data)
    {
        r->right = insert(r->right,d);
    }
    else if(d<r->data)
    {
        r->left = insert(r->left,d);
    }
    return r;
}
Node*BST::findMin(Node*r)
{
    if(!r)
    {
        return NULL;
    }
    else if(r->left==NULL)
    {
        return r;
    }
    else
    {
        return findMin(r->left);
    }
}
void BST::remove(int d)
{
    root = remove(root,d);
}
Node*BST::remove(Node*r,int d)
{
    Node*temp;
    if(!r)
    {
        return NULL;
    }
    else if(d>r->data)
    {
        r->right = remove(r->right,d);
    }
    else if(d<r->data)
    {
        r->left = remove(r->left,d);
    }
    else if(r->right&&r->left)
    {
        temp = findMin(r->right);
        r->data = temp->data;
        r->right = remove(r->right,temp->data);
    }
    else
    {
        temp = r;
        if(r->left==NULL)
        {
            r = r->right;
        }
        else if(r->right==NULL)
        {
            r = r->left;
        }
        delete temp;
    }
    return r;
}
void BST::print()
{
    InOrderPrint(root);
    cout<<endl;
}
void BST::InOrderPrint(Node*r)
{
    if(r)
    {
        InOrderPrint(r->left);
        cout<<r->data<<"->";
        InOrderPrint(r->right);
    }
}
void BST::PreOrderPrint(Node*r)
{
    if(r)
    {
        cout<<r->data<<"->";
        PreOrderPrint(r->left);
        PreOrderPrint(r->right);
    }
}
void BST::PostOrderPrint(Node*r)
{
    if(r)
    {
        PostOrderPrint(r->left);
        PostOrderPrint(r->right);
        cout<<r->data<<"->";
    }
}
void BST::clear(Node*r)
{
    if(r)
    {
        clear(r->left);
        clear(r->right);
        delete r;
    }
}
BST::~BST()
{
    clear(root);
    root = NULL;
}
int main()
{
    BST B;
    B.insert(9);
    B.insert(1);
    B.insert(15);
    B.insert(-1);
    B.print();
    B.remove(-1);
    B.print();
}
