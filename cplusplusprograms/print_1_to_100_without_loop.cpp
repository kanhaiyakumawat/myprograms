#include <iostream>
using namespace std;

class Test
{
	public:
		Test()
		{
			static int i = 1;
			cout<<i++<<endl;
		}
};

int main() {
	// your code goes here
	Test t[100];
	return 0;
}
