#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> bin,oct;
    int number,a,b;
    cout<<"Enter a positive decimal integer of at most 8 digits: ";
    cin>>number;
    a=number;b=number;
    while(true)
    {
        bin.push_back(a%2);
        if(a<2)break;
        a=(a-a%2)/2;
    }
    while(true)
    {
        oct.push_back(b%8);
        if(b<8)break;
        b=(b-b%8)/8;
    }
    reverse(bin.begin(),bin.end());
    reverse(oct.begin(),oct.end());
    cout<<"The binary equivalent of "<<number<<" is ";
    for(int i=0;i<bin.size();i++)
        cout<<bin[i];
    cout<<endl;
    cout<<"The octal equivalent of "<<number<<" is ";
    for(int i=0;i<oct.size();i++)
        cout<<oct[i];
    cout<<endl;
    system("pause");
}
