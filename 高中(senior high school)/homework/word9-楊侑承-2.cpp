#include<iostream>
using namespace std;
int nall(int);
int main(void)
{
	int n;
	cin>>n;
	cout<<nall(n)<<endl;
	system("pause");
}
int nall(int n)
{
	if(n==1)return 1;
	return n*nall(n-1);
}
