#include<iostream>
using namespace std;

int main(void)
{
	float l,w,bmi;
	cin>>l>>w;
	bmi = w/(l/100*l/100);cout<<bmi; 
	if(bmi>=25.5)
	{
		cout<<"­D"; 
	}
	else if(17.5>=bmi)
	{
		cout<<"½G"; 
	}
	else
	{
		cout<<"­è­è¦n"; 
	}
	system("pause");
} 
