#include <iostream>
using namespace std;

int sumArray(int arr[], int index, int size)
{
	//Base Case
	if (index == size)
	{
		return 0;
	}

	//Recursive Case
	return arr[index] + sumArray(arr, index + 1, size);

}

int main()
{
	int arr[] = { 2, 4, 6, 8 };

	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Sum = " << sumArray(arr, 0, size) << endl;

	return 0;
}