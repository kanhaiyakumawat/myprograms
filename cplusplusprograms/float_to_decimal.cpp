#include <iostream>
#include <string>

using namespace std;

string integer_to_binary(const int num)
{
string binary;
int curr = num;

while(curr)
{
binary+=curr%2;
curr/=2;
}
return binary;
}

int main()
{
cout<<"binary is: "<<integer_to_binary(50)<<endl;
return 0;
}

