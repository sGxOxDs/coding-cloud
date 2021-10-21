#include<iostream>
using namespace std;

int oddSum(int a,int b)
{
    int sum=0;
    if(a>b)
    {
        int temp=a;a=b;b=temp;
    }
    if(a%2==1)
    {
        for(int i=a;i<=b;i+=2)
        {
            sum+=i;
        }
    }
    else
    {
        for(int i=a+1;i<=b;i+=2)
        {
            sum+=i;
        }
    }
    return sum;
}

int main()
{
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        cout<<"Case "<<i+1<<": "<<oddSum(x,y)<<endl;
    }
}
