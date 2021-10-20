#include<iostream>
using namespace std;
int main(void)
{
	int a,b,i,j,x,y,ai,bj;
	cin>>a>>b;if(b>a){int tmp;tmp=a;a=b;b=tmp;}
	ai=a;bj=b;y=ai*bj;
	while(a>0&&b>=0)
	{
		if(b==0){x=a;break;}
		else{int tmp=b;b=a%b;a=tmp;}
	}
	for(i=1;i<y;i++)for(j=1;j<y;j++)if(ai*i==bj*j)if(y>bj*j)y=bj*j;
	cout<<x<<endl<<y<<endl;
	system("pause");
}
