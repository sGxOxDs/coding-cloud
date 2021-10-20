#include<iostream>
#include <time.h>

using namespace std;

struct player_data
{
    int pid;
    int money;
    int where;
    void move(int x)
    {
        where=where+x;
        if(where>=24)
        {
            where=where-24;
            money=money+2000;
        }
    }
    void pay(int y)
    {
        money=money+y;
    }
    void debug_data()
    {
        cout<<"玩家ID:\t"<<pid<<"\n玩家位置:"<<where<<"\n玩家財產:"<<money<<endl<<endl;
    }
};
struct map_data
{
    int mid;
    int sell_p;
    int buy_p;
    int building_level;
    int owner;
    void mapdata()
    {
        cout<<"地圖ID:\t"<<mid<<"\n地圖價格:"<<buy_p
        <<"\n建築等級:"<<building_level<<"\n擁有者:\t"<<owner<<endl<<endl;
    }
};
player_data PD[8];
map_data MD[24];
void load(int a)
{
    for(int i=0;i<a;i++)
    {
        PD[i]={i,10000,0};
    }
    for(int i=0;i<24;i++)
    {
        MD[i]={i,0,(i/5+1)*500,1,-1};
    }
    MD[0]={0,-1,-1,-1,-1};
    MD[6]={6,-1,-1,-1,-1};
    MD[12]={12,-1,-1,-1,-1};
    MD[18]={18,-1,-1,-1,-1};
    srand (time(NULL));
}
int dice()
{
    int random=rand()%3+1;
    return random;
}

int main()
{
    int a;bool b=true;
    cin>>a;
    if(a<9 && a>0){}
    else
    {
        do{
            cout<<"重新輸入 必須在1~8之間"<<endl;
            cin>>a;
        }while(a>8 || a<=0);
    }
    int rank[a];
    load(a);
    while(b)
    {
        for(int i=0;i<a;i++)
        {
            PD[i].move(dice());
            /*
            MD[PD[i].where].mapdata();
            if(PD[i].money>MD[PD[i].where].buy_p&&MD[PD[i].where].buy_p!=-1&&MD[PD[i].where].owner==-1) //買地
            {
                cout<<"Buy?(y/n)"<<endl;
                char c; cin>>c;
                switch(c)
                {
                    case 'y':   PD[i].pay(-MD[PD[i].where].buy_p);
                                MD[PD[i].where].owner=PD[i].pid; break;
                    case 'Y':   PD[i].pay(-MD[PD[i].where].buy_p);
                                MD[PD[i].where].owner=PD[i].pid; break;
                    case 'n':break;
                    case 'N':break;
                    default :break;
                }
            }
            */
            if(PD[i].money>MD[PD[i].where].buy_p&&MD[PD[i].where].buy_p!=-1&&MD[PD[i].where].owner==-1) //買地auto
            {
                PD[i].pay(-MD[PD[i].where].buy_p);
                MD[PD[i].where].owner=PD[i].pid;
            }
            /*if(MD[PD[i].where].owner==PD[i].pid&&PD[i].money>MD[PD[i].where].buy_p) //升級建築
            {
                cout<<"BLvUP?(y/n)"<<endl;
                char c; cin>>c;
                switch(c)
                {
                    case 'y':   PD[i].pay(-MD[PD[i].where].buy_p);
                                MD[PD[i].where].building_level++; break;
                    case 'Y':   PD[i].pay(-MD[PD[i].where].buy_p);
                                MD[PD[i].where].building_level++; break;
                    case 'n':break;
                    case 'N':break;
                    default :break;
                }
            }*/
            if(MD[PD[i].where].owner==PD[i].pid&&PD[i].money>MD[PD[i].where].buy_p) //升級建築auto
            {
                PD[i].pay(-MD[PD[i].where].buy_p);
                MD[PD[i].where].building_level++;
            }
            if(MD[PD[i].where].owner!=-1) //過路費
            {
                PD[i].pay(-MD[PD[i].where].buy_p*MD[PD[i].where].building_level);
                PD[MD[PD[i].where].owner].pay(MD[PD[i].where].buy_p*MD[PD[i].where].building_level);
            }
        }
        for(int i=0;i<a;i++) //data檢測
        {
            PD[i].debug_data();
            int temp1=0;
            for(int j=0;j<24;j++)
            {
                if(PD[i].pid==MD[j].owner)
                {
                    temp1=temp1+MD[j].buy_p*MD[j].building_level;
                }
            }
            cout<<"玩家總資產:"<<PD[i].money+temp1<<endl<<endl;
            MD[PD[i].where].mapdata();
        }
        for(int i=0;i<a;i++) //破產檢測
        {
            int temp=0;
            for(int j=0;j<24;j++)
            {
                if(PD[i].pid==MD[j].owner)
                {
                    temp=temp+MD[j].buy_p*MD[j].building_level;
                }
            }
            if(PD[i].money+temp<0){b=false;cout<<"玩家 "<<i<<" 破產了!!!"<<endl;break;}
        }
    }
    for(int i=0;i<a;i++) //data結算
    {
        PD[i].debug_data();
        int temp1=0;
        for(int j=0;j<24;j++)
        {
            if(PD[i].pid==MD[j].owner)
            {
                temp1=temp1+MD[j].buy_p*MD[j].building_level;
            }
        }
        cout<<"玩家總資產:"<<PD[i].money+temp1<<endl<<endl;
    }
    for(int j=0;j<24;j++)
    {
        MD[j].mapdata();
    }
    cout<<"end"<<endl;
}





/*
    開發者日誌

    Day.0
        覺得自己太廢
        心血來潮的挑戰做大富翁程式 順便復健
        構思運用大量結構 減少自己負擔
    Day.1
        開始動工
        將大量構思轉為現實
        完成兩種資料結構
        製作買地 過路費 回到起點送錢 破產檢測 建築加蓋 等系統

*/
