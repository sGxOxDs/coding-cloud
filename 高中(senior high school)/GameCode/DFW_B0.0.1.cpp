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
        cout<<"���aID:\t"<<pid<<"\n���a��m:"<<where<<"\n���a�]��:"<<money<<endl<<endl;
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
        cout<<"�a��ID:\t"<<mid<<"\n�a�ϻ���:"<<buy_p
        <<"\n�ؿv����:"<<building_level<<"\n�֦���:\t"<<owner<<endl<<endl;
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
            cout<<"���s��J �����b1~8����"<<endl;
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
            if(PD[i].money>MD[PD[i].where].buy_p&&MD[PD[i].where].buy_p!=-1&&MD[PD[i].where].owner==-1) //�R�a
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
            if(PD[i].money>MD[PD[i].where].buy_p&&MD[PD[i].where].buy_p!=-1&&MD[PD[i].where].owner==-1) //�R�aauto
            {
                PD[i].pay(-MD[PD[i].where].buy_p);
                MD[PD[i].where].owner=PD[i].pid;
            }
            /*if(MD[PD[i].where].owner==PD[i].pid&&PD[i].money>MD[PD[i].where].buy_p) //�ɯūؿv
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
            if(MD[PD[i].where].owner==PD[i].pid&&PD[i].money>MD[PD[i].where].buy_p) //�ɯūؿvauto
            {
                PD[i].pay(-MD[PD[i].where].buy_p);
                MD[PD[i].where].building_level++;
            }
            if(MD[PD[i].where].owner!=-1) //�L���O
            {
                PD[i].pay(-MD[PD[i].where].buy_p*MD[PD[i].where].building_level);
                PD[MD[PD[i].where].owner].pay(MD[PD[i].where].buy_p*MD[PD[i].where].building_level);
            }
        }
        for(int i=0;i<a;i++) //data�˴�
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
            cout<<"���a�`�겣:"<<PD[i].money+temp1<<endl<<endl;
            MD[PD[i].where].mapdata();
        }
        for(int i=0;i<a;i++) //�}���˴�
        {
            int temp=0;
            for(int j=0;j<24;j++)
            {
                if(PD[i].pid==MD[j].owner)
                {
                    temp=temp+MD[j].buy_p*MD[j].building_level;
                }
            }
            if(PD[i].money+temp<0){b=false;cout<<"���a "<<i<<" �}���F!!!"<<endl;break;}
        }
    }
    for(int i=0;i<a;i++) //data����
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
        cout<<"���a�`�겣:"<<PD[i].money+temp1<<endl<<endl;
    }
    for(int j=0;j<24;j++)
    {
        MD[j].mapdata();
    }
    cout<<"end"<<endl;
}





/*
    �}�o�̤�x

    Day.0
        ı�o�ۤv�Ӽo
        �ߦ�Ӽ骺�D�԰��j�I�ε{�� ���K�_��
        �c��B�Τj�q���c ��֦ۤv�t��
    Day.1
        �}�l�ʤu
        �N�j�q�c���ର�{��
        ������ظ�Ƶ��c
        �s�@�R�a �L���O �^��_�I�e�� �}���˴� �ؿv�[�\ ���t��

*/
