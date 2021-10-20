#include<iostream>
using namespace std;
int main(void)
{
	int a,b,c=0,i;
	cin>>a>>b;
	if(a>b)
	{
		for(i=b;i<a;i++)
		{
			c = c+i;
		}
		cout<<c+a;
	}
	else if(b>a)
	{
		for(i=a;i<b;i++)
		{
			c = c+i;
		}
		cout<<c+b;
	}
	else
	{
		cout<<"87ㄟ\n兩數相等";
	}
	system("pause");
}
