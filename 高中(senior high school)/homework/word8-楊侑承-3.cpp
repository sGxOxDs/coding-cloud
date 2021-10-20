#include<iostream>
using namespace std;
int main(void)
{
	int i,j,a,b,all=0;
	for(a=1;a<=10000;a++)
	{
		all=0;
		for(i=1;i<=10000;i++)
		{
			if(a%i==0)
			{
				all=all+i;
			}
		}
		all=all-a;
		if(all==a)
		cout<<a<<" 是完全數"<<endl;
	}
	system("pause");
}
