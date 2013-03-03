#include <iostream>
using namespace std;
const int N = 4;
bool
sorted_matrix_search (int arr[][N], int M, int K)
{
  int i = 0;
  int j = N - 1;
  while (i < M && j >= 0)
    {
      if (arr[i][j] == K)
	{
	  cout << "found the element at: " << i << ", " << j << endl;
	  return true;
	}
      else if (arr[i][j] < K)
	{
	  i++;
	}
      else
	{
	  j--;
	}
    }
  cout << "not found" << endl;
  return false;
}

int
main ()
{
  int arr[][4] = { {10, 20, 30, 40},
  {15, 25, 35, 45},
  {27, 29, 37, 48},
  {32, 33, 39, 50},
  {32, 33, 39, 51},
  };
  sorted_matrix_search (arr, 5, 51);
  return 0;
}
