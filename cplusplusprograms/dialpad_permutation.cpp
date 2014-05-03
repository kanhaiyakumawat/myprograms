#include <iostream>

using namespace std;

class Key
{
	public:
		void set(char* str, int len)
		{
			this->str = new char[len];
			int i = 0;
			while(i < len)
			{
				this->str[i] = str[i];
				i++;
			}
			this->len = len;
			current = 0;
		}
		char get_next()
		{
			if(current < len)
			{
			//	cout<<"current key is "<<str<<" returning : "<<str[current]<<endl;
				return str[current++];
			}
			throw '\0';
		}
		void reset()
		{
			current = 0;
		}
	private:
		int len;
		char *str;
		int current;
};

class DialPad
{
public:
  void permute (char *num, int len)
  {
    set_keys ();
    char *curr = new char[len];
    permute (num, curr, len, 0);
  }
private:
  Key keys[10];
  void set_keys ()
  {
    keys[0].set ("\0", 1);
    keys[1].set ("\0", 1);
    keys[2].set ("ABC\0", 4);
    keys[3].set ("DEF\0", 4);
    keys[4].set ("GHI\0", 4);
    keys[5].set ("JKL\0", 4);
    keys[6].set ("MNO\0", 4);
    keys[7].set ("PQRS\0", 5);
    keys[8].set ("TUV\0", 4);
    keys[9].set ("WXYZ\0", 5);
  }
  void permute (char *num, char *curr, int len, int curr_ind)
  {
    if (curr_ind == len)
      {
	cout << curr << endl;
	return;
      }
    char c;
    while (c = keys[num[curr_ind] - '0'].get_next (), c != '\0')
      {
	curr[curr_ind] = c;
	permute (num, curr, len, curr_ind + 1);
      }
    keys[num[curr_ind] - '0'].reset ();
  }
};

int
main ()
{
  DialPad dp;
  char *num = "234";
  dp.permute (num, 3);
  return 0;
}
