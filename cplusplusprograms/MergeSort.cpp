#include <iostream>

using namespace std;
template<typename T>
void merge_sort(T arr[], int start, int end)
{
	if((end - start) < 1)
	{
		return;
	}
	int mid = (start + end)/2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);

	T *copy_arr = new T(end - start + 1);
	for(int i = start; i <= end; i++)
	{
		copy_arr[i - start] = arr[i];
	}

	int i = 0;
	int j = mid - start + 1;
	int k = start;
	while(i <= (mid - start) && j <= (end - start))
	{
		if(copy_arr[i] <= copy_arr[j])
		{
			arr[k++] = copy_arr[i++];
		}
		else
		{
			arr[k++] = copy_arr[j++];
		}
	}
	while(i <= (mid - start))
	{
		arr[k++] = copy_arr[i++];
	}
	while(j <= (end - start))
	{
		arr[k++] = copy_arr[j++];
	}
	delete copy_arr;
}
void print_arr(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int arr[] = {2,6,9,1,7,4,10};
	print_arr(arr, sizeof(arr)/sizeof(arr[0]));
	merge_sort<int>(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	print_arr(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
