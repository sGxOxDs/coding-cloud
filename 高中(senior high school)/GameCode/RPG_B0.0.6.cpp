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
	do{cout<<"輸入地圖大小:";cin>>n;}while(n<=1);
	do{cout<<"輸入起始座標(1~"<<n<<",1~"<<n<<"):";cin>>x>>y;}
	while(x<=0 || x>=n+1 || y<=0 || y>=n+1);
	do{cout<<"輸入鬼的起始座標(1~"<<n<<",1~"<<n<<"):";cin>>xg>>yg;}
	while(xg<=0 || xg>=n+1 || yg<=0 || yg>=n+1 ||xg==x && yg==y);
	do{cout<<"體力值上限:";cin>>sp_max;}while(sp_max<=0);
	sp = sp_max;xyshow(x-1,y-1,0);cout<<"體力值: "<<sp<<"/ "<<sp_max<<endl;
	system_massage();cin>>move;
	if(x>=xg){sx=x-xg;}else if(xg>x){sx=xg-x;}
	if(y>=yg){sy=y-yg;}else if(yg>y){sy=yg-y;}
	while(move!=0 && sc!=999)
	{
		system("CLS");/*system為控制dos系統下的清畫面指令*/
		if(move==7 && sp>1 || move==9 && sp>2){xyshow(x-1,y-1,move);}
		else if(move==8 && y<=n-1 && sp>0){xyshow(x-1,y,move);y=y+1;}
		else if(move==4 && x>=2 && sp>0){xyshow(x-2,y-1,move);x=x-1;}
		else if(move==6 && x<=n-1 && sp>0){xyshow(x,y-1,move);x=x+1;}
		else if(move==2 && y>=2 && sp>0){xyshow(x-1,y-2,move);y=y-1;}
		else if(move==5 && sp_max>=sp){xyshow(x-1,y-1,move);}
		else if(sp==0){xyshow(x-1,y-1,0);cout<<"體力不足 請休息"<<endl;}
		else if(move==0){break;}
		else{xyshow(x-1,y-1,0);cout<<"again"<<endl;}
		if(sc==999){break;}
		cout<<"體力值: "<<sp<<"/ "<<sp_max<<endl;
		system_massage();cin>>move;sm=sm+1;
	}
	score=sm/(sp_max+sx+sy)*100;cout<<"你得到了 "<<score<<" 分"<<endl;
	system("pause");return 0;
}
void xyshow(int x,int y,int move)
{                                         /*可改成其他圖案*/
	srand(time(NULL));R=rand()%2;int i,j,m=0;char xy[n][n];
	for(i=0;i<n;i++)for(j=0;j<n;j++)xy[i][j]='0';xy[x][y]='X';xy[xg-1][yg-1]='G';
	while(move==7)
	{
		for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
		cout<<"施放技能方向\n8=向上\t2=向下"<<endl;
		cout<<"4=向左\t6=向右\n5=取消"<<endl;cin>>m;
		if(m==5){cout<<"取消施放技能"<<endl;break;}
		else if(m==8){for(i=0;i<3;i++){if(y<n-1)xy[x-1+i][y+1]='=';if(x-1+i==xg-1 && y+1==yg-1)stop=3;}break;}
		else if(m==6){for(i=0;i<3;i++){if(x<n-1 && y<n+1-i && y+i-1>=0)xy[x+1][y-1+i]='=';if(x+1==xg-1 && y-1+i==yg-1)stop=3;}break;}
		else if(m==4){for(i=0;i<3;i++){if(x>0 && y<n+1-i && y+i-1>=0)xy[x-1][y-1+i]='=';if(x-1==xg-1 && y-1+i==yg-1)stop=3;}break;}
		else if(m==2){for(i=0;i<3;i++){if(y>0)xy[x-1+i][y-1]='=';if(x-1+i==xg-1 && y-1==yg-1)stop=3;}break;}
		else{cout<<"again"<<endl;cin>>m;}
	}
	while(move==9)
	{
		for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
		cout<<"施放技能方向\n8=向上\t2=向下"<<endl;
		cout<<"4=向左\t6=向右\n5=取消"<<endl;cin>>m;
		if(m==5){cout<<"取消施放技能"<<endl;break;}
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
		else if(xg-1==x && yg-1==y){cout<<"你死了\a"<<endl;sc=999;}
	}
	else{cout<<"鬼暫停 "<<stop<<"回合"<<endl;stop=stop-1;}
}
void system_massage()
{
	cout<<"7=橫砍\t9=射擊\n8=向上\t2=向下"<<endl;
	cout<<"4=向左\t6=向右\n5=休息\t0=結束"<<endl;
}






/*
	目標RPG 更新日誌:
		2017.11.09 b0.0.1
			主程式確立
			地圖建立 移動系統建立
			把for改成副程式
		2017.11.10 b0.0.2
			新增體力系統
			新增移動提示
		2017.11.10 b0.0.3
			地圖系統可用圖案
			訊息系統優化
			遊戲介面清除之前資料
			新增技能系統
			解決若干技能顯示的BUG
			優化體力部分判斷式
		2017.11.13 b0.0.4
			優化體力部分程式碼
			優化初始輸入
			技能系統併入移動系統
			新增追逐的亡靈
			修正技能阻擋亡靈問題(該死的縮排)
		2017.11.14 b0.0.5
            新增計分系統
            地圖0隱藏
        2017.11.16 b0.0.6
        	優化鬼AI(不會憑空移動)
        	技能可多回合抵擋鬼
*/
