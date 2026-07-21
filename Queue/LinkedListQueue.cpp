#include <iostream>
using namespace std;

class LinkedListQueue
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* front;
	Node* back;

public:
	// Constructor / Destructor
	LinkedListQueue();
	~LinkedListQueue();

	//Queue Operations
	void enqueue(int value);
	void dequeue();
	int peekfront();

	// Helper Functions
	bool isEmpty() const;

	//Testing
	void print();
};

LinkedListQueue::LinkedListQueue()
{
	front = nullptr;
	back = nullptr;
}

LinkedListQueue::~LinkedListQueue()
{
	while (front != nullptr) {
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	back = nullptr;
}

void LinkedListQueue::enqueue(int value)
{

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (isEmpty())
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back->next = newNode;
		back = newNode;
	}

}

void LinkedListQueue::dequeue()
{
	if (isEmpty())
	{
		return;
	}

	Node* temp = front;
	front = front->next;
	delete temp;

	if (front == nullptr)
	{
		back = nullptr;
	}
	
}

int LinkedListQueue::peekfront()
{
	if (isEmpty())
	{
		return -1;
	}
	return front->data;
}

void LinkedListQueue::print()
{
	Node* current = front;

	cout << "Queue: ";

	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}