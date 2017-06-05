#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	char p;
	Queue<char> que(4);
	que.push('a');
	que.push('b');
	que.push('c');
	que.push('d');
	que.push('e');
	que.peek(p);
	que.pop();
	que.peek(p);
	que.pop();
	que.peek(p);
	que.pop();
	que.peek(p);
	que.pop();
	que.peek(p);
	que.pop();
	que.peek(p);
	que.pop();
	que.peek(p);
	que.pop();
	cout << p;
	return 0;
}