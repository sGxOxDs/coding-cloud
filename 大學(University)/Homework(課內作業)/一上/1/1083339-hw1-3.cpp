// Determine whether a number is a palindrome.
#include <iostream>
using namespace std;

int main()
{
   string number; // user input number
   cout << "Enter a 5-digit number: "; // prompt for a number
   cin >> number; // get number
   int c=0,c_ount=number.length();
   for(int i=0;i<number.length();i++)
   {
       for(int j=number.length()-1;j>=0;j--)
       {
           if(number.at(i)==number.at(j)) c++;
       }
   }
   if(c==c_ount)
   {
       cout<<number<<" is not a palindrome."<<endl;
   }
   else
   {
       cout<<number<<" is a palindrome!!!"<<endl;
   }

   system( "pause" );
} // end main
