#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
//Âù»ë¾÷²vÃö«Y
using namespace std;

inline int Dice()
{
    return rand()%6+1;
}

int main()
{
    int times=36000;
    srand(time(NULL));
    int dice1=-1,dice2=-1;
    double twodiceformat[6][6];
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            twodiceformat[i][j]=0;
    for(int i=0;i<times;i++)
    {
        dice1=Dice();
        dice2=Dice();
        twodiceformat[dice1-1][dice2-1]++;
    }

    cout<<right<<setw(6)<<" "
        <<setw(6)<<"1"<<setw(6)<<"2"
        <<setw(6)<<"3"<<setw(6)<<"4"
        <<setw(6)<<"5"<<setw(6)<<"6"<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<setw(6)<<i+1;
        for(int j=0;j<6;j++)
            cout<<setw(6)<<twodiceformat[i][j];
        cout<<endl;
    }
    cout<<endl;



    for(int k=2;k<=12;k++)
    {
        double temp_allprobability=0;
        cout<<"P("<<k<<") = ";
        if(k<=7)
            for(int x=1,y=1,z=k-1;x<=k-1;x++,y++,z--)
            {
                if(x==1)
                    cout<<"P("<<y<<"+"<<z<<")";
                else
                    cout<<"+P("<<y<<"+"<<z<<")";
            }
        else
            for(int x=1,y=k-6,z=6;x<=13-k;x++,y++,z--)
            {
                if(x==1)
                    cout<<"P("<<y<<"+"<<z<<")";
                else
                    cout<<"+P("<<y<<"+"<<z<<")";
            }
        cout<<"="<<fixed<<setprecision(6);

        if(k<=7)
            for(int x=1,y=1,z=k-1;x<=k-1;x++,y++,z--)
            {
                temp_allprobability+=twodiceformat[y-1][z-1]/(times+0.0);
                if(x==1)
                    cout<<twodiceformat[y-1][z-1]/(times+0.0);
                else
                    cout<<"+"<<twodiceformat[y-1][z-1]/(times+0.0);
            }
        else
            for(int x=1,y=k-6,z=6;x<=13-k;x++,y++,z--)
            {
                temp_allprobability+=twodiceformat[y-1][z-1]/(times+0.0);
                if(x==1)
                    cout<<twodiceformat[y-1][z-1]/(times+0.0);
                else
                    cout<<"+"<<twodiceformat[y-1][z-1]/(times+0.0);
            }
        cout<<"="<<temp_allprobability<<endl;
    }

}
