#ifndef MY_STACK_H
#define MY_STACK_H

#include <iostream>

using namespace std;

template <typename T>
class Stack
{
    public:
        Stack()
        {
            ptr = NULL;
        }
        void push(T val);
        T pop();
        T top();
        bool is_empty()
        {
            return ptr == NULL;
        }

    private:
        class Item
        {
            public:
                Item(T v)
                {
                    val = v;
                    next = NULL;
                }
                Item *next;
                T val;
        };
        Item *ptr;
};

    template<typename T>
void Stack<T>::push(T val)
{
    Item *node = new Item(val);
    if(node)
    {
        node->next = ptr;
        ptr = node;
    }
    else
    {
        cout<<"stack overflow"<<endl;
        throw;
    }
}

    template<typename T>
T Stack<T>::pop()
{
    if(ptr)
    {
        Item *temp = ptr;
        T val = temp->val;
        ptr = ptr->next;
        delete temp;
        return val;
    }
    else
    {
        cout<<"stack underflow";
        throw;
    }
}

    template<typename T>
T Stack<T>::top()
{
    return ptr->val;
}
#endif
