#include <iostream>
using namespace std;

int main()
{
    int a,b,c;bool f=true;
    cout<<"all Armstrong numbers of three digits:"<<endl;
    for(int x=1;x<10;x++)
    {
        for(int y=0;y<10;y++)
        {
            for(int z=0;z<10;z++)
            {
                if(x*x*x+y*y*y+z*z*z==x*100+y*10+z&&f)
                {
                    cout<<x<<y<<z;
                    f=false;
                }
                else if(x*x*x+y*y*y+z*z*z==x*100+y*10+z)
                {
                    cout<<" "<<x<<y<<z;
                }
            }
        }
    }
    cout<<endl;
    system("pause");
}
