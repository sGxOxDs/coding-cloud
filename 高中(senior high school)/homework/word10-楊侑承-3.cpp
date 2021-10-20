#include<iostream>
using namespace std;
int main(void)
{
	int i,j;int a[5];
	for(i=0;i<5;i++)cin>>a[i];
	for(i=0;i<5;i++)for(j=0;j<5;j++)if(a[i]<a[j]){int tmp=a[i];a[i]=a[j];a[j]=tmp;}
	for(i=0;i<5;i++)cout<<a[i]<<" ";
	system("pause");
}
