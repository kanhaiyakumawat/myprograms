#include <iostream>
#include "Tree.h"

using namespace std;
template<typename T>
class AncestorofTree:public Tree<int>
{
    public:
        T immediate_ancestor(T item)
        {
            if(ROOT != NULL)
            {
                if(ROOT->val == item)
                {
                    return -9999999;
                }
                else
                {
                    TreeNode *current = ROOT;
                    while(current)
                    {
                        if(current->val < item)
                        {
                            if(current->left)
                            {
                                if(current->left->val == item)
                                {
                                    return current->val;
                                }
                                else
                                {
                                    current = current->left;
                                }
                            }
                            else
                            {
                                return -9999999;
                            }
                        }
                        else
                        {
                            if(current->right)
                            {
                                if(current->right->val == item)
                                {
                                    return current->val;
                                }
                                else
                                {
                                    current = current->right;
                                }
                            }
                            else
                            {
                                return -9999999;
                            }
                        }
                    }

                }
            }
        }
};
int main()
{
    AncestorofTree<int> tree;

    tree.add_node(10);
    tree.add_node(5);
    tree.add_node(15);
    tree.traverse();
    cout<<tree.immediate_ancestor(5);
    return 0;
}
