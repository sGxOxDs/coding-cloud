#include<iostream>
using namespace std;
int main(void)
{
	int i,j,a,b,n=0;
	cin>>a>>b;
	for(i=1;i<=a;i++)
	{
		if(a%i==0)
		{
			for(j=1;j<=b;j++)
			{
				if(j==i && b%j==0)
				{
					cout<<j;
					cout<<" ";
					n=n+1;
				}
			}
		}
	}
	if(n==1)
	{
		cout<<"\n¨â¼Æ¤¬½è\n";
	}
	system("pause");
}
