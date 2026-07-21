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

ArrayStack::ArrayStack() //Create an empty stack and allocates memory for the array.
{
	//Initial stack capacity
	capacity = 6;

	//No elements in the stack yet
	used = 0;

	//Allocate memory for the dynamic array
	data = new int[capacity];
}

ArrayStack::~ArrayStack()  //Adds a new element to the top of the stack.
{
	//Release dynamically allocated memory
	delete[] data;
}

void ArrayStack::push(int value) 
{
	//Expand the array if it is full
	if (used == capacity) 
	{
		grow();
	}
	//Insert the new value at the next available position
	data[used] = value;

	//Increase the number of the stored elemeents
	used++;
}

void ArrayStack::pop()
{
	//Do nothing if the stack is empty
	if (isEmpty()) 
	{
		return;
	}

	//Remove the top element
	used--;
}

int ArrayStack::top()
{
	//Return -1 if the stack is empty
	if (isEmpty())
	{
		return -1;
	}

	//Return the top element
	return data[used - 1];

}

bool ArrayStack::isEmpty() const //Checks whether the stack contains any elements
{
	//The stack is empty when no elements are stored
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
