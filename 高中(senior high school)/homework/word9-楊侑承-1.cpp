#include<iostream>
using namespace std;
int xn(int,int);
int xn2(int,int);
int main(void)
{
	int x,n;
	cin>>x>>n;
	cout<<xn(x,n)<<endl;
	cout<<xn2(x,n)<<endl;
	system("pause");
}
int xn(int x,int n)
{
	int xall=1;
	for(int i=1;i<=n;i++){xall=xall*x;}
	return xall;
}
int xn2(int x,int n)
{
	if(n==1)return x;
	return x*xn2(x,n-1);
}
