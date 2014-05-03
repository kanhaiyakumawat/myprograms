#include <iostream>

using namespace std;

class Key
{
public:
  void set (char *str, int len)
  {
    this->str = new char[len];
    int i = 0;
    while (i < len)
      {
	this->str[i] = str[i];
	i++;
      }
    this->len = len;
    current = 0;
  }

  char get_next ()
  {
    if (current < len)
      {
	//      cout<<"current key is "<<str<<" returning : "<<str[current]<<endl;
	return str[current++];
      }
    throw '\0';
  }

  void reset ()
  {
    current = 0;
  }

  int get_length ()
  {
    return len;
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
    int curr_ind = 0;
    int i = 0;
    int good_len = len;
    char *good_num = new char[len];
    while (curr_ind < len)
      {
	if (keys[num[curr_ind] - '0'].get_length () <= 1)
	  {
	    good_len--;
	  }
	else
	  {
	    good_num[i++] = num[curr_ind];
	  }
	curr_ind++;
      }
    char *curr = new char[len];
    permute (good_num, curr, good_len, 0);
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
  char *num = "01234567";
  dp.permute (num, 8);
  return 0;
}
