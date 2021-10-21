#include <iostream>
//用recursive算10進位轉16進位

using namespace std;

void ans_recursive(int in_put)
{
    if(in_put==0)
        return;
    ans_recursive(in_put/16);
    switch(in_put%16)
    {
        case 0:
            cout<<"0";
            break;
        case 1:
            cout<<"1";
            break;
        case 2:
            cout<<"2";
            break;
        case 3:
            cout<<"3";
            break;
        case 4:
            cout<<"4";
            break;
        case 5:
            cout<<"5";
            break;
        case 6:
            cout<<"6";
            break;
        case 7:
            cout<<"7";
            break;
        case 8:
            cout<<"8";
            break;
        case 9:
            cout<<"9";
            break;
        case 10:
            cout<<"A";
            break;
        case 11:
            cout<<"B";
            break;
        case 12:
            cout<<"C";
            break;
        case 13:
            cout<<"D";
            break;
        case 14:
            cout<<"E";
            break;
        case 15:
            cout<<"F";
            break;
        default:
            cout<<"error"<<endl;
            break;
    }
}

int main()
{
    int In_Put;
    while(cin>>In_Put)
    {
        if(In_Put<0||In_Put>32767)
        {
            cout<<"error"<<endl;
            break;
        }
        else if(In_Put==0)
        {
            cout<<In_Put<<" = "<<"0"<<endl;
        }
        else
        {
            cout<<In_Put<<" = ";
            ans_recursive(In_Put);
            cout<<endl;
        }
    }
}
