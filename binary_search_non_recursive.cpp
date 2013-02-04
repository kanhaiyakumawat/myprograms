#include <iostream>

using namespace std;

int binary_search (int array[], int left, int right, int key)
{
  int mid = -1;
  while (left < right)
    {
      mid = (left + right) / 2;
      if (array[mid] == key)
        {
          return mid;
        }
      else if (array[mid] < key)
        {
          right = mid - 1;
        }
      else
        {
          left = mid + 1;
        }
    }
  return -1;
}

int main ()
{
  int array[] = { 1, 2, 3, 6, 7, 9 };

  int ans = binary_search (array, 0, 5, 10);

  ans >
    0 ? cout << "found the key at index " << ans << endl : cout <<
    "Key doesn't exist" << endl;
  return 0;
}
