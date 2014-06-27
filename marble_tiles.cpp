/*
position is considered valid position as long as it has another marble in all 4 directions from where it is location (see example)
For example, in the following diagram, the black marbles are the places where marbles are present already and blue marble is the list of places where you can place a new marble. 

 
 
 
 
 
Given a board configuration, print the maximum number of places where you can keep a new marble.
Input Format: 
First line has two integer N and K. N is the size of the NxN grid and K is the number of marbles already present in the grid. K lines follow, in which each line has 2 integers X and Y. (X, Y) is the position of the marble present. 
Output Format: 
One integer which is the total number of places where you can keep a marble. 
Limits. 
N <= 1000. K <= N*N
Example.
6 9
0 2
1 1
1 5
2 0
2 2
2 5
4 0
4 2
5 1
Output:
3

*/

#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //read first line for board size and number of marbles
    string input;
    getline(cin, input);
    int N = 0;
    int K = 0;
    int arr[2];
    int i = 0;
    char_separator<char> sep(" ");
    tokenizer<char_separator<char>> tokens(input, sep);
    for (const auto& t : tokens) {
        arr[i++] = stoi(t);
    }
    N = arr[0];
    K = arr[1];
    //cout<<"done "<<N<<" "<<K<<endl;
    int **grid = new int*[N];
    bool *bottom_found = new bool[N];
    bool *top_not_found = new bool[N];
    for(int i = 0; i < N; i++)
    {
        grid[i] = new int[N];
        bottom_found[i] = top_not_found[i] = false;
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = 0;
        }
    }
    
    for(int i = 0; i < K; i++)
    {
        input.clear();
        getline(cin, input);
        
        int j = 0;
        tokenizer<char_separator<char>> tokens(input, sep);
        for (const auto& t : tokens) {
            arr[j++] = stoi(t);
            //cout<<"marbel location "<<marbels[i][j - 1]<<endl;
        }
        grid[arr[0]][arr[1]] = 1;
    }
    //check for each
    int count = 0;
  
    for(int i = 1; i < (N - 1); i++)
    {
        bool left_found = false;
        for(int j = 1; j < (N - 1); j++)
        {
            //check if empty
            if(grid[i][j] == 1)
            {
                left_found = true;
                bottom_found[j] = true;
                continue;
            }
            if(top_not_found[j])
            {
                continue;
            }
            //check in left
            bool found = false;
            if(!left_found)
            {
            for(int l = j - 1; l >= 0; l--)
            {
                if(grid[i][l] == 1)
                {
                    found = true;
                    left_found = true;
                    break;
                }
            }
            if(found == false)
            {
                continue;
            }
            }
            //check right
            found = false;
            for(int r = j + 1; r < N; r++)
            {
                 if(grid[i][r] == 1)
                {
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                break;
                //continue;
            }
            //check top
            found = false;
            for(int t = i - 1; t >= 0; t--)
            {
                 if(grid[t][j] == 1)
                {
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                top_not_found[j] = true;
                continue;
            }
            //check bottom
            if(bottom_found[j])
            {
                count++;
                continue;
            }
            found = false;
            
            for(int b = i + 1; b < N; b++)
            {
                 if(grid[b][j] == 1)
                {
                    found = true;
                    bottom_found[j] = true;
                    break;
                }
            }
            if(found)
            {
                //cout<<i<<" "<<j<<endl;
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
