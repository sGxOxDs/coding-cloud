#include<iostream>
using namespace std;

int main(void)
{
	int la,lb;
	cin>>la>>lb;
	if(la>lb)
	{
		cout<<"A好高"; 
	}
	else if(lb>la)
	{
		cout<<"B好高"; 
	}
	else
	{
		cout<<"半斤八兩"; 
	}
	system("pause");
} 
