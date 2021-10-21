#include <iostream>
using namespace std;

#define degree 101
struct Node
{
    char C;
    int Side[degree]={-1};
    bool FSide[degree]={false};
    bool ì格 = false;
    void check()
    {
        for(int i=0;i<degree;i++)
            for(int j=i+1;j<degree;j++)
                if(FSide[i]&&FSide[j]&&Side[i]>Side[j])
                {
                    int temp=Side[i];
                    Side[i]=Side[j];
                    Side[j]=temp;
                }
    }
    void well(int nope)
    {
        for(int i=0;i<degree;i++)
            if(FSide[i]&&Side[i]==nope)
                FSide[i]=false;
    }
    void remove_well(int nope)
    {
        for(int i=0;i<degree;i++)
            if(!(FSide[i])&&Side[i]==nope)
                FSide[i]=true;
    }
    void link(int in)
    {
        for(int i=0;i<degree;i++)
            if(!(FSide[i]))
            {
                Side[i]=in;
                FSide[i]=true;
                break;
            }
    }
};

//Node line[256]={};
Node* line = new Node[256]();
int node;
char start;//,Ans[256]={};
char* Ans = new char[256]();
//bool temp = false;

void Traversal(Node root,int AnsCount)
{
    Ans[AnsCount]=root.C;
    line[root.C].ì格 = true;
    if(AnsCount==node)//&&root.C==start)
    {
        //for(int i=0;i<=node;i++)
            //cout<<Ans[i];
        //cout<<endl;
        //temp = true;
    }
    if(AnsCount<=node)
        for(int i=0;i<degree;i++)
            if(root.FSide[i])
            {
                line[root.Side[i]].well(root.C);
                line[root.C].well(root.Side[i]);
                Traversal(line[root.Side[i]],AnsCount+1);
                line[root.Side[i]].remove_well(root.C);
                line[root.C].remove_well(root.Side[i]);
            }
}

bool ì格浪琩()
{
    int count = 0;
    for (int i = 0; i < 256; i++)
        if (line[i].ì格)
        {
            count++;
            //cout << line[i].C;
        }
    //cout << endl;
    return (count == node);
}

int main()
{
    int time;
    cin >> time;
    bool* 氮 = new bool[time]();
    for (int j = 0; j < time; j++)
    {
        delete[] line;
        delete[] Ans;
        line = new Node[256]();
        Ans = new char[256]();
        //temp = false;
        int n;
        char a, b;
        cin >> node >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            start = b;
            line[a].C = a;
            line[a].link(b);
            line[b].C = b;
            line[b].link(a);
        }
        for (int i = 0; i < 256; i++)
            line[i].check();
        Traversal(line[start], 0);
        氮[j] = ì格浪琩();
        
    }
    for (int i = 0; i < time; i++)
    {
        if (氮[i])
            cout << "connect" << endl;
        else
            cout << "disconnect" << endl;
    }
    delete[] 氮;
}
