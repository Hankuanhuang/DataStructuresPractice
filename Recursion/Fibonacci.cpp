#include <iostream>
using namespace std;

int maxArray(int arr[], int index, int size)
{
	if (index == size - 1)
	{
		return arr[index];
	}

	int max = maxArray(arr, index + 1, size);

	if (arr[index] > max)
	{
		return arr[index];
	}
	return max;

}
