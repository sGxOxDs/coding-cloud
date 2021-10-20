#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void Boss1();
int main(void)
{
	int a;
	while(true)
	{
		cin>>a;if(a==0){break;}
		else if(a==1){Boss1();}
	}
	system("pause");
}
void Boss1()
{
	void Boss1_map(int,int,int,int);
	system("CLS");
	int px=2,py=8,bx=15,by=8;char move;
	Boss1_map(px,py,bx,by);
	while(true)
	{
		cin>>move;system("CLS");
		if(move=='0'){break;}
		else if(move=='w'&&py<19){py=py+1;Boss1_map(px,py,bx,by);}
		else if(move=='s'&&py>0){py=py-1;Boss1_map(px,py,bx,by);}
		else if(move=='a'&&px>0){px=px-1;Boss1_map(px,py,bx,by);}
		else if(move=='d'&&px<19){px=px+1;Boss1_map(px,py,bx,by);}
		else if(move=='1'){}
		else if(move=='2'){}
		else if(move=='3'){}
		else{Boss1_map(px,py,bx,by);}
	}
}
void Boss1_map(int px,int py,int bx,int by)
	{
		int n=17,i,j;char xy[n][n];
		for(i=0;i<n;i++)for(j=n-1;j>=0;j--)xy[i][j]='\0';
		xy[bx][by]='B';xy[px][py]='0';
		
		
		for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
	}





/*
	目標BOSS戰 更新日誌:
        2017.11.16 b0.0.1 
        	
*/ 
