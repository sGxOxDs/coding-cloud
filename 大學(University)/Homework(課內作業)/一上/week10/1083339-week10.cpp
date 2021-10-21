#include <iostream>
//CPE 10404 UVA10035
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        int carry=0,c=0;
        for(;a!=0||b!=0||c!=0;a/=10,b/=10)
        {
            if(a%10+b%10+c>=10)
            {
                carry++;
                c=1;
            }
            else
                c=0;
        }
        if(carry==0)
            cout<<"No carry operation."<<endl;
        else if(carry==1)
            cout<<"1 carry operation."<<endl;
        else
            cout<<carry<<" carry operations."<<endl;
    }
}
