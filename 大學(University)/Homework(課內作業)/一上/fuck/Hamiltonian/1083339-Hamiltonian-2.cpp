#include <iostream>
using namespace std;

struct Node
{
    char C;
    int X=-1,Y=-1,Z=-1;
    bool FX=false,FY=false,FZ=false;
    void check()
    {
        if(FZ)
        {
            if(Y>Z)
            {
                int temp=Y;
                Y=Z;
                Z=temp;
            }
            if(X>Y)
            {
                int temp=X;
                X=Y;
                Y=temp;
            }
            if(Y>Z)
            {
                int temp=Y;
                Y=Z;
                Z=temp;
            }
        }
        else if(FY)
        {
            if(X>Y)
            {
                int temp=X;
                X=Y;
                Y=temp;
            }
        }
    }
    void well(int nope)
    {
        if(X==nope)
            FX=false;
        else if(Y==nope)
            FY=false;
        else if(Z==nope)
            FZ=false;
    }
    void remove_well(int nope)
    {
        if(X==nope)
            FX=true;
        else if(Y==nope)
            FY=true;
        else if(Z==nope)
            FZ=true;
    }
    void link(int in)
    {
        if(X==-1)
        {
            X=in;
            FX=true;
        }
        else if(Y==-1)
        {
            Y=in;
            FY=true;
        }
        else if(Z==-1)
        {
            Z=in;
            FZ=true;
        }
    }
    void debug()
    {
        int a=FX,b=FY,c=FZ;
        char x=X,y=Y,z=Z;
        cout<<C<<" ";
        cout<<x<<" "<<y<<" "<<z<<" ";
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
};

Node line[256]={};
int node;
char start,Ans[256]={};

void Traversal(Node root,int AnsCount)
{
    Ans[AnsCount]=root.C;
    if(AnsCount==node&&root.C==start)
    {
        for(int i=0;i<=node;i++)
            cout<<Ans[i];
        cout<<endl;
    }
    if(AnsCount<=node)
    {
        //root.debug();
        //cout<<root.C;
        if(root.FX)
        {
            //cout<<"X"<<AnsCount<<" ";
            //root.FX=false;
            line[root.X].well(root.C);
            line[root.C].well(root.X);
            //line[start].debug();
            Traversal(line[root.X],AnsCount+1);//cout<<endl;
            line[root.X].remove_well(root.C);
            line[root.C].remove_well(root.X);
            //root.FX=true;
        }
        if(root.FY)
        {
            //cout<<"Y"<<AnsCount<<" ";
            //root.FY=false;
            line[root.Y].well(root.C);
            line[root.C].well(root.Y);
            Traversal(line[root.Y],AnsCount+1);//cout<<endl;
            line[root.Y].remove_well(root.C);
            line[root.C].remove_well(root.Y);
            //root.FY=true;
        }
        if(root.FZ)
        {
            //cout<<"Z"<<AnsCount<<" ";
            //root.FZ=false;
            line[root.Z].well(root.C);
            line[root.C].well(root.Z);
            Traversal(line[root.Z],AnsCount+1);//cout<<endl;
            line[root.Z].remove_well(root.C);
            line[root.C].remove_well(root.Z);
            //root.FZ=true;
        }
    }
}

int main()
{
    int n;
    char a,b;
    cin>>node>>n>>start;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        line[a].C=a;
        line[a].link(b);
        line[b].C=b;
        line[b].link(a);
    }
    for(int i=0;i<256;i++)
        line[i].check();
    Traversal(line[start],0);
}
