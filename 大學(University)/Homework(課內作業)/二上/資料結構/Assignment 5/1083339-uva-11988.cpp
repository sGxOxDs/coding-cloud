#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	string s;
	for (; cin >> s;)
	{
		list<string> ls;
		string buffer;
		int homedown = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] != '[' && s[i] != ']' && s[i] != '\n')
				buffer.push_back(s[i]);
			else
			{
				if (homedown != 0)
					ls.push_front(buffer);
				else
					ls.push_back(buffer);
				if (s[i] == '[')
					homedown = 1;
				else if (s[i] == ']')
					homedown = 0;
				buffer.clear();
			}
		}
		if (homedown > 0)
			ls.push_front(buffer);
		else
			ls.push_back(buffer);
		buffer.clear();
		for (auto it=ls.begin();it!=ls.end();it++)
		{
			cout << *it;
		}
		cout << endl;
	}
}