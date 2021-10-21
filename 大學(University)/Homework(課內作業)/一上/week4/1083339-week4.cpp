#include <iostream>
#include <iomanip>
//停車費的計算程式
using namespace std;

double calculateCharges(double hr)
{
    if(hr<=2)
    {
        return 3;
    }
    else if(hr>=22)
    {
        return 15;
    }
    else
    {
        int temp=hr;
        if(hr-0.5>=temp)
        {
            temp++;
        }
        return ( 3 + 0.6*(temp-2) );
    }
}

int main()
{
    double hours[3];
    cout<<"Please enter parking time"<<endl;
    for(int i=0;i<3;i++)
        cin>>hours[i];
    while(hours[0]>24||hours[1]>24||hours[2]>24)
    {
        cout<<"Wrong"<<endl;
        cout<<"please enter again"<<endl;
        for(int i=0;i<3;i++)
            cin>>hours[i];
    }

    cout<<fixed;

    cout<<setw(8)<<left<<"Car"
        <<setw(8)<<right<<"Hours"
        <<setw(8)<<"Charge"<<endl;

    cout<<setw(8)<<left<<"1"
        <<setw(8)<<setprecision(1)<<right<<hours[0]
        <<setw(8)<<setprecision(2)<<calculateCharges(hours[0])<<endl;

    cout<<setw(8)<<left<<"2"
        <<setw(8)<<setprecision(1)<<right<<hours[1]
        <<setw(8)<<setprecision(2)<<calculateCharges(hours[1])<<endl;

    cout<<setw(8)<<left<<"3"
        <<setw(8)<<setprecision(1)<<right<<hours[2]
        <<setw(8)<<setprecision(2)<<calculateCharges(hours[2])<<endl;

    cout<<setw(8)<<left<<"TOTAL"
        <<setw(8)<<setprecision(1)<<right<<hours[0]+hours[1]+hours[2]
        <<setw(8)<<setprecision(2)<<    calculateCharges(hours[0])+
                                        calculateCharges(hours[1])+
                                        calculateCharges(hours[2])  <<endl;
}
