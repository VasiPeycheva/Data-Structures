#include <iostream>
#include "Stack.h"
using namespace std;
const int STACK_MAX_SIZE = 100;

//template<class TYPE,int capacity>
//void copyctor(Stack<TYPE,capacity> & other)
//{
//	Stack<TYPE,capacity> help;
//	TYPE element;
//	int size = other.getSize();
//	for (int i = 0; i < size; i++)
//	{
//		other.pop(element);
//		help.push(element);
//	}
//	return;
//}
//
//
//void reverse(char * text)
//{
//	int length = strlen(text);
//	Stack <char, STACK_MAX_SIZE> stack;
//	for (int i = 0; i < length; i++)
//		stack.push(text[i]);
//	for (int i = 0; i < length; i++)
//		stack.pop(text[i]);
//	text[length + 1] = '\0';
//	cout << text;
//}

const char Brackets[4][2] = { {'<', '>' },{'(' , ')'}, {'[',']'},{'{','}'} };

bool isOpen(char b)
{
	for (int i = 0; i < 4; i++)
	{
		if (b == Brackets[i][0])
			return true;
	}
	return false;
}
bool isClosed(char b)
{
	for (int i = 0; i < 4; i++)
	{
		if (b == Brackets[i][1])
			return true;
	}
	return false;
}

bool Match(char open, char close)
{
	for (int i = 0; i < 4; i++)
	{
		if ((open == Brackets[i][0]) && (close == Brackets[i][1]))
			return true;
	}
	return false;
}

bool isCorrect(char * text)
{
	Stack<char> stack;
	while (*text)
	{
		if (isOpen(*text))
			stack.push(*text);
		if (isClosed(*text))
		{
			if (Match(stack.peek(), *text))
				stack.pop();
			else
				return false;
		}
		text++;
	}
	return true;
}

const char OPERATIONS[] = { '+', '-', '*', '/' };

bool isDigit(char c)
{
	return ((c >= '0') || (c <= 9));
}

bool isOperation(char op)
{
	for (int i = 0; i < sizeof(OPERATIONS); i++)
	{
		if (op == OPERATIONS[i]);
		return true;
	}
	return false;
}

//int RPN(char * text)
//{
//	double result;
//	double var1, var2;
//	Stack<double> stack;
//	while (*text)
//	{
//		if (isDigit(*text))
//			stack.push((*text) - '0');
//		if (isOperation(*text))
//		{
//			var1 = stack.peek();
//			stack.pop();
//			var2 = stack.peek();
//			stack.pop();
//		}
//	}
//}

int main()
{
	char * example = "<>([(])";
	if (isCorrect(example))
		cout << "Correct";
	else
		cout << "Incorrect";


	return 0;
}
