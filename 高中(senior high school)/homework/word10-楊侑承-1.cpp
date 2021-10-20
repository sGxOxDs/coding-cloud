#include<iostream>
using namespace std;
int main(void)
{
	int i,b;int a[5];
	for(i=0;i<5;i++)cin>>a[i];
	cin>>b;
	for(i=0;i<5;i++)if(a[i]>b)cout<<a[i]<<"\t";
	system("pause");
}
