#include <iostream>
using namespace std;

class ArrayStack {

private:
	int* data;
	int capacity;
	int used;

public:
	// Constructor / Destructor
	ArrayStack();
	~ArrayStack();

	// Stack Operations
	void push(int value);
	void pop();
	int top();

	// Helper Functions
	bool isEmpty() const;
	void grow();

	//Testing
	void print();
};

ArrayStack::ArrayStack() 
{
	capacity = 6;
	used = 0;
	data = new int[capacity];
}

ArrayStack::~ArrayStack()
{
	delete[] data;
}

void ArrayStack::push(int value) 
{
	if (used == capacity) 
	{
		grow();
	}
	data[used] = value;
	used++;
}

void ArrayStack::pop()
{
	if (isEmpty()) 
	{
		return;
	}
	used--;
}

int ArrayStack::top()
{
	if (isEmpty())
	{
		return -1;
	}

	return data[used - 1];

}

bool ArrayStack::isEmpty() const
{
	return used == 0;
}

void ArrayStack::grow()
{
	// Double the capacity
	int newCapacity = capacity * 2;

	// Create a new large arry
	int* newData = new int[newCapacity];

	for (int i = 0; i < used; i++) 
	{
		newData[i] = data[i];
	}

	// Delete the old array
	delete[] data;

	// Point data to the new arry
	data = newData;

	// Update capcaity
	capacity = newCapacity;
}

void ArrayStack::print()
{
	cout << "Stack: ";

	for (int i = 0; i < used; i++)
	{
		cout << data[i] << " ";
	}

	cout << endl;
}

int main()
{
	ArrayStack s;

	cout << "Original Stack:" << endl;
	s.print();

	s.push(10);
	s.push(20);
	s.push(30);

	cout << "\nAfter push 3 times:" << endl;
	s.print();

	cout << "Top: " << s.top() << endl;

	s.pop();
	cout << endl;
	s.print();

	cout << "Top: " << s.top() << endl;

	return 0;
}