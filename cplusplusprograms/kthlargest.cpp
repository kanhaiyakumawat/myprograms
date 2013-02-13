#include <iostream>
 
using namespace std;
 
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}*Tree, tree;
 
void kthlargest(Tree node, int *count, int k)
{
    if(node && *count < k)
    {
        kthlargest(node->right, count, k);
        *count = *count+1;
        if((*count) == k)
        {
            cout<<"found the kthlargest "<<node->data<<endl;
            return;
        }
        cout<<"k:"<<k<<" count:"<<*count<<" node data: "<<node->data<<endl;
        kthlargest(node->left, count, k);
    }
    return;
}
 
void add_node(Tree *root, int data)
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
            if(node->data <= data)
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
int *count = new int;
*count = 0;
int k = 5;
    Tree root = NULL;
    add_node(&root,8);
    add_node(&root,6);
    add_node(&root,11);
    add_node(&root,7);
    add_node(&root,5);
    add_node(&root,10);
    add_node(&root,16);
    print_tree(root);
    kthlargest(root,count,k);
cout<<endl;
return 0;    
}
