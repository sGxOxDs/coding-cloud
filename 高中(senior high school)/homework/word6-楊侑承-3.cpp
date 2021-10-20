#include<iostream>
using namespace std;
int main(void)
{
	int a,b,c,i;
	cin>>a>>b>>c;
	for(i=a;i<c;i=i+b-a)
	{
		cout<<i<<"\n";
	}
	system("pause");
}
