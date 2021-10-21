#include <iostream>
#include <queue>

using namespace std;

struct Register
{
	friend bool operator<(const Register &left, const Register &right);
	int id;
	int time;
	int c_time;
};
bool operator<(const Register& left, const Register& right)
{
	if (left.time > right.time)
		return true;
	else if (left.time < right.time)
		return false;
	else
	{
		if (left.id > right.id)
			return true;
		else
			return false;
	}
}
int main()
{
	string s;
	priority_queue<Register> Rpq;
	for (; cin >> s;)
	{
		if (s == "#")
			break;
		Register temp_R;
		cin >> temp_R.id;
		cin >> temp_R.time;
		temp_R.c_time = temp_R.time;
		Rpq.push(temp_R);
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << Rpq.top().id << endl;
		Register temp_R;
		temp_R = Rpq.top();
		temp_R.time += temp_R.c_time;
		Rpq.push(temp_R);
		Rpq.pop();
	}
}