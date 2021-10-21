#include <iostream>
#include <fstream>
#include <sstream>
//1083339 ŪCSV
using namespace std;

int main()
{
    fstream file("records.csv",ios::in);
    if(!file)
    {
        cout<<"can't open"<<endl;
        return 0;
    }
    stringstream ss;
    string value,temp;
    ss.str("");
    ss.clear();

    string data[100][4];
    int data_line=0;
    for(data_line=0 ;getline(file,temp);data_line++ )
    {
        ss.str(temp);
        for(int j=0 ;getline(ss,value,',');j++ )
            data[data_line][j]=value;
        ss.clear();
    }

    stringstream sn;

    int weight[100],height[100];
    for(int i=0;i<100;i++)
    {
        weight[i]=-1;
        height[i]=-1;
    }

    for(int i=0;i<data_line;i++)
    {
        sn.str("");
        sn.clear();
        sn<<data[i][2];
        sn>>weight[i];
    }
    for(int i=0;i<data_line;i++)
    {
        sn.str("");
        sn.clear();
        sn<<data[i][3];
        sn>>height[i];
    }

    int sum=0;
    for(int i=0;i<data_line;i++)
        sum+=weight[i];
    cout<<sum/data_line<<endl;
    sum=0;
    for(int i=0;i<data_line;i++)
        sum+=height[i];
    cout<<sum/data_line<<endl<<endl;

    for(int i=0;i<data_line;i++)
        for(int j=0;j<data_line;j++)
            if(data[i][3]<data[j][3])
                for(int k=0;k<4;k++)
                {
                    temp=data[i][k];
                    data[i][k]=data[j][k];
                    data[j][k]=temp;
                }
    for(int i=0 ;i<data_line;i++ )
    {
        for(int j=0; j<4; j++)
            cout<<data[i][j]<<" ";
        cout<<endl;
    }

}
