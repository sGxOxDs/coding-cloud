#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
int STR=0,DEX=0,CON=0,IQ=0,WIS=0,CHA=0;
/*力量,敏捷,體質,智力,感知,魅力*/ 
int FD6H3(int a)
{
	srand(time(NULL)+a);int R[4],i,j,Attri[6];
	for(i=0;i<4;i++)R[i]=rand()%6+1;
	for(i=0;i<4;i++)for(j=0;j<4;j++)if(R[i]>R[j])
	{int tmp=R[i];R[i]=R[j];R[j]=tmp;}
	return R[0]+R[1]+R[2];
}
int main()
{
	int i,j,Attri[6];
	for(i=0;i<6;i++)Attri[i]=FD6H3(i);
	for(i=0;i<6;i++)cout<<Attri[i]<<" ";
	STR=Attri[0];DEX=Attri[1];CON=Attri[2];
	IQ=Attri[3];WIS=Attri[4];CHA=Attri[5];
	system("pause");
}





/*
	目標 DnD 更新日誌:
        2017.11.19 b0.0.1 
        	
*/ 
