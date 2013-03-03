#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int MyCompare(const string  &X, const string &Y)
{
string XY = X;
XY.append(Y);
string YX = Y;
YX.append(X);

return XY.compare(YX) > 0? 1: 0;
}

int main()
{
vector<string> arr;
arr.push_back("12");
arr.push_back("352");
arr.push_back("353");
arr.push_back("35");
string num;
sort(arr.begin(), arr.end(), MyCompare);

for(int i  = 0; i < arr.size(); i++)
{
num.append(arr[i]);
}
cout<<"largest number is:"<<num<<endl;
return 0;
} 

