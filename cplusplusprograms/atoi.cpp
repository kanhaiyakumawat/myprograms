#include <iostream>
#include <string>

using namespace std;

int
atoi (string str)
{
  bool is_negative = false;
  int num = 0;

  if (str.length () <= 0)
    {
      throw;
    }

  if (str[0] == '-')
    {
      is_negative = true;
    }
  else
    {
      if (str[0] >= '0' && str[0] <= '9')
	{
	  num = str[0] - '0';
	}
      else
	{
	  throw;
	}
    }

  for (int i = 0; i < str.length (); i++)
    {
      if (str[0] >= '0' && str[0] <= '9')
	{
	  num = num * 10 + (str[i] - '0');
	}
      else
	{
	  throw;
	}
    }

  return is_negative ? num * (-1) : num;
}

int
main ()
{
  cout << "integer is:" << atoi ("a1234") << endl;
  return 0;
}
