#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;


int main()
{
	string temp;
	for (; getline(cin,temp);)
	{
		map<string, string> m;
		stringstream ss(temp);
		string val,key;
		ss >> val >> key;
		m[key] = val;
		for (; getline(cin, temp) && temp != ""; )
		{
			stringstream ss(temp);
			ss >> val >> key;
			m[key] = val;
		}
		for (; getline(cin, temp) && temp != "";)
		{
			if (m[temp] == "")
				cout << "eh" << endl;
			else
				cout << m[temp] << endl;
		}
	}
	return 0;

}