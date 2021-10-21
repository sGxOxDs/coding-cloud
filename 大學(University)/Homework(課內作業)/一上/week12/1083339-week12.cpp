#include <iostream>
#include <fstream>
#include <sstream>
//1083339 binary data
using namespace std;

struct record {
int id;
unsigned char name[16];
int weight;
int height;
float bmi;
};

void choose(int a)
{
    if(a==1)
    {
        fstream file("records.csv",ios::in);
        if(!file)
        {
            cout<<"can't open"<<endl;
            return;
        }
        fstream binary("records.dat",ios::out|ios::binary);
        if(!binary)
        {
            cout<<"can't out"<<endl;
            return;
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

        record TurnDataTo[data_line];

        for(int i=0 ;i<data_line;i++ )
        {
            TurnDataTo[i].id=i;
            int j;
            for(j=0;data[i][1][j]!='\0';j++)
                TurnDataTo[i].name[j]=data[i][1][j];
            TurnDataTo[i].name[j]='\0';

            TurnDataTo[i].height=height[i];
            TurnDataTo[i].weight=weight[i];
            TurnDataTo[i].bmi= (weight[i]+0.0)/((height[i]/100.0)*(height[i]/100.0));
        }

        for(auto var:TurnDataTo)
            binary.write((char*)&var,sizeof(record));

        file.close();
        binary.close();
    }
    else if(a==2)
    {
        fstream binary("records.dat",ios::in|ios::binary);
        if(!binary)
        {
            cout<<"can't out"<<endl;
            return;
        }
        record BinaryData[100];
        int BinaryData_line=0;
        while(!binary.eof())
        {
            record temp;
            binary.read((char*)&temp,sizeof(record));
            BinaryData[BinaryData_line]=temp;
            BinaryData_line++;
        }
        BinaryData_line--;

        for(int i=0;i<BinaryData_line;i++)
        {
            if(BinaryData[i].bmi<18.5)
            {
                cout<<BinaryData[i].id<<"  "
                    <<BinaryData[i].name<<"  "
                    <<BinaryData[i].height<<"  "
                    <<BinaryData[i].weight<<"  "
                    <<BinaryData[i].bmi<<"  "<<endl;
            }
        }
        binary.close();
    }
}

int main()
{
    int a;
    cout<<"0 to end"<<endl;
    cout<<"1 to savebinarydata"<<endl;
    cout<<"2 to readbinarydata"<<endl;
    while(cin>>a)
    {
        if(a==0)
            break;
        choose(a);
        cout<<"0 to end"<<endl;
        cout<<"1 to savebinarydata"<<endl;
        cout<<"2 to readbinarydata"<<endl;
    }

}
