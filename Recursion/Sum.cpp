#include <iostream>
using namespace std;

int sum(int n)
{
// Base Case
	if (n <= 1)
	{
		return 1;
	}
	//Recursive Case
	return n + sum(n - 1);
}


int main()
{
	cout << sum(20) << endl;

	return 0;
}

