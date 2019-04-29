#include <iostream>
using namespace std;

struct Node
{
  Node*left;
  Node*right;
  int data;
  int height;
};
class AVL
{
private:
  Node*root;
  Node*insert(Node*temp,int d);
  Node*getNode(int d);
public:
  AVL();
  AVL(int d);
  void insert(int d);
};
AVL::AVL()
{
  root = NULL;
}
AVL::AVL(int d)
{
  root = getNode(d);
}
Node*AVL::getNode(int d)
{
  Node*temp = new Node;
  temp->left = NULL;
  temp->right = NULL;
  temp->data = d;
  temp->height = 1;
  return temp;
}
Node*AVL::insert(Node*temp,int d)
{
  if(!temp)
  {
    temp = getNode(d);
  }
  else if(d>temp->data)
  {
    temp->right = insert(temp->right,d);
  }
  else if(d<temp->data)
  {
    temp->left = insert(temp->left,d);
  }
  else
  {
    return temp;
  }
}

int main()
{
  return 0;
}
