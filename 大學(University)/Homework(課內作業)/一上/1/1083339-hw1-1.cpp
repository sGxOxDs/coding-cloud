#include <iostream> // allows program to perform input and output
using namespace std; // program uses names from the std namespace

int main()
{
   int number; // integer read from user

   cout << "Enter an integer: "; // prompt
   cin >> number; // read integer from user
   if(number%2==0)cout<<"The integer "<<number<<" is even."<<endl;
   if(number%2==1)cout<<"The integer "<<number<<" is odd."<<endl;
    //The integer 73 is odd. The integer 74 is even.
   system( "pause" );
} // end main
