#include <iostream>
#include <string>
#include <map>

using namespace std;

char max_occuring_char(char *str)
{
	int len = char_traits<char>::length(str);
	std::map<char, int> my_map;
	int max_val = 0;
	char max_char = ' ';
	for(int i = 0; i < len; i++)
	{
		if(my_map.find(str[i]) == my_map.end())
		{
			my_map[str[i]] = 1;
			if(max_val == 0)
			{
				max_val = 1;
				max_char = str[i];
			}
		}
		else
		{
			int val = my_map.find(str[i])->second;
			my_map.find(str[i])->second = val + 1;
			if(max_val < (val + 1))
			{
				max_val = val + 1;
				max_char = str[i];
			}
		}
	}
	return max_char;
}

int main() {
	// your code goes here
	char input[] = "ababacbb";
	cout<<"max occuring character "<<max_occuring_char(input);
	return 0;
}
