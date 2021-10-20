#include<iostream>
using namespace std;

int main(void)
{
	int l,w;
	cin>>l>>w;
	if(l>150)
	{
		cout<<"你好高"; 
	}
	else if(120>l)
	{
		cout<<"你好矮"; 
	}
	else
	{
		cout<<"剛剛好";
	}
	if(w>70)
	{
		cout<<"你好重"; 
	}
	else if(50>l)
	{
		cout<<"你好輕"; 
	}
	else
	{
		cout<<"你身材好";
	}
	system("pause");
} 
