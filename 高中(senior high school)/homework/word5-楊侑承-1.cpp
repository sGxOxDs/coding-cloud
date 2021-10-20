#include<iostream>
using namespace std;

int main(void)
{
	float m;
	cin>>m;
	if(m>=10000)
	{
		m = m*0.55;
	}
	else if(m>=5000)
	{
		m = m*0.6; 
	}
	else if(m>=2000)
	{
		m = m*0.7;
	}
	cout<<"¹ê¥I"<<m; 
	system("pause");
} 
