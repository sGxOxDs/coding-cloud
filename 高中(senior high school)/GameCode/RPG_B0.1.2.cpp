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
HANDLE hIn, hOut;  /*������*/
place H,hv={0,0},B,bv={0,0}; /*���a,���ʦV�q*/
char g_map[N][2*N+4];
int delay_time=20;
int    x1=2,y1=1,x2=(N-1)*2,y2=N-1;  //�ж����
int bm=0,mult;

void k_control()
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
void gotoxy (int x, int y)/*������*/
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
	cout<<"����H�C���{�����J��"<<endl;
	Sleep(1500);system("CLS");
    
	srand (time(NULL));
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);/*������*/
    hIn  = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE err = INVALID_HANDLE_VALUE;
    if (hIn == err || hOut == err) {
        puts ("handle failed");
        getch ();
        exit (1);
    }
    cout<<"�C������:"<<endl;
    cout<<"�ϥ���L����V��i��C��"<<endl;
    cout<<"���o�V�[���ƶV��!!!"<<endl;
    system("pause");system("CLS");
	cout<<"�C���Y�N�}�l"<<endl;
    system("pause");system("CLS");
    draw_map();
    H.set(x1+3,(y2-y1)/2);
    B.set(x2-3,(y2-y1)/2);
}
void Boss_AI()
{
	int R1=(rand()+bm)%2,R2=(rand()+bm)%3;
    if(B.x>H.x && B.y<H.y) /*B��bH����1�H����*/
    {
    	switch(R1)
    	{
    		case 0:bv.set(-2,0);break;
    		case 1:bv.set(0,1);break;
		}
	}
	else if(B.x<H.x && B.y<H.y) /*B��bH����2�H����*/
    {
    	switch(R1)
    	{
    		case 0:bv.set(2,0);break;
    		case 1:bv.set(0,1);break;
		}
	}
	else if(B.x<H.x && B.y>H.y) /*B��bH����3�H����*/
    {
    	switch(R1)
    	{
    		case 0:bv.set(2,0);break;
    		case 1:bv.set(0,-1);break;
		}
	}
	else if(B.x>H.x && B.y>H.y) /*B��bH����4�H����*/
    {
    	switch(R1)
    	{
    		case 0:bv.set(-2,0);break;
    		case 1:bv.set(0,-1);break;
		}
	}
	if(B.x==H.x) /*B�bH��Y�b�W��*/ 
	{
		if(B.y>H.y)
		{
			switch(R2)
    	    {
    			case 0:bv.set(-2,0);break;
    			case 1:bv.set(0,-1);break;
    			case 2:bv.set(2,0);break;
			}
		}
		else
		{
			switch(R2)
    	    {
    			case 0:bv.set(-2,0);break;
    			case 1:bv.set(0,1);break;
    			case 2:bv.set(2,0);break;
			}
		}
	}
	else if(B.y==H.y) /*B�bH��X�b�W��*/ 
	{
		if(B.x>H.x)
		{
			switch(R2)
    	    {
    			case 0:bv.set(-2,0);break;
    			case 1:bv.set(0,-1);break;
    			case 2:bv.set(0,1);break;
			}
		}
		else
		{
			switch(R2)
    	    {
    			case 0:bv.set(2,0);break;
    			case 1:bv.set(0,-1);break;
    			case 2:bv.set(0,1);break;
			}
		}
	}
	if(B.x<=x1&&bv.x==-2|| B.x>x2+2&&bv.x==2|| B.y<=y1&&bv.y==-1|| B.y>=y2-1&&bv.y==1)
        bv.set(0,0);
    draw(B.x,B.y," ");
    B.x=B.x+bv.x;
    B.y=B.y+bv.y;
    draw(B.x,B.y,"B");
    bv.set(0,0);
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
    	mult=bm/500+1;
        Sleep(delay_time);
        if(kbhit()) k_control();
        hero_move();
        if(bm%5==0) Boss_AI(); bm++;
        for(int i=1;i<mult;i++)
        {
        	if(kbhit()) k_control();
       		hero_move();
        	if(bm%5==0) Boss_AI(); bm++;
        	if(H.x==B.x && H.y==B.y)
				break;
		}
        if(H.x==B.x && H.y==B.y)
			break;
    }
    system("CLS");
    cout<<"Game Over"<<endl;
    cout<<"���Ƶ��⤤�w�p�n5��"<<endl;
    Sleep(5000);
    system("CLS"); 
    cout<<"�A�o��:"<<bm*mult*mult<<"��"<<endl;
    system("pause");
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
        2017.11.19 b0.0.7
        	���C��צ^�X��
        	�s�W���ޯ�
        	�t�έ��߲��h�Ƶ{��
			�T���Τ@�Ƶ{��
        	�@��BUG�X�{
======================================== 
        2018.06.09 b0.1.0
            �{���������g
            �אּ�Y�ɨt��
            ��y�g�Y�D
            �@�藍���ժ��{��
        2019.1.31 b0.1.1
        	�����ժ��{���|�ΤF
			���ʥѳs��אּ�I�� 
		2019.2.1 b0.1.2
			�s�W��B,�p����
			���H�ɶ��W�[�ӥ[�t
			�����H�ʤ� 
*/
