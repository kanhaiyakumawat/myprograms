#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[], int start, int end)
{
    int pivot = start;
    
    int i = start + 1;
    int j = end;
    
    while(i <= j)
    {
        while(array[i] <= array[pivot])
        {
            i++;
        }
        while(array[j] > array[pivot])
        {
            j--;
        }
    
        if(i < j)
        {
            swap(array[i], array[j]);
        }
    }
    swap(array[j],array[pivot]);
    pivot = j;
    return pivot;
    
}
void quick_sort(int array[], int start, int end)
{
    if(start >= end)
    {
        return;
    } 
    int pivot = partition(array, start, end);
    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, end);
}

void print(int arrar[], int len)
{
    int i = 0;
    while(i < len)
    {
        cout<<arrar[i++]<<" ";
    }
    cout<<endl;
}

int main()
{
    int array[]={12,4,6,1,7,16,9,14,2};
    print(array, 9);
    quick_sort(array, 0,8);
    print(array, 9);
    return 0;
}
