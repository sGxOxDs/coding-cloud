#include<iostream>
using namespace std;

int GCD(int divisor,int dividend)
{
    if(dividend%divisor==0)
        return divisor;
    else
        return GCD(dividend%divisor,divisor);
}

int main()
{
    int N;
    cin>>N;
    while(N!=0)
    {
        int G=0;
        for(int i=1;i<N;i++)
            for(int j=i+1;j<=N;j++)
                G+=GCD(i,j);
        cout<<G<<endl;
        cin>>N;
    }
}
