#include <iostream>
using namespace std;

void xyshow(int,int,int);
void system_massage();
int main(void)
{
	int n,x,y,move,sp,sp_max;
	cout<<"��J�a�Ϥj�p:";cin>>n;
	do{cout<<"��J�_�l�y��(1~"<<n<<",1~"<<n<<"):";
	cin>>x>>y;cout<<"��O�ȤW��:";cin>>sp_max;}
	while(x<=0 && sp_max>0||x>=n+1 && sp_max>0||y<=0 && sp_max>0||y>=n+1 && sp_max>0);
	sp = sp_max;xyshow(n,x-1,y-1);cout<<"��O��: "<<sp<<"/ "<<sp_max<<endl;
	system_massage();cin>>move;
	while(move!=0)
	{
		if(move==8 && y<=n-1 && sp>0){xyshow(n,x-1,y);y=y+1;sp=sp-1;}
		else if(move==4 && x>=2 && sp>0){xyshow(n,x-2,y-1);x=x-1;sp=sp-1;}
		else if(move==6 && x<=n-1 && sp>0){xyshow(n,x,y-1);x=x+1;sp=sp-1;}
		else if(move==2 && y>=2 && sp>0){xyshow(n,x-1,y-2);y=y-1;sp=sp-1;}
		else if(move==8 && sp==0||move==4 && sp==0||move==6 && sp==0||move==2 && sp==0)
		{cout<<"��O���� �Х�"<<endl;}
		else if(move==5 && sp==sp_max){xyshow(n,x-1,y-1);}
		else if(move==5 && sp_max>sp){xyshow(n,x-1,y-1);sp=sp+1;}
		else if(move==0){break;}
		else{cout<<"again"<<endl;}
		cout<<"��O��: "<<sp<<"/ "<<sp_max<<endl;
		system_massage();cin>>move;
	}
	system("pause");
	return 0;
}
void xyshow(int n,int x,int y)
{                                         /*0 1�i�令��L�Ʀr(�Ϯ׫ݸѨM)*/ 
	int i,j,xy[n][n];for(i=0;i<n;i++)for(j=0;j<n;j++)xy[i][j]=0;xy[x][y]=1;
	for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
}
void system_massage()
{
	cout<<"8=�V�W\t2=�V�U"<<endl;
	cout<<"4=�V��\t6=�V�k"<<endl;
	cout<<"5=��\t0=����"<<endl;
}




/*
	�ؼ�RPG ��s��x:
		2017.11.09 b0.0.1
			�D�{���T��
			�a�ϫإ� ���ʨt�Ϋإ� 
			��for�令�Ƶ{��
		2017.11.10 b0.0.2
			�s�W��O�t��
			�s�W���ʴ��� 
				 
*/ 
