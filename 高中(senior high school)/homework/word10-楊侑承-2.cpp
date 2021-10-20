#include<iostream>
using namespace std;
int main(void)
{
	int i,b,all=0;int a[5];
	for(i=0;i<5;i++)cin>>a[i];
	cin>>b;
	for(i=0;i<5;i++)if(a[i]>b)all=all+a[i];
	cout<<all;
	system("pause");
}
