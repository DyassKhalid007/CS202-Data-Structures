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
  Node*getNode();
  Node*remove(Node*temp,int d);
  Node*insert(Node*temp,int d);
  Node*search(Node*temp,int d);
  Node*findMax(Node*temp);
  Node*findMin(Node*temp);
  void inorder(Node*temp);
public:
  BST();
  BST(int d);
  void insert(int d);
  bool search(int d);
  int findMax();
  int findMin();
  void remove(int d);
  void display();
};
Node*BST::getNode()
{
  Node*temp = new Node;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
Node*BST::insert(Node*temp,int d)
{
  if(!temp)
  {
    temp = getNode();
    temp->data = d;
  }
  else if(d>temp->data)
  {
    temp->right = insert(temp->right,d);
  }
  else if(d<temp->data)
  {
    temp->left = insert(temp->left,d);
  }
  return temp;
}
Node*BST::search(Node*temp,int d)
{
  if(!temp)
  {
    return NULL;
  }
  else if(d>temp->data)
  {
    search(temp->right,d);
  }
  else if(d<temp->data)
  {
    search(temp->left,d);
  }
  else
  {
    return temp;
  }
}
Node*BST::findMax(Node*temp)
{
  if(!temp)
  {
    return NULL;
  }
  else if(!temp->right)
  {
    return temp;
  }
  else
  {
    return findMax(temp->right);
  }
}
Node*BST::remove(Node*temp,int d)
{
  Node*t;
  if(!temp)
  {
    return NULL;
  }
  else if(d<temp->data)
  {
    temp->left = remove(temp->left,d);
  }
  else if(d>temp->data)
  {
    temp->right = remove(temp->right,d);
  }
  else if(temp->right&&temp->left)
  {
    t = findMin(temp->right);
    temp->data = t->data;
    temp->right = remove(temp->right,temp->data);
  }
  else
  {
    t = temp;
    if(!temp->right)
    {
      temp = temp->left;
    }
    else if(!temp->left)
    {
      temp = temp->right;
    }
    delete t;
  }
  return temp;
}
Node*BST::findMin(Node*temp)
{
  if(!temp)
  {
    return NULL;
  }
  else if(!temp->left)
  {
    return temp;
  }
  else
  {
    return findMin(temp->left);
  }
}
BST::BST()
{
  root = NULL;
}
BST::BST(int d)
{
  root = getNode();
  root->data = d;
}
void BST::insert(int d)
{
  root = insert(root,d);
}
bool BST::search(int d)
{
  if(search(root,d))
  {
    return true;
  }
  else
  {
    return false;
  }
}
int BST::findMax()
{
  Node*temp = findMax(root);
  return temp->data;
}
int BST::findMin()
{
  Node*temp = findMin(root);
  return temp->data;
}
void BST::remove(int d)
{
  remove(root,d);
}
void BST::inorder(Node*temp)
{
  if(!temp)
  {
    return;
  }
  inorder(temp->left);
  cout<<temp->data<<"->";
  inorder(temp->right);
}
void BST::display()
{
  inorder(root);
}
int main()
{
  BST B;
  B.insert(9);
  B.insert(100);
  B.insert(1);
  B.remove(9);
  B.insert(100);
  B.insert(101);
  B.display();
}
