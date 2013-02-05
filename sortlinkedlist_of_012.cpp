#include <iostream>

using namespace std;

typedef struct linklist
{
    int val;
    struct linklist *next;
}*LL;

LL HEAD = NULL;
LL TAIL = NULL;

void create_list(LL node)
{
    if(HEAD == NULL)
    {
        HEAD = node;
        TAIL = node;
    }
    else
    {
        TAIL->next = node;
        TAIL = node;
    }
}

LL create_node()
{
    int val = 0;
    cout<<"enter node value:";
    cin>>val;

    LL node = new linklist();
    if(node)
    {
        node->val = val;
        node->next = NULL;
    }
    else
    {
        cout<<"could not allocate sufficient memory";
    }
}

void sort_list(LL list)
{
    LL current = HEAD;
    LL previous = NULL;
    LL END = TAIL;
    int num1 = 0;
    int num2 = 2;

    while(current != NULL && current!=END)
    {
        if(current->val == num1)
        {
            if(current == HEAD)
            {
                previous = HEAD;
                current = current->next;
            }
            else
            {
                previous->next = current->next;
                current->next = HEAD;
                HEAD = current;
                current = previous->next;
            }
        }
        else if(current->val == num2)
        {
            if(current == HEAD)
            {
                HEAD = current->next;
                TAIL->next = current;
                current->next = NULL;
                TAIL = current;
                previous = NULL;
                current = HEAD;
            }
            else
            {
                previous->next = current->next;
                TAIL->next = current;
                current->next = NULL;
                TAIL = current;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}
void print_list()
{
    LL current = HEAD;
    cout<<"List:";
    while(current)
    {
        cout<<current->val;
        current = current->next;
    }
    cout<<"\n";
}
int main()
{
    char choice = 'n';
    do
    {
        LL node = create_node();
        create_list(node);
        cout<<"enter y if you want to add more nodes in the list:";
        cin>>choice;
    }while(choice == 'y');
    print_list();
    sort_list(HEAD);
    print_list();
    return 0;
}
