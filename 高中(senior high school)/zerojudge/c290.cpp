#include<iostream>
#include<string>
using namespace std;

int main()
{
    string x;
    while(cin>>x)
    {
        int a=0,b=0;
        for(int i=0;i<x.size();i++)
        {
            if(i%2==0)
            {
                a=a+x.at(i)-'0';
            }
            else if(i%2==1)
            {
                b=b+x.at(i)-'0';
            }
        }
        if(a<b)
        {
            int tmp=a;a=b;b=tmp;
        }
        cout<<a-b<<endl;
    }

}
