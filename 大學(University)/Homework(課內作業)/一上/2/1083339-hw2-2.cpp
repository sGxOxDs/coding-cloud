#include <iostream>
using namespace std;

int main()
{
    string number;
    cout<<"Enter a positive integer of at most 8 digits: ";
    cin>>number;
    int total=0;
    for(int i=0;i<number.length();i++)
        total=total+number.at(i)-'0';
    cout<<"The sum of all digits of "<<number<<" is "<<total<<endl;
    system("pause");
}
