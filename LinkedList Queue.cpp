#include <iostream>

using namespace std;

class Node {
	Node(int n);
	int data;
	Node* next;
	Node* prev;
};

Node::Node(int n)
{
	data = n;
	next = NULL;
	prev = NULL;
}

class Queue {
private:
	Node* front;
	Node* rear;
	int size;
public:
	Queue();
	void enQueue(int n);
	void deQueue();
	void printQueue();
	int queueSize();
};
Queue::Queue()
{
	front = NULL;
	rear = NULL;
	size = 0;
} //생성자

void Queue::enQueue(int n)
{
	Node* newNode = new Node(n);
	if (size == 0)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		front = 
	}
}

int main()
{
	return 0;
}