#include <iostream>

using namespace std;

int kadane(int array[], int len)
{
    int maxStart = -1;
    int maxEnd = -1;
    int maxSum = -99999999;
    int currentStart = 0;
    int currentEnd = 0;
    int currentSum = 0;
    
    for(currentEnd = currentStart; currentEnd < len; currentEnd++)
    {
        currentSum += array[currentEnd];
        if(currentSum < 0)
        {
            currentStart = currentEnd + 1;
            currentSum = 0;
        }
        else if(maxSum < currentSum)
        {
            maxStart = currentStart;
            maxEnd = currentEnd;
            maxSum = currentSum;
        }
    }
    cout<<"max sum is:"<<maxSum<<" in the range index "<<maxStart<<" and "<<maxEnd<<endl;
    return maxSum;
}

int main()
{
    int array[]={4,-1,-3, 10, -8, 9, -6};
    kadane(array, sizeof(array)/sizeof(array[0]));
    return 0;
}
