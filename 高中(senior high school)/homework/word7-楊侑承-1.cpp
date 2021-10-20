#include<iostream>
using namespace std;
int main(void)
{
	int i,j,x;
	cin>>x;
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=x;j++)
		{
			cout<<i<<"*"<<j<<"="<<i*j<<"\t";
		}
		cout<<endl;
	}
	system("pause");
}
