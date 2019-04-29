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
  Node*insert(Node*temp,int d);
  Node*getNode();
  void inorder(Node*temp);//LNR
  Node*find(Node*temp,int d);
  Node*findMin(Node*temp);
  Node*findMax(Node*temp);
  Node*remove(Node*temp,int d);
  void clear(Node*temp);
public:
  BST();
  BST(int d);
  void insert(int d);
  void display();
  bool find(int d);
  int findMin();
  int findMax();
  void remove(int d);
  ~BST();
};
BST::BST()
{
  root = NULL;
}
BST::BST(int d)
{
  root = getNode();
  root->data = d;
}
Node* BST::insert(Node*temp,int d)
{
  if(!temp)
  {
    temp = getNode();
    temp->data = d;
  }
  else if(temp->data>d)
  {
    temp->left = insert(temp->left,d);
  }
  else if(temp->data<d)
  {
    temp->right = insert(temp->right,d);
  }
  return temp;
}
Node*BST::getNode()
{
  Node*temp = new Node;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
}
void BST::insert(int d)
{
  root = insert(root,d);
}
void BST::inorder(Node*t)
{
  if(!t)
  {
    return;
  }
  inorder(t->left);
  cout<<t->data<<endl;
  inorder(t->right);
}
void BST::display()
{
  inorder(root);
}
Node*BST::find(Node*temp,int d)
{
  if(!temp)
  {
    return NULL;
  }
  else if(d>temp->data)
  {
    find(temp->right,d);
  }
  else if(d<temp->data)
  {
    find(temp->left,d);
  }
  else
  {
    return temp;
  }
}
bool BST::find(int d)
{
  if(find(root,d))
  {
    return true;
  }
  else
  {
    return false;
  }
}
int BST::findMin()
{
  Node*temp = findMin(root);
  return temp->data;
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
int BST::findMax()
{
  Node*temp = findMax(root);
  return temp->data;
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
void BST::remove(int d)
{
  remove(root,d);
}
void BST::clear(Node*temp)
{
  if(temp)
  {
    clear(temp->left);
    clear(temp->right);
    delete temp;
  }
  temp = NULL;
}
BST::~BST()
{
  clear(root);
}

int main()
{
  BST B;
  B.insert(9);
  B.insert(100);
  B.insert(1);
  B.remove(9);
  B.display();

}
