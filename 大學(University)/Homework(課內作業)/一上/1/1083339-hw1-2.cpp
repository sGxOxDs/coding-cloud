#include <iostream> // allows program to perform input and output
using namespace std; // program uses names from the std namespace

int main()
{
   string number; // integer read from user

   cout << "Enter a five-digit integer: "; // prompt
   cin >> number; // read integer from user
   for(int i=0;i<number.length();i++)
   {
       char c=number.at(i);
       if(i<number.length()-1)
       {
           cout<<c<<" ";
       }
       else
       {
           cout<<c<<endl;
       }
   }
   system( "pause" );
} // end main
