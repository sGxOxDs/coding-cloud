#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int sc=0,n,sp,sp_max,xg,yg,R,stop=0;

void xyshow(int,int,int);
void system_massage();
int main(void)
{
	int x,y,move;float score,sx,sy,sm=0;
	do{cout<<"��J�a�Ϥj�p:";cin>>n;}while(n<=1);
	do{cout<<"��J�_�l�y��(1~"<<n<<",1~"<<n<<"):";cin>>x>>y;}
	while(x<=0 || x>=n+1 || y<=0 || y>=n+1);
	do{cout<<"��J�����_�l�y��(1~"<<n<<",1~"<<n<<"):";cin>>xg>>yg;}
	while(xg<=0 || xg>=n+1 || yg<=0 || yg>=n+1 ||xg==x && yg==y);
	do{cout<<"��O�ȤW��:";cin>>sp_max;}while(sp_max<=0);
	sp = sp_max;xyshow(x-1,y-1,0);cout<<"��O��: "<<sp<<"/ "<<sp_max<<endl;
	system_massage();cin>>move;
	if(x>=xg){sx=x-xg;}else if(xg>x){sx=xg-x;}
	if(y>=yg){sy=y-yg;}else if(yg>y){sy=yg-y;}
	while(move!=0 && sc!=999)
	{
		system("CLS");/*system������dos�t�ΤU���M�e�����O*/
		if(move==7 && sp>1 || move==9 && sp>2){xyshow(x-1,y-1,move);}
		else if(move==8 && y<=n-1 && sp>0){xyshow(x-1,y,move);y=y+1;}
		else if(move==4 && x>=2 && sp>0){xyshow(x-2,y-1,move);x=x-1;}
		else if(move==6 && x<=n-1 && sp>0){xyshow(x,y-1,move);x=x+1;}
		else if(move==2 && y>=2 && sp>0){xyshow(x-1,y-2,move);y=y-1;}
		else if(move==5 && sp_max>=sp){xyshow(x-1,y-1,move);}
		else if(sp==0){xyshow(x-1,y-1,0);cout<<"��O���� �Х�"<<endl;}
		else if(move==0){break;}
		else{xyshow(x-1,y-1,0);cout<<"again"<<endl;}
		if(sc==999){break;}
		cout<<"��O��: "<<sp<<"/ "<<sp_max<<endl;
		system_massage();cin>>move;sm=sm+1;
	}
	score=sm/(sp_max+sx+sy)*100;cout<<"�A�o��F "<<score<<" ��"<<endl;
	system("pause");return 0;
}
void xyshow(int x,int y,int move)
{                                         /*�i�令��L�Ϯ�*/
	srand(time(NULL));R=rand()%2;int i,j,m=0;char xy[n][n];
	for(i=0;i<n;i++)for(j=0;j<n;j++)xy[i][j]='0';xy[x][y]='X';xy[xg-1][yg-1]='G';
	while(move==7)
	{
		for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
		cout<<"�I��ޯ��V\n8=�V�W\t2=�V�U"<<endl;
		cout<<"4=�V��\t6=�V�k\n5=����"<<endl;cin>>m;
		if(m==5){cout<<"�����I��ޯ�"<<endl;break;}
		else if(m==8){for(i=0;i<3;i++){if(y<n-1)xy[x-1+i][y+1]='=';if(x-1+i==xg-1 && y+1==yg-1)stop=3;}break;}
		else if(m==6){for(i=0;i<3;i++){if(x<n-1 && y<n+1-i && y+i-1>=0)xy[x+1][y-1+i]='=';if(x+1==xg-1 && y-1+i==yg-1)stop=3;}break;}
		else if(m==4){for(i=0;i<3;i++){if(x>0 && y<n+1-i && y+i-1>=0)xy[x-1][y-1+i]='=';if(x-1==xg-1 && y-1+i==yg-1)stop=3;}break;}
		else if(m==2){for(i=0;i<3;i++){if(y>0)xy[x-1+i][y-1]='=';if(x-1+i==xg-1 && y-1==yg-1)stop=3;}break;}
		else{cout<<"again"<<endl;cin>>m;}
	}
	while(move==9)
	{
		for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
		cout<<"�I��ޯ��V\n8=�V�W\t2=�V�U"<<endl;
		cout<<"4=�V��\t6=�V�k\n5=����"<<endl;cin>>m;
		if(m==5){cout<<"�����I��ޯ�"<<endl;break;}
		else if(m==8){for(i=1;i<n-y;i++){xy[x][y+i]='=';if(x==xg-1 && y+i==yg-1)stop=2;}break;}
		else if(m==6){for(i=1;i<n-x;i++){xy[x+i][y]='=';if(x+i==xg-1 && y==yg-1)stop=2;}break;}
		else if(m==4){for(i=1;i<=x;i++){xy[x-i][y]='=';if(x-i==xg-1 && y==yg-1)stop=2;}break;}
		else if(m==2){for(i=1;i<=y;i++){xy[x][y-i]='=';if(x==xg-1 && y-i==yg-1)stop=2;}break;}
		else{cout<<"again"<<endl;cin>>m;}
	}
	for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
	if(move==5 && sp_max>sp){sp=sp+1;}
	else if(move==8 || move==6 || move==4 || move==2){sp=sp-1;}
	else if(move==7 && m!=5){sp=sp-2;}
	else if(move==9 && m!=5){sp=sp-3;}

	if(move==2||move==4||move==6||move==8||move==7||move==9||move==5)if(stop==0)
	{
		if(R==0 && xg-1>x){xg=xg-1;}
		else if(R==0 && xg-1<x){xg=xg+1;}
		else if(R==1 && yg-1<y){yg=yg+1;}
		else if(R==1 && yg-1>y){yg=yg-1;}
		else if(R==1 && xg-1>x){xg=xg-1;}
		else if(R==1 && xg-1<x){xg=xg+1;}
		else if(R==0 && yg-1<y){yg=yg+1;}
		else if(R==0 && yg-1>y){yg=yg-1;}
		else if(xg-1==x && yg-1==y){cout<<"�A���F\a"<<endl;sc=999;}
	}
	else{cout<<"���Ȱ� "<<stop<<"�^�X"<<endl;stop=stop-1;}
}
void system_massage()
{
	cout<<"7=���\t9=�g��\n8=�V�W\t2=�V�U"<<endl;
	cout<<"4=�V��\t6=�V�k\n5=��\t0=����"<<endl;
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
		2017.11.13 b0.0.4
			�u����O�����{���X
			�u�ƪ�l��J
			�ޯ�t�Ψ֤J���ʨt��
			�s�W�l�v���`�F
			�ץ��ޯ���פ`�F���D(�Ӧ����Y��)
		2017.11.14 b0.0.5
            �s�W�p���t��
            �a��0����
        2017.11.16 b0.0.6
        	�u�ư�AI(���|�̪Ų���)
        	�ޯ�i�h�^�X��װ�
*/
