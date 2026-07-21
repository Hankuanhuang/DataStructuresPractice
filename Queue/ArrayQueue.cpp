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

ArrayQueue::ArrayQueue()
{
	capacity = 10;
	used = 0;
	front = 0;
	data = new int[capacity];
}

ArrayQueue::~ArrayQueue()
{
	delete[] data;
}

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

void ArrayQueue::dequeue()
{
	if (isEmpty())
	{
		return;
	}
	front++;
	used--;
}

int ArrayQueue::peekfront()
{
	if (isEmpty())
	{
		return -1;
	}
	return data[front];
}

bool ArrayQueue::isEmpty() const
{
	return used == 0;
}

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