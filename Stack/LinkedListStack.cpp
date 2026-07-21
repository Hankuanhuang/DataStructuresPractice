#include <iostream>
using namespace std;

class LinkedListStack
{
private:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* top;

public:
	//Construtor / Destructor
	LinkedListStack();
	~LinkedListStack();

	//Stack Operations
	void push(int value);
	void pop();
	int peek();

	//Helper functions
	bool isEmpty() const;

	//Testing
	void print();

};

LinkedListStack::LinkedListStack()
{
	top = nullptr;
}

LinkedListStack::~LinkedListStack()
{
	while (top != nullptr)
	{
		Node* temp = top;
		top = top->next;
		delete temp;
	}

}

void LinkedListStack::push(int value)
{
	Node* newNode = new Node;

	newNode->data = value;
	newNode->next = top;

	top = newNode;
}

void LinkedListStack::pop()
{
	if (isEmpty())
	{
		return;
	}

	Node* temp = top;
	top = top->next;
	delete temp;
}

int LinkedListStack::peek()
{
	if (isEmpty())
	{
		return -1;
	}

	return top->data;
}

bool LinkedListStack::isEmpty() const
{
	return top == nullptr;
}



void LinkedListStack::print()
{
	Node* current = top;
	
	cout << "Stack: ";

	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main()
{
	LinkedListStack s;

	cout << "Original Stack:" << endl;
	s.print();

	s.push(10);
	s.push(20);
	s.push(30);

	cout << "\nAfter push 10, 20, 30:" << endl;
	s.print();

	cout << "Peek: " << s.peek() << endl;

	s.pop();

	cout << "\nAfter pop:" << endl;
	s.print();

	cout << "Peek: " << s.peek() << endl;

	return 0;
}