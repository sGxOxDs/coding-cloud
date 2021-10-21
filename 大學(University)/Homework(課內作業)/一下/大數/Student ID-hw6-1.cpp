// Huge integer addition, subtraction, multiplication and division
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::ios;

// enable user to input a positive huge integer
void input( istream &inFile, int *&hugeInt, int &size );

// perform addition, subtraction, multiplication and division
void perform( ostream &outFile, int *hugeInt1, int *hugeInt2, int *&hugeInt3,
              int *&hugeInt4, int size1, int size2, int size3, int size4 );

void reset( int *&hugeInt, int &size );

// outputs hugeInt[ size - 1 .. 0 ]
void output( ostream &outFile, int *hugeInt, int size );

// a recursive function that outputs hugeInt[ last .. 0 ]
void recursiveOutput( ostream &outFile, int *hugeInt, int last );

// returns true if and only if the specified huge integer is zero
bool isZero( int *hugeInt, int size );

// return true if and only if hugeInt1 == hugeInt2
bool equal( int *hugeInt1, int *hugeInt2, int size1, int size2 );

// a recursive function that returns true if and only if hugeInt1 == hugeInt2
// provided that size1 == size2
bool recursiveEqual( int *hugeInt1, int *hugeInt2, int last );

// returns true if and only if hugeInt1 < hugeInt2
bool less( int *hugeInt1, int *hugeInt2, int size1, int size2 );

// a recursive function that returns true if and only if hugeInt1 < hugeInt2
// provided that size1 == size2
bool recursiveLess( int *hugeInt1, int *hugeInt2, int last );

// sum = addend + adder
void addition( int *addend, int *adder, int *&sum, int addendSize, int adderSize, int &sumSize );

// difference = minuend - subtrahend
void subtraction( int *minuend, int *subtrahend, int *&difference,
                  int minuendSize, int subtrahendSize, int &differenceSize );

// product = multiplicand * multiplier
void multiplication( int *multiplicand, int *multiplier, int *&product,
                     int multiplicandSize, int multiplierSize, int &productSize );

// quotient = dividend / divisor; remainder = dividend % divisor
void division( int *dividend, int *divisor, int *&quotient, int *&remainder,
               int dividendSize, int divisorSize, int &quotientSize, int &remainderSize );

// hugeInt /= 10
void divideBy10( int *hugeInt, int &size );

const int numTestCases = 22; // the number of test cases
const int arraySize = 200;

int main()
{
   system( "mode con cols=122" );

   ifstream inFile( "Test cases.txt", ios::in );

   // exit program if ifstream could not open file
   if( !inFile )
   {
      cout << "File could not be opened" << endl;
      system( "pause" );
      exit( 1 );
   }

   ofstream outFile( "Result.txt", ios::out );

   // exit program if ofstream could not open file
   if( !outFile )
   {
      cout << "File could not be opened" << endl;
      system( "pause" );
      exit( 1 );
   }   

   int *hugeInt1 = new int[ 1 ]();
   int *hugeInt2 = new int[ 1 ]();
   int *hugeInt3 = new int[ 1 ]();
   int *hugeInt4 = new int[ 1 ]();
   int size1 = 1;
   int size2 = 1;
   int size3 = 1;
   int size4 = 1;

   for( int i = 0; i < numTestCases; i++ )
   {
      input( inFile, hugeInt1, size1 );
      input( inFile, hugeInt2, size2 );
      perform( cout, hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4 );
      perform( outFile, hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4 );
   }

   delete[] hugeInt1;
   delete[] hugeInt2;
   delete[] hugeInt3;
   delete[] hugeInt4;

   inFile.close();
   outFile.close();

   system( "pause" );
}

// enable user to input a positive huge integer
void input( istream &inFile, int *&hugeInt, int &size )
{
   char numericString[ arraySize ];

   inFile >> numericString;

   size = strlen( numericString );
   delete[] hugeInt;
   hugeInt = new int[ size ];
   for( int i = 0; i < size; ++i )
      hugeInt[ i ] = numericString[ size - i - 1 ] - '0';
}

