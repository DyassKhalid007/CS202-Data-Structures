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
    Node*insert(Node*p,int d);
    Node*remove(Node*p,int d);
    Node*findMin(Node*p);
public:
    BST();
    Node*getNode(int d);//function to get new Node;
    void insert(int d);
    void remove(int d);
};
BST::BST()
{
    root = NULL;
}
Node*BST::getNode(int d)
{
    Node*temp = new Node;
    temp->data=d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void BST::insert(int d)
{
    root = insert(root,d);
}
Node*BST::insert(Node*p,int d)
{
    if(p==NULL)
    {
        p = getNode(d);
    }
    else if(d>p->data)
    {
        p->right = insert(p->right,d);
    }
    else if(d<p->data)
    {
        p->left = insert(p->left,d);
    }
    return p;
}
Node*BST::findMin(Node*p)
{
    if(p==NULL)
    {
        return NULL;
    }
    else if(p->left==NULL)
    {
        return p;
    }
    else
    {
        return findMin(p->left);
    }
}
void BST::remove(int d)
{
    root = remove(root,d);
}
Node*BST::remove(Node*p,int d)
{
    Node*t;
    if(p==NULL)
    {
        return NULL;
    }
    else if(d>p->data)
    {
        p->right = remove(p->right,d);
    }
    else if(d<p->data)
    {
        p->left = remove(p->left,d);
    }
    else if(p->left&&p->right)
    {
        t = findMin(p->right);
        p->data = t->data;
        p->right = remove(p->right,p->data);
    }
    else
    {
        t = p;
        if(p->left==NULL)
        {
            p = p->right;
        }
        else if(p->right==NULL)
        {
            p = p->left;
        }
        delete t;
    }
    return p;
}


int main()
{

}
