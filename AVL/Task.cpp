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
  Node*root;
private:
  AVL();
  AVL(int d);
  Node*getNode(int d);
  int max(int a,int b);
  int getHeight(Node*temp);
  int getBalanceF(Node*temp);
  Node*rightRotate(Node*temp);
  Node*leftRotate(Node*temp);
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
int AVL::getHeight(Node*temp)
{
  if(temp == NULL)
  {
    return 0;
  }
  return temp->height;
}
int AVL::max(int a,int b)
{
  return (a>b)?a:b;
}
int AVL::getBalanceF(Node*temp)
{
  if(!temp)
  {
    return 0;
  }
  return(getHeight(temp->left)-getHeight(temp->right));
}
Node*AVL::rightRotate(Node*temp)
{
  Node*x = temp->right;
}



int main()
{
  return 0;
}
