#include <iostream>
using namespace std;

int power(int base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	return base * power(base, exponent - 1);
}

int main() 
{
	cout << power(2, 5) << endl; //32
	cout << power(3, 4) << endl; //81
	cout << power(5, 0) << endl; //1
	cout << power(10, 2) << endl; //100

	return 0;

}