#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int c;
	string str;
	cin >> c;
	getline(cin, str);
	for (; c--;)
	{
		stack<char> sta;
		getline(cin, str);
		for (int i = 0; i < str.length(); i++)
		{
			/*if (str[i] == '(' || str[i] == '[')
			{
				sta.push(str[i]);
			}
			else*/ if (!sta.empty() && sta.top() == '[' && str[i] == ']')
			{
				sta.pop();
			}
			else if (!sta.empty() && sta.top() == '(' && str[i] == ')')
			{
				sta.pop();
			}
			else if (str[i] == ' ')
			{

			}
			else
			{
				sta.push(str[i]);
			}
		}
		if (sta.empty())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	return 0;
}