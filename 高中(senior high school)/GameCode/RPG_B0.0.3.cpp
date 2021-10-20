#include <iostream>
using namespace std;

void xyshow(int,int,int);
void system_massage();
void xyskill(int,int,int,int,int);
int main(void)
{
	int n,x,y,move,sp,sp_max;
	cout<<"輸入地圖大小:";cin>>n;
	do{cout<<"輸入起始座標(1~"<<n<<",1~"<<n<<"):";
	cin>>x>>y;cout<<"體力值上限:";cin>>sp_max;}
	while(x<=0 && sp_max>0||x>=n+1 && sp_max>0||y<=0 && sp_max>0||y>=n+1 && sp_max>0);
	sp = sp_max;xyshow(n,x-1,y-1);cout<<"體力值: "<<sp<<"/ "<<sp_max<<endl;
	system_massage();cin>>move;
	while(move!=0)
	{
		system("CLS");/*system為控制dos系統下的清畫面指令*/
		if(move==7 || move==9)
		{
			xyskill(n,x-1,y-1,move,sp);
			if(move==7 && sp>1){sp=sp-2;}
			else if(move=9 && sp>2){sp=sp-3;}
			else{cout<<"體力不足"<<endl;}
		}
		else if(move==8 && y<=n-1 && sp>0){xyshow(n,x-1,y);y=y+1;sp=sp-1;}
		else if(move==4 && x>=2 && sp>0){xyshow(n,x-2,y-1);x=x-1;sp=sp-1;}
		else if(move==6 && x<=n-1 && sp>0){xyshow(n,x,y-1);x=x+1;sp=sp-1;}
		else if(move==2 && y>=2 && sp>0){xyshow(n,x-1,y-2);y=y-1;sp=sp-1;}
		else if(move==5 && sp_max>=sp){xyshow(n,x-1,y-1);if(sp_max>sp)sp=sp+1;}
		else if(sp==0){xyshow(n,x-1,y-1);cout<<"體力不足 請休息"<<endl;}
		else if(move==0){break;}
		else{xyshow(n,x-1,y-1);cout<<"again"<<endl;}
		cout<<"體力值: "<<sp<<"/ "<<sp_max<<endl;
		system_massage();cin>>move;
	}
	system("pause");
	return 0;
}
void xyshow(int n,int x,int y)
{                                         /*可改成其他圖案*/ 
	int i,j;char xy[n][n];
	for(i=0;i<n;i++)for(j=0;j<n;j++)xy[i][j]='0';xy[x][y]='X';
	for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
}
void system_massage()
{
	cout<<"7=橫砍\t9=射擊\n8=向上\t2=向下"<<endl;
	cout<<"4=向左\t6=向右\n5=休息\t0=結束"<<endl;
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
			cout<<"施放技能方向\n8=向上\t2=向下"<<endl;
			cout<<"4=向左\t6=向右\n5=取消"<<endl;cin>>m;
			if(m==5){cout<<"取消施放技能\n仍消耗體力"<<endl;break;}
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
			cout<<"施放技能方向\n8=向上\t2=向下"<<endl;
			cout<<"4=向左\t6=向右\n5=取消"<<endl;cin>>m;
			if(m==5){cout<<"取消施放技能\n仍消耗體力"<<endl;break;}
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
				 
*/ 
