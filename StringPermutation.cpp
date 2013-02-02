#include <iostream>
 
using namespace std;
 
void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}
void string_permutation(char current[], int curr_index, int N)
{
    //cout<<"current string : "<<current<<" orignal string: "<<orig<<" current index:"<<curr_index<<"max lenght:"<<N<<endl;
    if(curr_index == (N))
    {
        int i =0;
        while(i<N)
        cout<<current[i++];
        cout<<endl;
        return;
    }
    for(int i = curr_index; i < N; i++)
    {
        swap(current+curr_index, current + i);
        string_permutation(current, curr_index + 1, N);
        swap(current+curr_index, current + i);
    }
}
 
int main() {
    char current[]="abcd";
        string_permutation(current, 0, 4);
        return 0;
}
