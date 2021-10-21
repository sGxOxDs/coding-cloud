#include <iostream>
#include <iomanip>
//攝氏與華氏溫度轉換器
using namespace std;

double ConvertToCelsius(double temperature)
{
    return (temperature-32)*5/9;
}

double ConvertToFahrenheit(double temperature)
{
    return temperature*1.8+32.0;
}

int main()
{
    int choose_conversion,low_bond,up_bond;
    cout<<"Please choose which conversion you want to use:\n"
        <<"1.Celsius to Fahrenheit\n"
        <<"2. Fahrenheit to Celsius"<<endl;
    cin>>choose_conversion;
    cout<<"Please input the lower bond and upper bond of the temperature you want to convert:"<<endl;
    cout<<"lower bond: ";
    cin>>low_bond;
    cout<<"upper bond: ";
    cin>>up_bond;

    if(choose_conversion!=1&&choose_conversion!=2)
    {
        cout<<"wrong choose"<<endl;
        system("pause");
        return 0;
    }
    else if(low_bond>up_bond)
    {
        cout<<"wrong bond"<<endl;
        system("pause");
        return 0;
    }
    cout<<endl;
    cout<<setw(8)<<right<<"Celsius"
        <<setw(12)<<"Fahrenheit"
        <<setw(12)<<"Celsius"
        <<setw(12)<<"Fahrenheit"<<endl;
    for(int i=0;i<44;i++)
        cout<<"-";
    cout<<fixed<<setprecision(1)<<endl;
    //cout<<endl;
    if(choose_conversion==1)
    {
        for(int i=low_bond,j=(low_bond+up_bond)/2+1;i<(low_bond+up_bond)/2+1&&j<=up_bond;i++,j++)
        {
            cout<<setw(8)<<i+0.0
                <<setw(12)<<ConvertToFahrenheit(i)
                <<setw(12)<<j+0.0
                <<setw(12)<<ConvertToFahrenheit(j)<<endl;
        }
        if((low_bond+up_bond)/2.0-0.5!=(low_bond+up_bond)/2)
        {
            cout<<setw(8)<<(low_bond+up_bond)/2+0.0
                <<setw(12)<<ConvertToFahrenheit((low_bond+up_bond)/2)<<endl;
        }

    }
    else if(choose_conversion==2)
    {
        for(int i=low_bond,j=(low_bond+up_bond)/2+1;i<(low_bond+up_bond)/2+1&&j<=up_bond;i++,j++)
        {
            cout<<setw(8)<<ConvertToCelsius(i)
                <<setw(12)<<i+0.0
                <<setw(12)<<ConvertToCelsius(j)
                <<setw(12)<<j+0.0<<endl;
        }
        if((low_bond+up_bond)/2.0-0.5!=(low_bond+up_bond)/2)
        {
            cout<<setw(8)<<ConvertToCelsius((low_bond+up_bond)/2)
                <<setw(12)<<(low_bond+up_bond)/2+0.0<<endl;
        }
    }
}
