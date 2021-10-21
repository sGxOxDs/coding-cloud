// Determine whether three values represent the sides of a right triangle.
#include <iostream>
using namespace std;

int main()
{
   int side[3];

   // get values of three sides
   cout << "Enter side 1: ";
   cin >> side[0];

   cout << "Enter side 2: ";
   cin >> side[1];

   cout << "Enter side 3: ";
   cin >> side[2];

   for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(side[i]<side[j]){int temp=side[i];side[i]=side[j];side[j]=temp;}

   if(side[2]*side[2]==side[0]*side[0]+side[1]*side[1])
   {
       cout<<"These are the sides of a right triangle."<<endl;
   }
   else
   {
       cout<<"These do not form a right triangle."<<endl;
   }

   system( "pause" );
} // end main
