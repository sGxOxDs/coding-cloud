#include <iostream>
#include <vector>
//用Iterative算10進位轉16進位

using namespace std;

int main()
{
    int in_put;
    while(cin>>in_put)
    {
        if(in_put<0||in_put>32767)
        {
            cout<<"error"<<endl;
            break;
        }
        else if(in_put==0)
        {
            cout<<in_put<<" = "<<"0"<<endl;
        }
        else
        {
            vector <char> ans_string;
            cout<<in_put<<" = ";
            for(;in_put>0;in_put=in_put/16)
            {
                switch(in_put%16)
                {
                    case 0:
                        ans_string.push_back('0');
                        break;
                    case 1:
                        ans_string.push_back('1');
                        break;
                    case 2:
                        ans_string.push_back('2');
                        break;
                    case 3:
                        ans_string.push_back('3');
                        break;
                    case 4:
                        ans_string.push_back('4');
                        break;
                    case 5:
                        ans_string.push_back('5');
                        break;
                    case 6:
                        //cout<<"6";
                        ans_string.push_back('6');
                        break;
                    case 7:
                        //cout<<"7";
                        ans_string.push_back('7');
                        break;
                    case 8:
                        //cout<<"8";
                        ans_string.push_back('8');
                        break;
                    case 9:
                        //cout<<"9";
                        ans_string.push_back('9');
                        break;
                    case 10:
                        //cout<<"A";
                        ans_string.push_back('A');
                        break;
                    case 11:
                        //cout<<"B";
                        ans_string.push_back('B');
                        break;
                    case 12:
                        //cout<<"C";
                        ans_string.push_back('C');
                        break;
                    case 13:
                        //cout<<"D";
                        ans_string.push_back('D');
                        break;
                    case 14:
                        //cout<<"E";
                        ans_string.push_back('E');
                        break;
                    case 15:
                        //cout<<"F";
                        ans_string.push_back('F');
                        break;
                    default:
                        cout<<"error"<<endl;
                        break;
                }
            }
            for(int i=ans_string.size()-1;i>=0;i--)
                cout<<ans_string[i];
            cout<<endl;
        }

    }
}
