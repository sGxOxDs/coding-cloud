#include <iostream>
#include "StackType.h"
using namespace std;
//¹ïºÙ©ÊÀË´ú 1083339
#define testing case7

int main()
{
	string case1 = "(x)";
	string case2 = "(x{})";
	string case3 = "(x{ x[] })";
	string case4 = "(x[x)]";
	string case5 = "(x(x[]";
	string case6 = "(xx)]";
	string case7 = "(x(((((";
	StackType test;
	try
	{
		for (int i = 0; i < testing.size(); i++)
		{
			if (testing[i] == '(' || testing[i] == '[' || testing[i] == '{')
			{
				if (test.IsEmpty())
					test.Push(testing[i]);
				else
				{
					if (testing[i] == '(' && test.Top() == ')')
						test.Pop();
					else if (testing[i] == '[' && test.Top() == ']')
						test.Pop();
					else if (testing[i] == '{' && test.Top() == '}')
						test.Pop();
					else
						test.Push(testing[i]);
				}
			}
			else if (testing[i] == ')' || testing[i] == ']' || testing[i] == '}')
			{
				if (test.Top() == '(' && testing[i] == ')')
					test.Pop();
				else if (test.Top() == '[' && testing[i] == ']')
					test.Pop();
				else if (test.Top() == '{' && testing[i] == '}')
					test.Pop();
				else
					test.Push(testing[i]);
			}
		}
	}
	catch (FullStack& e)
	{
		cout << e.what() << endl;
	}
	catch (EmptyStack& e)
	{
		cout << e.what() << endl;
	}
	
	if (test.IsEmpty())
		cout << "Well formed" << endl;
	else
		cout << "Not well formed" << endl;

	return 0;
}