#include "StackType.h"

StackType::StackType()
{
	top = -1;
}

bool StackType::IsFull() const
{
	return (top >= MAX_ITEMS - 1);
}

bool StackType::IsEmpty() const
{
	return (top <= -1);
}

void StackType::Push(char item)
{
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = item;
}

void StackType::Pop()
{
	if (IsEmpty())
		throw EmptyStack();
	top--;
}

char StackType::Top()
{
	return items[top];
}