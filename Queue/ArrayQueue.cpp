#include <iostream>
using namespace std;

class ArrayQueue
{
private:
	int* data;
	int capacity;
	int used;
	int front;

public:
	// Constructor / Destructor
	ArrayQueue();
	~ArrayQueue();

	//Queue Operations
	void enqueue(int value);
	void dequeue();
	int peekfront();

	// Helper Functions
	bool isEmpty() const;
	void grow();

	void print();
};

//-------------------------------------
//Consturctor
//Initial the queue with:
//-capacity = 10
//-used = 0(queue is empty)
//-front = 0(first element index)
//Allocate dynamic memory for the array
ArrayQueue::ArrayQueue()
{
	capacity = 10;
	used = 0;
	front = 0;
	data = new int[capacity];
}

//-------------------------------------
//Destructor
//Free the dynamically allocated memory
//to prevent memroy leaks.
ArrayQueue::~ArrayQueue()
{
	delete[] data;
}

//-------------------------------------
//enqueue()
//Add a new value to the back of the queue.
//if the array is full, grow the capacity first.
//Store the new value, then increase used.
void ArrayQueue::enqueue(int value)
{
	if (used == capacity)
	{
		grow();
	}

	int back = front + used;
	data[back] = value;
	used++;
}

//-------------------------------------
//Dequeue()
//Remove the front element from the queue.
//if the queue is empty, do nothing.
//Move front forward and decrease used.
void ArrayQueue::dequeue()
{
	if (isEmpty())
	{
		return;
	}
	front++;
	used--;
}

//-------------------------------------
//Peekfront()
//Return the value at the front of the queue.
// If the queue is empty.
//return -1.
int ArrayQueue::peekfront()
{
	if (isEmpty())
	{
		return -1;
	}
	return data[front];
}

//-------------------------------------
//isEmpty()
//Return true if the queue has no elements.
//Otherwise return false.
bool ArrayQueue::isEmpty() const
{
	return used == 0;
}

//-------------------------------------
// grow()
// Double the array capacity.
//
// Create a new array with double size.
// Copy all queue elements to the new array,
// starting from index 0.
// Delete the old array,
// update data pointer,
// reset front to 0.
void ArrayQueue::grow()
{
	int newCapacity = capacity * 2;
	int* newData = new int[newCapacity];

	for (int i = 0; i < used; i++)
	{
		newData[i] = data[front + i];
	}
	delete[] data;

	data = newData;
	capacity = newCapacity;
	front = 0;

}

void ArrayQueue::print()
{
	cout << "Queue: ";

	for (int i = 0; i < used; i++)
	{
		cout << data[front + i] << " ";
	}
	cout << endl;
}

int main()
{
	ArrayQueue q;

	cout << "Original Queue" << endl;
		q.print();

		q.enqueue(10);
		q.enqueue(20);
		q.enqueue(30);

		cout << "After enqueue 10, 20, 30" << endl;
		q.print();

		cout << "Peek front: " << q.peekfront() << endl;

		q.dequeue();
		cout << endl;

		q.print();

		cout << "Peek front: " << q.peekfront() << endl;
		return 0;
}
