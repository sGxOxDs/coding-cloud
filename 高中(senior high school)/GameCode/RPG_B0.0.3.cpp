#include <iostream>
using namespace std;

void xyshow(int,int,int);
void system_massage();
void xyskill(int,int,int,int,int);
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
		system("CLS");/*system������dos�t�ΤU���M�e�����O*/
		if(move==7 || move==9)
		{
			xyskill(n,x-1,y-1,move,sp);
			if(move==7 && sp>1){sp=sp-2;}
			else if(move=9 && sp>2){sp=sp-3;}
			else{cout<<"��O����"<<endl;}
		}
		else if(move==8 && y<=n-1 && sp>0){xyshow(n,x-1,y);y=y+1;sp=sp-1;}
		else if(move==4 && x>=2 && sp>0){xyshow(n,x-2,y-1);x=x-1;sp=sp-1;}
		else if(move==6 && x<=n-1 && sp>0){xyshow(n,x,y-1);x=x+1;sp=sp-1;}
		else if(move==2 && y>=2 && sp>0){xyshow(n,x-1,y-2);y=y-1;sp=sp-1;}
		else if(move==5 && sp_max>=sp){xyshow(n,x-1,y-1);if(sp_max>sp)sp=sp+1;}
		else if(sp==0){xyshow(n,x-1,y-1);cout<<"��O���� �Х�"<<endl;}
		else if(move==0){break;}
		else{xyshow(n,x-1,y-1);cout<<"again"<<endl;}
		cout<<"��O��: "<<sp<<"/ "<<sp_max<<endl;
		system_massage();cin>>move;
	}
	system("pause");
	return 0;
}
void xyshow(int n,int x,int y)
{                                         /*�i�令��L�Ϯ�*/ 
	int i,j;char xy[n][n];
	for(i=0;i<n;i++)for(j=0;j<n;j++)xy[i][j]='0';xy[x][y]='X';
	for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
}
void system_massage()
{
	cout<<"7=���\t9=�g��\n8=�V�W\t2=�V�U"<<endl;
	cout<<"4=�V��\t6=�V�k\n5=��\t0=����"<<endl;
}
void xyskill(int n,int x,int y,int move,int sp)
{
	int i,j,m=0;char xy[n][n];
	for(i=0;i<n;i++)for(j=0;j<n;j++)xy[i][j]='0';xy[x][y]='X';
	if(move==7 && sp>1)
	{
		while(true)
		{
			for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
			cout<<"�I��ޯ��V\n8=�V�W\t2=�V�U"<<endl;
			cout<<"4=�V��\t6=�V�k\n5=����"<<endl;cin>>m;
			if(m==5){cout<<"�����I��ޯ�\n��������O"<<endl;break;}
			else if(m==8){for(i=0;i<3;i++)if(y<n-1)xy[x-1+i][y+1]='=';break;}
			else if(m==6){for(i=0;i<3;i++)if(x<n-1 && y<n+1-i && y+i-1>=0)xy[x+1][y-1+i]='=';break;}
			else if(m==4){for(i=0;i<3;i++)if(x>0 && y<n+1-i && y+i-1>=0)xy[x-1][y-1+i]='=';break;}
			else if(m==2){for(i=0;i<3;i++)if(y>0)xy[x-1+i][y-1]='=';break;}
			else{cout<<"again"<<endl;cin>>m;}
		}
	}
	else if(move=9 && sp>2)
	{
		while(true)
		{
			for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
			cout<<"�I��ޯ��V\n8=�V�W\t2=�V�U"<<endl;
			cout<<"4=�V��\t6=�V�k\n5=����"<<endl;cin>>m;
			if(m==5){cout<<"�����I��ޯ�\n��������O"<<endl;break;}
			else if(m==8){for(i=1;i<n-y;i++)xy[x][y+i]='=';break;}
			else if(m==6){for(i=1;i<n-x;i++)xy[x+i][y]='=';break;}
			else if(m==4){for(i=1;i<=x;i++)xy[x-i][y]='=';break;}
			else if(m==2){for(i=1;i<=y;i++)xy[x][y-i]='=';break;}
			else{cout<<"again"<<endl;cin>>m;}
		}
	}
	for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
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
		2017.11.10 b0.0.3
			�a�Ϩt�Υi�ιϮ�
			�T���t���u��
			�C�������M�����e��� 
			�s�W�ޯ�t��
			�ѨM�Y�z�ޯ���ܪ�BUG
			�u����O�����P�_�� 
				 
*/ 
