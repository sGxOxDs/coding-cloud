#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std ;
const int N = 23;
struct place
{
    int x,y;
    void set(int X,int Y)
    {
        x=X;y=Y;
    }
};
HANDLE hIn, hOut;  /*不明白*/
place H,hv={0,0}; /*玩家,移動向量*/
char g_map[N][2*N+4];
int delay_time=20;
int    x1=2,y1=1,x2=(N-1)*2,y2=N-1;  //房間邊界
void k_control() /*不明白*/
{
    static DWORD count;
    static INPUT_RECORD ir;
    ReadConsoleInput (hIn, &ir, 1, &count);
    if (!ir.Event.KeyEvent.bKeyDown) return;
    switch (ir.Event.KeyEvent.wVirtualKeyCode)
    {
        case VK_UP:hv.set(0,-1);break;
        case VK_DOWN:hv.set(0,1);break;
        case VK_LEFT:hv.set(-2,0);break;
        case VK_RIGHT:hv.set(2,0);break;
        case VK_SPACE:hv.set(0,0);break;
        default :break;
    }

}
void gotoxy (int x, int y)/*不明白*/
{
    static COORD c;
    c.X = x; c.Y = y;
    SetConsoleCursorPosition (hOut, c);
}
void draw (int x, int y, char* s)
{
    gotoxy (x,y);
    cout << s;
}
void draw_map()
{
    for(int i=1;i<N-1;i++)
        for(int j=1;j<2*N+3;j++)
            g_map[i][j]='\0';
    for(int i=1;i<N-1;i++)
    {
        g_map[i][0]='|';
        g_map[i][2*N+3]='|';

    }
    for(int i=1;i<2*N+3;i++)
    {
        g_map[0][i]='-';
        g_map[N-1][i]='-';
    }
    g_map[0][0]='O';
    g_map[0][2*N+3]='O';
    g_map[N-1][0]='O';
    g_map[N-1][2*N+3]='O';
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<2*N+4;j++)
                cout<<g_map[i][j];
            cout<<endl;
        }
}
void start_load()
{
    srand (time(NULL));
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);/*不明白*/
    hIn  = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE err = INVALID_HANDLE_VALUE;
    if (hIn == err || hOut == err) {
        puts ("handle failed");
        getch ();
        exit (1);
    }
    draw_map();
    H.set((x2-x1)/2+3, (y2-y1)/2);
}
void hero_move()
{
    if(H.x<=x1&&hv.x==-2|| H.x>x2+2&&hv.x==2|| H.y<=y1&&hv.y==-1|| H.y>=y2-1&&hv.y==1)
        hv.set(0,0);
    draw(H.x,H.y," ");
    H.x=H.x+hv.x;
    H.y=H.y+hv.y;
    draw(H.x,H.y,"H");
    hv.set(0,0);
}
int main()
{
    start_load();
    while(true)
    {
        Sleep(delay_time);
        if(kbhit())k_control();
        hero_move();
    }
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
        2017.11.19 b0.0.7
        	降低抵擋回合數
        	新增鬼技能
        	系統重心移去副程式
			訊息統一副程式
        	一堆BUG出現
        2018.06.09 b0.1.0
            程式完全重寫
            改為即時系統
            仿造貪吃蛇
            一堆不明白的程式
        2019.1.31 b0.1.1
        	不明白的程式會用了
			移動由連續改為點式 
*/
