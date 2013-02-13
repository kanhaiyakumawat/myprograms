/*
Design an algorithm such that we have to find the k th element in the array such that their only prime factors are 3,5 an 7.
Example: Array will contain 1,3,5,7,9,21,25,...
We have to return the kth element in array...!!!
*/

#include <iostream>

using namespace std;

bool
is_factor_of_3_5_7 (const int a)
{
  int num = a;
  bool is_factor = false;
  while (num > 0 && num % 2 == 0)
    {
      num /= 2;
    }
  while (num > 0 && num % 3 == 0)
    {
      is_factor = true;
      num /= 3;
    }
  while (num > 0 && num % 5 == 0)
    {
      is_factor = true;
      num /= 5;
    }
  while (num > 0 && num % 7 == 0)
    {
      is_factor = true;
      num /= 7;
    }

  if (num > 1)
    {
      return false;
    }
  else
    {
      return is_factor;
    }
}

int
kthnumber (int arr[], int len, int k)
{
  int j = 0;
  int i = 0;
  while (i < len && j < k)
    {
      if (is_factor_of_3_5_7 (arr[i]))
	{
	  j++;
	}
      i++;
    }
  if (j == k)
    {
      cout << "found the kth element" << arr[i - 1] << endl;
    }
  else
    {
      cout << "could not find the kth element" << endl;
    }
}

int
main ()
{
  int arr[] = {
    1, 3, 5, 7, 9, 21, 25
  };
  kthnumber (arr, 7, 6);
  return 0;
}