// perform addition, subtraction, multiplication and division
void perform( ostream &outFile, int *hugeInt1, int *hugeInt2, int *&hugeInt3,
              int *&hugeInt4, int size1, int size2, int size3, int size4 )
{
   output( outFile, hugeInt1, size1 );
   output( outFile, hugeInt2, size2 );

   // hugeInt3 = hugeInt1 + hugeInt2
   addition( hugeInt1, hugeInt2, hugeInt3, size1, size2, size3 );
   output( outFile, hugeInt3, size3 );
   reset( hugeInt3, size3 );

   // if hugeInt1 < hugeInt2
   if( less( hugeInt1, hugeInt2, size1, size2 ) )
   {
      outFile << '-';
      // hugeInt3 = hugeInt2 - hugeInt1
      subtraction( hugeInt2, hugeInt1, hugeInt3, size2, size1, size3 );
      output( outFile, hugeInt3, size3 ); // outputs n2 - n1
   }
   else
   {
      // hugeInt3 = hugeInt1 - hugeInt2
      subtraction( hugeInt1, hugeInt2, hugeInt3, size1, size2, size3 );
      output( outFile, hugeInt3, size3 ); // outputs n1 - n2
   }
   reset( hugeInt3, size3 );

   // hugeInt3 = hugeInt1 * hugeInt2
   multiplication( hugeInt1, hugeInt2, hugeInt3, size1, size2, size3 );
   output( outFile, hugeInt3, size3 ); // outputs n1 * n2
   reset( hugeInt3, size3 );

   if( isZero( hugeInt2, size2 ) )
   {
      outFile << "DivideByZero!\n";
      outFile << "DivideByZero!\n";
   }
   else
   {
      division( hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4 );
      output( outFile, hugeInt3, size3 ); // outputs n1 / n2
      output( outFile, hugeInt4, size4 ); // outputs n1 % n2
      reset( hugeInt3, size3 );
      reset( hugeInt4, size4 );
   }

   outFile << endl;
}

void reset( int *&hugeInt, int &size )
{
   size = 1;
   delete[] hugeInt;
   hugeInt = new int[ 1 ]();
}

// outputs hugeInt[ size - 1 .. 0 ]
void output( ostream &outFile, int *hugeInt, int size )
{
   recursiveOutput( outFile, hugeInt, size - 1 );
   outFile << endl;
}

// a recursive function that outputs hugeInt[ last .. 0 ]
void recursiveOutput( ostream &outFile, int *hugeInt, int last )
{

}

// returns true if and only if the specified huge integer is zero
bool isZero( int *hugeInt, int size )
{
   if( size == 1 && hugeInt[ 0 ] == 0 )
      return true;
   return false;
}

// return true if and only if hugeInt1 == hugeInt2
bool equal( int *hugeInt1, int *hugeInt2, int size1, int size2 )
{
   if( size1 != size2 )
      return false;

   return recursiveEqual( hugeInt1, hugeInt2, size1 - 1 );
}

// a recursive function that returns true if and only if hugeInt1 == hugeInt2
// provided that size1 == size2
bool recursiveEqual( int *hugeInt1, int *hugeInt2, int last )
{

}

// returns true if and only if hugeInt1 < hugeInt2
bool less( int *hugeInt1, int *hugeInt2, int size1, int size2 )
{
   if( size1 < size2 )
      return true;
   if( size1 > size2 )
      return false;

   return recursiveLess( hugeInt1, hugeInt2, size1 - 1 );
}

// a recursive function that returns true if and only if hugeInt1 < hugeInt2
// provided that size1 == size2
bool recursiveLess( int *hugeInt1, int *hugeInt2, int last )
{

}

// sum = addend + adder
void addition( int *addend, int *adder, int *&sum, int addendSize, int adderSize, int &sumSize )
{
   sumSize = ( addendSize >= adderSize ) ? addendSize + 1 : adderSize + 1;

   delete[] sum;
   sum = new int[ sumSize ]();

   for( int i = 0; i < addendSize; i++ )
      sum[ i ] = addend[ i ];

   for( int i = 0; i < adderSize; i++ )
      sum[ i ] += adder[ i ];

   for( int i = 0; i < sumSize - 1; i++ )
      if( sum[ i ] > 9 ) // carrying
      {
         sum[ i ] -= 10;
         sum[ i + 1 ]++;
      }

   if( sum[ sumSize - 1 ] == 0 )
      sumSize--;
}

// difference = minuend - subtrahend
void subtraction( int *minuend, int *subtrahend, int *&difference,
                  int minuendSize, int subtrahendSize, int &differenceSize )
{

}

// product = multiplicand * multiplier
void multiplication( int *multiplicand, int *multiplier, int *&product,
                     int multiplicandSize, int multiplierSize, int &productSize )
{

}

// quotient = dividend / divisor; remainder = dividend % divisor
void division( int *dividend, int *divisor, int *&quotient, int *&remainder,
               int dividendSize, int divisorSize, int &quotientSize, int &remainderSize )
{
   if( isZero( dividend, dividendSize ) )
   {
      reset( quotient, quotientSize );
      reset( remainder, remainderSize );
      return;
   }


}

// hugeInt /= 10
void divideBy10( int *hugeInt, int &size )
{
   if( size == 1 )
      hugeInt[ 0 ] = 0;
   else
   {
      for( int i = 1; i < size; i++ )
         hugeInt[ i - 1 ] = hugeInt[ i ];

      size--;
      hugeInt[ size ] = 0;
   }
}