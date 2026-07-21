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

//---------------------------------------------------
//Creats an empty linked list.
//Initializes the head pointer to nullptr
//---------------------------------------------------
LinkedListStack::LinkedListStack()
{
	top = nullptr;
}

//---------------------------------------------------
//Release all nodes in the linked list.
//Prevents memory leaks.
//---------------------------------------------------
LinkedListStack::~LinkedListStack()
{
	while (top != nullptr)
	{
		Node* temp = top;
		top = top->next;
		delete temp;
	}

}

//---------------------------------------------------
//Adds a new element to the top of the stack.
//Create a new node and updates the top pointer.
//---------------------------------------------------
void LinkedListStack::push(int value)
{
	Node* newNode = new Node;

	newNode->data = value;
	newNode->next = top;

	top = newNode;
}

//---------------------------------------------------
//Remove the top element from the stack.
//Delete the top node and updates the top pointer.
//---------------------------------------------------
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

//---------------------------------------------------
//Return the top element without removing it.
//Return -1 if the stack is empty.
//---------------------------------------------------
int LinkedListStack::peek()
{
	if (isEmpty())
	{
		return -1;
	}

	return top->data;
}

//---------------------------------------------------
//Checks whether the stack is empty.
//Returns true if the top pointer is nullptr.
//---------------------------------------------------
bool LinkedListStack::isEmpty() const
{
	return top == nullptr;
}

//---------------------------------------------------
//Prints all element from top to bottom.
//Traverses the linked list until nullptr.
//---------------------------------------------------
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
