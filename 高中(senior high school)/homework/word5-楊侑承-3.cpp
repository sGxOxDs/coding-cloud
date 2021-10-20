#include<iostream>
using namespace std;

int main(void)
{
	int c;
	cin>>c;
	if(c%4==0 && c%100!=0 || c%400==0)
	{
		cout<<"¶|¦~";
	}
	else
	{
		cout<<"«D¶|¦~";
	}
	system("pause");
}
