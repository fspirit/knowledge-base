#include "../node.h"

class Stack
{
	Stack() : top(nullptr) {};
	Node * top;

	int Pop()
	{
		if (top != nullptr)
		{
			int value = top->value;
			top = top->next;
			return value;
		}
		return 0;
	}

	void Push(int value)
	{
		Node * t = new Node(value);
		t.next = top;
		top = t;
	}

	int Top()
	{
		if (top != nullptr)
		{
			return top->value;
		}
		return 0;
	}
}