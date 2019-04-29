#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
};
class BTree
{
private:
    Node*root;
    void insert(Node*r,int d);
public:
    BTree();
    Node*getNode(int d);
    void insert(int d);
    void inorder(Node*r);
    void deleteNode(int d);
    void deletion(Node*r,Node*ToBeDeleted);
    void print();
    void deleteNode(Node*r,int d);
};
BTree::BTree()
{
    root = getNode(0);
}
void BTree::insert(int d)
{
     insert(root,d);
}
void BTree::insert(Node*r,int d)
{
    queue<Node*>q;
    q.push(r);
    while(!q.empty())
    {
        Node*temp = q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left = getNode(d);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if(!temp->right)
        {
            temp->right = getNode(d);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
Node*BTree::getNode(int d)
{
    Node*temp = new Node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = d;
    return temp;
}
void BTree::inorder(Node*r)
{
    if(r)
    {

     inorder(r->left);
     cout<<r->data<<"->";
     inorder(r->right);
    }
}
void BTree::print()
{
    inorder(root);
}
void BTree::deleteNode(int d)
{
    deleteNode(root,d);
}
void BTree::deleteNode(Node*r,int d)
{
    queue<Node*> q;
    q.push(r);
    Node*temp;
    Node*keyNode;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data==d)
        {
            keyNode = temp;
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
    }
    int x = temp->data;
    deletion(root,temp);
    keyNode->data = x;

}
void BTree::deletion(Node*r,Node*tobeDeleted)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*temp = q.front();
        q.pop();
        if(temp->right)
        {
            if(temp->right==tobeDeleted)
            {
                temp->right = NULL;
                delete tobeDeleted;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if(temp->left)
        {
            if(temp->left==tobeDeleted)
            {
                temp->left = NULL;
                delete tobeDeleted;
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}


int main()
{
    BTree B;
    B.insert(90);
    B.insert(9);
    B.print();
    B.deleteNode(90);
    B.print();
}
