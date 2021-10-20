#include <iostream>
using namespace std;

void xyshow(int,int,int);
void system_massage();
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
		if(move==8 && y<=n-1 && sp>0){xyshow(n,x-1,y);y=y+1;sp=sp-1;}
		else if(move==4 && x>=2 && sp>0){xyshow(n,x-2,y-1);x=x-1;sp=sp-1;}
		else if(move==6 && x<=n-1 && sp>0){xyshow(n,x,y-1);x=x+1;sp=sp-1;}
		else if(move==2 && y>=2 && sp>0){xyshow(n,x-1,y-2);y=y-1;sp=sp-1;}
		else if(move==8 && sp==0||move==4 && sp==0||move==6 && sp==0||move==2 && sp==0)
		{cout<<"體力不足 請休息"<<endl;}
		else if(move==5 && sp==sp_max){xyshow(n,x-1,y-1);}
		else if(move==5 && sp_max>sp){xyshow(n,x-1,y-1);sp=sp+1;}
		else if(move==0){break;}
		else{cout<<"again"<<endl;}
		cout<<"體力值: "<<sp<<"/ "<<sp_max<<endl;
		system_massage();cin>>move;
	}
	system("pause");
	return 0;
}
void xyshow(int n,int x,int y)
{                                         /*0 1可改成其他數字(圖案待解決)*/ 
	int i,j,xy[n][n];for(i=0;i<n;i++)for(j=0;j<n;j++)xy[i][j]=0;xy[x][y]=1;
	for(j=n-1;j>=0;j--){for(i=0;i<n;i++)cout<<xy[i][j]<<" ";cout<<endl;}
}
void system_massage()
{
	cout<<"8=向上\t2=向下"<<endl;
	cout<<"4=向左\t6=向右"<<endl;
	cout<<"5=休息\t0=結束"<<endl;
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
				 
*/ 
