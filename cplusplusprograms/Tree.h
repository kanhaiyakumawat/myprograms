#ifndef MY_TREE_H
#define MY_TREE_H
#include <iostream>
#include "../stack/Stack.h"

using namespace std;

template <typename T>
class Tree
{
    public:
        Tree()
        {
            ROOT = NULL;
        }
        virtual ~Tree(){};
        virtual void add_node(T val);
        virtual void delete_node(T val);
        virtual void traverse();
    protected:
        class TreeNode
        {
            public:
                TreeNode(T v)
                {
                    val = v;
                    left = NULL;
                    right = NULL;
                }
                TreeNode *left;
                TreeNode *right;
                T val;
        };
        TreeNode *ROOT;
};
    template<typename T>
void Tree<T>::add_node(T val)
{
    TreeNode *node = new TreeNode(val);
    if(node)
    {
        if(ROOT)
        {
            TreeNode *temp = ROOT;
            while(temp)
            {
                if(temp->val > val)
                {
                    if(temp->left)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = node;
                        break;
                    }
                }
                else
                {
                    if(temp->right)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = node;
                        break;
                    }
                }
            }
        }
        else
        {
            ROOT = node;
        }
    }
    else
    {
        throw;
    }
}

    template<typename T>
void Tree<T>::delete_node(T val)
{

}
    template<typename T>
void Tree<T>::traverse()
{
    Stack<TreeNode*> stack;
    stack.push(ROOT);
    while(!stack.is_empty())
    {
        TreeNode *current = stack.pop();
        if(current->left)
        {
            stack.push(current->left);
        }
        if(current->right)
        {
            stack.push(current->right);
        }
        cout<<current->val<<endl;
    }
}
#endif
