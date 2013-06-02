#include <iostream>
#include <string>

using namespace std;

bool is_valid(int a)
{
    return a >= 65 && a <= 90;
}

void interpret(int arr[], string str, int curr, int len)
{
    if(curr == len)
  {
		cout<<str<<endl;
	}
	else
	{
        for(int i = curr; i < len; )
		{
            str.push_back(char(arr[i] + 64));
			interpret(arr, str, i + 1, len);
			if(i < len - 1 && is_valid(10*arr[i] + arr[i + 1] + 64))
			{
                str.erase(str.size() - 1, 1);
                str.push_back(char(arr[i]*10 + arr[i + 1] + 64));
				interpret(arr, str, i + 2, len);
                i++;
            }
            i++;
		}
	}
    
}
			
		

int main()
{
	int arr[] = {1, 2, 3, 4};
	string str = "";
	interpret(arr, str, 0, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
