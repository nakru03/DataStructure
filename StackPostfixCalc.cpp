/* 자료구조 과제
	2012011015 김상형
	스택을 이용한 후위표기법 계산기
	제출일 10/16
	제약 : int 형계산 가능, * + - / 사칙연산구현 스택사이즈 10000
*/

#include <iostream>
#include <string>

using namespace std;

const int MAXSIZE = 10000;

class Stack { //스택구현
private:
	char stack[MAXSIZE];
	int top;
public:
	Stack();
	void push(char elemet);	
	char pop();	
	void stackFull();
	void stackEmpty();
	int topcheck();
	int size();
	char peek();
	bool isEmpty();
};
Stack::Stack()
{
	top = -1;
}


void Stack::push(char element)
{
	if (top == MAXSIZE - 1)
		stackFull();
	stack[++top] = element;
}

void Stack::stackEmpty()
{
	cout << "-1" << endl;
	//exit(EXIT_FAILURE);
}

char Stack::pop()
{
	if (top<0)
		throw "stackEmpty()";
	return stack[top--];
}
void Stack::stackFull()
{
	cout << "stack is full" << endl;	
}
int Stack::size()
{
	return top + 1;
}
int Stack::topcheck()
{
	return top;
}
bool Stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}
char Stack::peek()
{
	return stack[top];
}


int precedence(char oper) //우선순위체크
{
	switch (oper)
	{
		case '(': return 0;
		case ')': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
	}
	return -1;
}
string translation(string str) //후위변환
{
	Stack postfixStack;
	char topV;
	string str2;
	for (int i = 0; i < str.length(); ++i)
	{
		switch (str[i])
		{
			case '+':
				while (!postfixStack.isEmpty() && precedence(postfixStack.peek()) >= precedence(str[i]))
				{
					str2.push_back(postfixStack.pop());
				}
				postfixStack.push(str[i]);
				break;

			case'-': 
				while (!postfixStack.isEmpty() && precedence(postfixStack.peek()) >= precedence(str[i]))
				{
					str2.push_back(postfixStack.pop());
				}
				postfixStack.push(str[i]);
				break;

			case'*': 
				while (!postfixStack.isEmpty() && precedence(postfixStack.peek()) >= precedence(str[i]))
				{
					str2.push_back(postfixStack.pop());
				}
				postfixStack.push(str[i]);
				break;

			case'/':
				while (!postfixStack.isEmpty() && precedence(postfixStack.peek()) >= precedence(str[i]))
				{
					str2.push_back(postfixStack.pop());
				}
				postfixStack.push(str[i]);
				break;

			case'(':
				postfixStack.push(str[i]);
				break;

			case')':
				topV = postfixStack.pop();
				while (topV != '(')
				{
					str2.push_back(topV);
					topV = postfixStack.pop();
				}
				break;

			default:
				str2.push_back(str[i]);
				break;
		}
	}
	while (!postfixStack.isEmpty())
	{
		str2.push_back(postfixStack.pop());
	}
	return str2;
}
int eval(string str) //계산
{
	int op1, op2;
	int tmp = 0;
	Stack calc;
	/*cout << str[0] - '0'<<endl;*/
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
		{
			tmp = str[i] - '0';
			calc.push(tmp);			
		}
		else
		{
			op1 = calc.pop();
			op2 = calc.pop();			
			switch (str[i])
			{
				case '+' : 					
					calc.push(op1 + op2);
					break;
				case '-':
					calc.push(op1 - op2);
					break;
				case '*':
					calc.push(op1 * op2);
					break;
				case'/':
					calc.push(op1 / op2);
			}
		}
		
	}
	return calc.pop();
}
int main()
{
	
	Stack st;	
	string str;
	string tmp;
	int tc;
	cout << "=======스택을 이용한 후위표기법 계산기=======" << endl;
	cout << "시행횟수 : " ;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cout << endl;
		cout << "연산식을 입력바랍니다: ";
		cin >> str;
		tmp = translation(str);
		cout << "후위표기법 변환결과 :" ;
		cout << tmp << endl;
		cout << "연산결과 : ";
		cout << eval("96+7+1+3+9+2+") << endl;
		cout << endl;
	}
		
	return 0;
}