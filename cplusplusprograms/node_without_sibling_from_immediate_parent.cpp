#include <iostream>
using namespace std;
typedef struct node
{
  node(int _data)
  {
    data = _data;
    left = NULL;
    right = NULL;
  }
  int data;
  struct node *left;
  struct node *right;
}Node;

void print_without_sibling(Node *node)
{
    if(node == NULL)
    {
        return;
    }
    if(node->left == NULL || node->right == NULL)
    {
        if(node->left == NULL)
        {
            if(node->right)
            {
                cout<<node->right->data<<endl;
                print_without_sibling(node->right);
            }
        }
        else
        {
            cout<<node->left->data<<endl;
            print_without_sibling(node->left);
        }
    }
    else
    {
         print_without_sibling(node->left);
         print_without_sibling(node->right);
    }
    return;
}
int main()
{
  Node *node = new Node(1);
  node->left = new Node(2);
  node->right = new Node(3);
  node->left->right = new Node(4);
  node->right->left = new Node(5);
  print_without_sibling(node);
  return 0;
}
  
