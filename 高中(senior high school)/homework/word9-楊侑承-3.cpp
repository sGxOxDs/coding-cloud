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
	if(n==0)return 0;
	return n%10+nall((n-n%10)/10);
}
