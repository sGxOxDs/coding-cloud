#include <iostream>
using namespace std;

#define degree 101
struct Node
{
    char c;
    int side[degree]={-1};
    bool fSide[degree]={false};
    bool footPrint = false;
    void Check()
    {
        for(int i=0;i<degree;i++)
            for(int j=i+1;j<degree;j++)
                if(fSide[i]&&fSide[j]&&side[i]>side[j])
                {
                    int temp=side[i];
                    side[i]=side[j];
                    side[j]=temp;
                }
    }
    void Well(int nope)
    {
        for(int i=0;i<degree;i++)
            if(fSide[i]&&side[i]==nope)
                fSide[i]=false;
    }
    void RemoveWell(int nope)
    {
        for(int i=0;i<degree;i++)
            if(!(fSide[i])&&side[i]==nope)
                fSide[i]=true;
    }
    void Link(int in)
    {
        for(int i=0;i<degree;i++)
            if(!(fSide[i]))
            {
                side[i]=in;
                fSide[i]=true;
                break;
            }
    }
};

Node* line = new Node[256]();
int node;
char start;
char* ans = new char[256]();

void Traversal(Node root,int AnsCount)
{
    ans[AnsCount]=root.c;
    line[root.c].footPrint = true;
    if(AnsCount<=node)
        for(int i=0;i<degree;i++)
            if(root.fSide[i])
            {
                line[root.side[i]].Well(root.c);
                line[root.c].Well(root.side[i]);
                Traversal(line[root.side[i]],AnsCount+1);
                line[root.side[i]].RemoveWell(root.c);
                line[root.c].RemoveWell(root.side[i]);
            }
}

bool FootPrintCheck()
{
    int count = 0;
    for (int i = 0; i < 256; i++)
        if (line[i].footPrint)
            count++;
    return (count == node);
}

int main()
{
    int time;
    cin >> time;
    bool* anser = new bool[time]();
    for (int j = 0; j < time; j++)
    {
        delete[] line;
        delete[] ans;
        line = new Node[256]();
        ans = new char[256]();
        int n;
        char a, b;
        cin >> node >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            start = b;
            line[a].c = a;
            line[a].Link(b);
            line[b].c = b;
            line[b].Link(a);
        }
        for (int i = 0; i < 256; i++)
            line[i].Check();
        Traversal(line[start], 0);
        anser[j] = FootPrintCheck();
    }
    for (int i = 0; i < time; i++)
    {
        if (anser[i])
            cout << "connect" << endl;
        else
            cout << "disconnect" << endl;
    }
    delete[] anser;
}
