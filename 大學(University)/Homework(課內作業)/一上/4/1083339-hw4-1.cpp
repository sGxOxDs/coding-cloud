// Huge integer addition, subtraction, multiplication and division
#include <iostream>
#include <string.h>
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
void input( istream &inFile, int hugeInt[], int &size );

// perform addition, subtraction, multiplication and division
void perform( ostream &outFile, int hugeInt1[], int hugeInt2[], int hugeInt3[],
              int hugeInt4[], int size1, int size2, int size3, int size4 );

// output the specified huge integer
void output( ostream &outFile, int hugeInt[], int size );

// returns true if and only if the specified huge integer is zero
bool isZero( int hugeInt[], int size );

// return true if and only if hugeInt1 == hugeInt2
bool equal( int hugeInt1[], int hugeInt2[], int size1, int size2 );

// returns true if and only if hugeInt1 < hugeInt2
bool less( int hugeInt1[], int hugeInt2[], int size1, int size2 );

// sum = addend + adder
void addition( int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize );

// difference = minuend - subtrahend
void subtraction( int minuend[], int subtrahend[], int difference[],
                  int minuendSize, int subtrahendSize, int &differenceSize );

// product = multiplicand * multiplier
void multiplication( int multiplicand[], int multiplier[], int product[],
                     int multiplicandSize, int multiplierSize, int &productSize );

// quotient = dividend / divisor; remainder = dividend % divisor
void division( int dividend[], int divisor[], int quotient[], int remainder[],
               int dividendSize, int divisorSize, int &quotientSize, int &remainderSize );

// hugeInt /= 10
void divideBy10( int hugeInt[], int &size );

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

   for( int i = 0; i < numTestCases; i++ )
   {
      int hugeInt1[ arraySize ] = {};
      int hugeInt2[ arraySize ] = {};
      int hugeInt3[ arraySize ] = {};
      int hugeInt4[ arraySize ] = {};
      int size1 = 1;
      int size2 = 1;
      int size3 = 1;
      int size4 = 1;

      input(inFile, hugeInt1, size1);
      input( inFile, hugeInt2, size2 );
      perform( cout, hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4 );
      perform( outFile, hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4 );
   }

   inFile.close();
   outFile.close();

   system( "pause" );
}

// enable user to input a positive huge integer
void input( istream &inFile, int hugeInt[], int &size )
{
   char numericString[ arraySize ];

   inFile >> numericString;

   size = strlen( numericString );
   for( int i = 0; i < size; ++i )
      hugeInt[ i ] = numericString[ size - i - 1 ] - '0';
}

// perform addition, subtraction, multiplication and division
void perform( ostream &outFile, int hugeInt1[], int hugeInt2[], int hugeInt3[],
              int hugeInt4[], int size1, int size2, int size3, int size4 )
{
   output( outFile, hugeInt1, size1 );
   output( outFile, hugeInt2, size2 );

   // hugeInt3 = hugeInt1 + hugeInt2
   addition( hugeInt1, hugeInt2, hugeInt3, size1, size2, size3 );
   output( outFile, hugeInt3, size3 );

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

   // hugeInt3 = hugeInt1 * hugeInt2
   multiplication( hugeInt1, hugeInt2, hugeInt3, size1, size2, size3 );
   output( outFile, hugeInt3, size3 ); // outputs n1 * n2

   if( isZero( hugeInt2, size2 ) )
   {
      outFile << "DivideByZero!\n";
      outFile << "DivideByZero!\n";
   }
   else
   {
      division( hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4 );
      output( outFile, hugeInt3, size3 );         // outputs n1 / n2
      output( outFile, hugeInt4, size4 );         // outputs n1 % n2
   }

   outFile << endl;
}

// output the specified huge integer
void output( ostream &outFile, int hugeInt[], int size )
{
   if( isZero( hugeInt, size ) )
      outFile << 0;
   else
      for( int i = size - 1; i >= 0; i-- )
         if( hugeInt[ i ] < 10 )
            outFile << hugeInt[ i ];

   outFile << endl;
}

// returns true if and only if the specified huge integer is zero
bool isZero( int hugeInt[], int size )
{
   for( int i = 0; i < size; i++ )
      if( hugeInt[ i ] != 0 )
         return false;
   return true;
}

// return true if and only if hugeInt1 == hugeInt2
bool equal( int hugeInt1[], int hugeInt2[], int size1, int size2 )
{
    if(size1<size2) /*е硉ノ计ゑ*/
    {
        return false;
    }
    else if(size1>size2)
    {
        return false;
    }
    else
    {
        for(int i=size1 - 1;i>=0;i--) /*硋浪琩*/
        {
            if(hugeInt1[i]<hugeInt2[i])
            {
                return false;
            }
            else if(hugeInt1[i]>hugeInt2[i])
            {
                return false;
            }
        }
        return true;
    }
}

