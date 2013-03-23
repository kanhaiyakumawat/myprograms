#include <iostream>

using namespace std;
const int N = 4;
void
print_matrix_diagonally (int arr[][N], int M)
{
  int SR = 0;			//Start Row
  int SC = N - 1;

  while (SC >= 0)
    {
      int i;
      int j;
      for (i = SR, j = SC; i < M && j < N; i++, j++)
	{
	  cout << arr[i][j] << " ";
	}
      cout << endl;
      SC--;
    }

  SR = 1;
  SC = 0;

  while (SR < M && SC < N)
    {
      int i;
      int j;
      for (i = SR, j = SC; i < M && j < N; i++, j++)
	{
	  cout << arr[i][j] << " ";
	}
      cout << endl;
      SR++;
    }

  return;
}

int
main ()
{
  int arr[5][4] = { {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16},
  {17, 18, 19, 20}
  };

  print_matrix_diagonally (arr, 5);
  return 0;
}
