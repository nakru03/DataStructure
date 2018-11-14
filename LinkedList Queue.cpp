#include <iostream>

using namespace std;

class Node {
public:
	Node(int n);
	int data;
	Node* next;	
};

Node::Node(int n)
{
	data = n;
	next = NULL;	
}

class Queue {
private:
	Node* front;
	Node* rear;
	int length;
public:
	Queue();
	~Queue();

	void enQueue(int n);
	void deQueue();	
	void printQueue();
	int queueSize();
	int queueFront();
	int queueRear();
};
Queue::Queue()
{
	front = NULL;
	rear = NULL;
	length = 0;
	
} //생성자

Queue::~Queue()
{
	while (length > 0)
		deQueue();
}


void Queue::enQueue(int n)
{
	Node* newNode = new Node(n);
	if (length == 0)
	{
		front = newNode;
		rear = newNode;

	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
		
	length++;
}

void Queue::deQueue()
{
	Node* tmp;
	if (length == 0) {
		cout << "Queue is Empty" << endl;
		exit(1);
	}
	else
	{
		tmp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		length--;
	}
}
int Queue::queueSize() { return length; }

int Queue::queueFront()
{
	return front->data;
}

int Queue::queueRear()
{
	return rear->data;
}

void Queue::printQueue()
{
	Node* tmp = front;
	cout << "예약 현황: " << endl;
	while (true)
	{
		cout << tmp->data << endl;
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
}

int main()
{
	Queue q;
	cout << "=========항공권 예약 대기자 프로그램========="<<endl;
	cout << "1. 큐에 예약자 입력 : 숫자" << endl;
	cout << "2. 큐에서 예약자 삭제" << endl;
	cout << "3. 현재 예약 대기자 상황" << endl;
	cout << "4. 현재 예약 대기자 인원" << endl;
	cout << "5. 최우선 대기자" << endl;
	cout << "6. 마지막 대기자" << endl;
	cout << "0 종료" << endl;
	cout << "==============================================" << endl;
	while (true)
	{
		int n;
		cout << "실행할 명령 번호 : ";
		cin >> n;
		switch (n)
		{
		case 1 :
			int numb;
			cout << "대기자의 번호를 입력하시오";
			cin >> numb;
			q.enQueue(numb);
			break;
		case 2:
			q.deQueue();
			break;
		case 3:
			q.printQueue();
			break;
		case 4:
			cout << q.queueSize() << endl;
			break;
		case 5:
			cout << q.queueFront() << endl;
			break;
		case 6:
			cout << q.queueRear() << endl;
			break;
		case 0:
			exit(1);
			break;

		}

		
	}


}