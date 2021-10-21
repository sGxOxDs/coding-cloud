#include<iostream>
using namespace std;

int f(int n)
{
    if(n<10)
        return n;
    else
    {
        int total=0;
        for(;n!=0;n=n/10)
        {
            total+=n%10;
        }
        return f(total);
    }
}

int main()
{
    int x;
    cin>>x;
    while(x!=0)
    {
        cout<<f(x)<<endl;
        cin>>x;
    }
}