// returns true if and only if hugeInt1 < hugeInt2
bool less( int hugeInt1[], int hugeInt2[], int size1, int size2 )
{
    if(size1<size2) /*е硉ノ计ゑ*/
    {
        return true;
    }
    else if(size1>size2)
    {
        return false;
    }
    else
    {
        for(int i=size1 - 1;i>=0;i--) /*硋浪琩*/
        {
            if(hugeInt1[i]<hugeInt2[i])
            {
                return true;
            }
            else if(hugeInt1[i]>hugeInt2[i])
            {
                return false;
            }
        }
        if(hugeInt1[0]==hugeInt2[0]) /*ㄢ计琌false*/
            return false;
    }
}

// sum = addend + adder
void addition( int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize )
{
   sumSize = ( addendSize >= adderSize ) ? addendSize + 1 : adderSize + 1;

   for( int i = 0; i < addendSize; i++ )
      sum[ i ] = addend[ i ];

   for( int i = addendSize; i < sumSize; i++ )
      sum[ i ] = 0;

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
void subtraction( int minuend[], int subtrahend[], int difference[],
                  int minuendSize, int subtrahendSize, int &differenceSize )
{
    differenceSize=minuendSize;
    for( int i = 0; i < minuendSize; i++ )
        difference[ i ] = minuend[ i ];

    for( int i = minuendSize; i < differenceSize; i++ )
        difference[ i ] = 0;

    for( int i = 0; i < subtrahendSize; i++ )
        difference[ i ] = difference[ i ] - subtrahend[ i ];

    for( int i = 0; i < differenceSize - 1; i++ ) /*秈*/
        if( difference[ i ] < 0 )
        {
            difference[ i ] = difference[ i ]+10;
            difference[ i + 1 ]--;
        }

    for( int i = differenceSize - 1; i >= 0 ; i-- ) /*埃0*/
        if( difference[ i ] == 0 )
        {
            differenceSize--;
        }
        else
        {
            break;
        }
}

// product = multiplicand * multiplier
void multiplication( int multiplicand[], int multiplier[], int product[],
                     int multiplicandSize, int multiplierSize, int &productSize )
{
    productSize=multiplicandSize+multiplierSize; /*4计*1计 程4+1计*/

    for( int i = 0; i < productSize; i++ ) /*籹*/
        product[ i ] = 0;

    for( int i = 0; i < multiplierSize; i++ )
        for( int j = 0; j < multiplicandSize; j++ )
            product[ i+j ] = product[ i+j ] + multiplier[ i ] * multiplicand[ j ];

    for( int i = 0; i < productSize - 1; i++ ) /*秈*/
    {
        if(product[i]>9)
        {
            product[i+1]=product[i+1]+product[i]/10;
            product[i]=product[i]%10;
        }
    }

    for( int i = productSize - 1; i >= 0 ; i-- ) /*埃0*/
        if( product[ i ] == 0 )
        {
            productSize--;
        }
        else
        {
            break;
        }
}

// quotient = dividend / divisor; remainder = dividend % divisor
void division( int dividend[], int divisor[], int quotient[], int remainder[],
               int dividendSize, int divisorSize, int &quotientSize, int &remainderSize )
{
    if(dividend[0] == 0 && dividendSize == 1)
    {
        quotient[0] = 0;
        remainder[0] = 0;
        quotientSize = 1;
        remainderSize = 1;
        return;
    }
    remainderSize = dividendSize;
    for(int i=0;i<dividendSize;i++)
        remainder[i] = dividend[i];
    if( less(dividend, divisor, dividendSize, divisorSize))
    {
        quotient[0] = 0;
        quotientSize = 1;
    }
    else
    {
        int n = dividendSize - divisorSize;
        int buffer[divisorSize + n],bufferSize = divisorSize + n;
        for(int i=n;i<bufferSize;i++)
            buffer[i]=divisor[i-n];
        for(int i=0;i<n;i++)
            buffer[i]=0;
        quotientSize = dividendSize - divisorSize;
        if( less(dividend, buffer, dividendSize, bufferSize))
        {
            divideBy10(buffer, bufferSize);
        }
        else
        {
            quotientSize++;
        }
        for(int i=0;i<quotientSize;i++)
            quotient[i]=0;
        for(int k=quotientSize-1;k>=0;k--)
        {
            while( less(buffer, remainder, bufferSize, remainderSize) || equal(buffer, remainder, bufferSize, remainderSize))
            {
                int tempArray[arraySize],tempArraySize=1;
                subtraction(remainder, buffer, tempArray, remainderSize, bufferSize, tempArraySize);
                for(int i=0;i<tempArraySize;i++)
                    remainder[i]=tempArray[i];
                for(int i=tempArraySize;i<remainderSize;i++)
                    remainder[i]=0;
                remainderSize=tempArraySize;
                quotient[k]++;
                if(remainder[0]==0 && remainderSize==1)
                    return;
            }
            divideBy10(buffer, bufferSize);
        }
        for( int i = remainderSize - 1; i >= 0 ; i-- ) /*埃0*/
        if( remainder[ i ] == 0 )
        {
            remainderSize--;
        }
        else
        {
            break;
        }
    }
}

// hugeInt /= 10
void divideBy10( int hugeInt[], int &size )
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
