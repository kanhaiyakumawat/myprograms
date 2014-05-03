#include <iostream>

using namespace std;

void
maximum_repeating_number (int arr[], int M, int K)
{
  for (int i = 0; i < M; i++)
    {
      if (arr[i] > (2 * M * K))
	{
	  cout << "INVALID DATA IN THE ARRAY" << endl;
	  return;
	}
      else if (arr[i] == i)
	{
	  arr[i] += (M * K + i);
	}
      else if (arr[i] >= (M * K))
	{
	  continue;
	}
      else
	{
	  do
	    {
	      if (arr[arr[i]] == arr[i])
		{
		  arr[arr[i]] += (M * K + arr[i]);
		  arr[i] = -1;
		}
	      else if (arr[arr[i]] >= (M * K))
		{
		  arr[arr[i]] += i;
		  arr[i] = -1;
		}
	      else
		{
		  int temp = arr[arr[i]];
		  arr[arr[i]] = arr[i] + M * K;
		  arr[i] = temp;
		}
	    }
	  while (arr[i] != -1 && arr[i] != i);
	  if (arr[i] != -1)
	    {
	      arr[i] += (M * K + i);
	    }
	}
    }
  int max = 0;
  int index = 0;
  for (int i = 1; i < M; i++)
    {
      if (arr[i] > (M * K))
	{
	  arr[i] -= (M * K);
	  if (max < (arr[i] / i))
	    {
	      max = arr[i] / i;
	      index = i;
	    }
	}
    }
  cout << "number " << index << " occurred max " << max << endl;
}

int
main ()
{
  int arr[] = { 4, 5, 6, 1, 7, 8, 5, 6, 6, 7 };
  maximum_repeating_number (arr, 10, 8);
  return 0;
}
