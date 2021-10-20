#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*get 70% TLE*/
struct line
{
    int st,en;
};/*a new kind that have two int */
bool cmp(line a,line b)
{
    return(a.st<b.st);
}/*if return true then change*/
int main()
{
    int N;
    while(cin>>N)
    {
        line L[N];
        for(int i=0;i<N;i++)
            cin>>L[i].st>>L[i].en;
        sort(L,L+N,cmp);

        int cnt=L[0].en-L[0].st;
        int e=L[0].en;
        for(int i=1;i<N;i++)
        {
            if(e>L[i].en)
            {

            }
            else if(e>=L[i].st&&e<L[i].en)
            {
                cnt=cnt+L[i].en-e;
                e=L[i].en;
            }
            else if(L[i].st>e)
            {
                cnt=cnt+L[i].en-L[i].st;
                e=L[i].en;
            }
        }
        cout<<cnt<<endl;
    }
}
/*
string all(1000000,0);
        int ans=0,l1,l2;
        for(int i=0;i<N;i++)
        {
            cin>>l1>>l2;
            for(int j=l1;j<l2;j++)
            {
                all.at(j)=1;
            }
        }
        for(int i=0;i<all.size();i++)ans=ans+all.at(i);
        cout<<ans<<endl;
*/
/*
int line[N][2];
        for(int i=0;i<N;i++)
            cin>>line[i][0]>>line[i][1];
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(line[i][0]>line[j][0])
                {
                   int tmp=line[i][0];
                   line[i][0]=line[j][0];
                   line[j][0]=tmp;
                   tmp=line[i][1];
                   line[i][1]=line[j][1];
                   line[j][1]=tmp;
                }
            }
        }
        int cnt=line[0][1]-line[0][0];
        int e=line[0][1];
        for(int i=1;i<N;i++)
        {
            if(e>line[i][1])
            {

            }
            else if(e>=line[i][0]&&e<line[i][1])
            {
                cnt=cnt+line[i][1]-e;
                e=line[i][1];
            }
            else if(line[i][0]>e)
            {
                cnt=cnt+line[i][1]-line[i][0];
                e=line[i][1];
            }
        }
        cout<<cnt<<endl;
*/
