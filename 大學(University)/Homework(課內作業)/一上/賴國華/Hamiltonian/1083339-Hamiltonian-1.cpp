#include <iostream>
using namespace std;

struct Node
{
    char C;
    int I=-1;
    int J;
    bool FR=true,FL=true;
    void check()
    {
        if(I>J)
        {
            int temp=I;
            I=J;
            J=temp;
        }
    }
    void input(int in)
    {
        if(I==-1)
            I=in;
        else
        {
            J=in;
            check();
        }
    }
};

Node line[256]={};
Node End={'='};
Node Call_Right(Node crrent)
{
    if(line[crrent.I].FR)
    {
        line[crrent.I].FR=false;
        return line[crrent.I];
    }
    else if(line[crrent.J].FR)
    {
        line[crrent.J].FR=false;
        return line[crrent.J];
    }
    else
        return End;
}
Node Call_Left(Node crrent)
{
    if(line[crrent.J].FL)
    {
        line[crrent.J].FL=false;
        return line[crrent.J];
    }
    else if(line[crrent.I].FL)
    {
        line[crrent.I].FL=false;
        return line[crrent.I];
    }
    else
        return End;
}

int main()
{
    int n;
    char a,b,start;
    cin>>n>>start;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        line[a].C=a;
        line[a].input(b);
        line[b].C=b;
        line[b].input(a);
    }

    Node temp=line[start];
    line[start].FR=false;
    while(temp.C!='=')
    {
        cout<<temp.C<<" ";
        temp=Call_Right(temp);
    }
    cout<<line[start].C<<endl;

    temp=line[start];
    line[start].FL=false;
    while(temp.C!='=')
    {
        cout<<temp.C<<" ";
        temp=Call_Left(temp);
    }
    cout<<line[start].C<<endl;
}
