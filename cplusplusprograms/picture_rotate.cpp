#include <iostream>

using namespace std;

#define N 5

void matrix(int arr[][N])
{
	int s = 0, t = N - 1;
	while(s <= t)
	{
		for(int i = 0; i < (t -s); i++)
		{
			int temp = arr[s][s + i];
			arr[s][s + i] = arr[s + i][t];
			arr[s + i][t] = arr[t][t - i];
			arr[t][t - i] = arr[t - i][s];
			arr[t - i][s] = temp;
		}
		s++;
		t--;
	}
}

void print_matrix(int arr[][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int arr[][N] = {{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}};
	cout<<"\n------ Original Matrix -------\n";	
	print_matrix(arr);
	matrix(arr);
	cout<<"\n------ 90 Degree Anti-Clockwise Rotated Matrix -------\n";	
	print_matrix(arr);
	return 0;
}
