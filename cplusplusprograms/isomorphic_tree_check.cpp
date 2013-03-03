#include <iostream>
 
using namespace std;
 
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}*Tree, tree;
 
bool isisomorphic(Tree node1, Tree node2)
{
    if(node1->left && node2->left)
    {
        if(node1->left->data == node2->left->data)
        return node1->right->data == node2->right->data;
        else if(node1->right && node2->right)
        {
            return node1->left->data == node2->right->data && node1->right->data == node2->left->data;
        }
        else
        {
            return false;
        }
    }
    else if(!node1->left && !node2->left)
    {
        if(node1->right && node2->right)
        {
            return node1->right->data == node2->right->data;
        }
        else if(!node1->right && !node2->right)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else 
    {
        return false;
    }
    return false;
}
 
void add_node(Tree *root, int data, bool asc = true)
{
    cout<<"data: "<<data<<endl;
    Tree node = *root;
    Tree new_node = new tree;
    if(new_node)
    {
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    else
    {
        cout<<"error occured";
        return;
    }
    if(*root == NULL)
    {
        cout<<"added as root"<<endl;
        *root = new_node;
    }
    else
    {
        cout<<"added as child nodes"<<endl;
        while(node)
        {
            if(node->data <= data && asc)
            {
                if(node->right)
                {
                    node = node->right;
                }
                else
                {
                    node->right = new_node;
                    break;
                }
            }
            else
            {
                if(node->left)
                {
                    node =  node->left;
                }
                else
                {
                    node->left = new_node;
                    break;
                }
            }
        }
    }
}
 
void print_tree(Tree root)
{
    if(root)
    {
        cout<<root->data<<" ";
        print_tree(root->left);
        print_tree(root->right);
    }
    cout<<endl;
}
int main()
{
    cout<<"start the program\n";
    Tree root = NULL;
    Tree root2 = NULL;
    add_node(&root,8);
    add_node(&root,6);
    add_node(&root,11);
    add_node(&root2,8,false);
    add_node(&root2,6,false);
    add_node(&root2,11,false);
    print_tree(root);
    if(isisomorphic(root,root2)) cout<<"iso-morphic tree";
    else cout<<"non iso-morphic tree";

cout << "\n";
return 0;    
}
