#include <iostream>
 
using namespace std;
int squares(int rows, int columns)
{
    int squares = 0;
    int counter = rows < columns? rows:columns;
    while(--counter>=0)
    {
        squares += (rows - counter)*(columns - counter);
    }
    return squares;
}
int main() {
    int rows = 3;
    int columns = 2;
    cout<<"max squares:"<<squares(rows,columns)<<endl;
        return 0;
}
