// Member-function definitions for class HugeInteger
#include <iostream>
using namespace std;
#include "HugeInteger.h" // include definition of class HugeInteger

// default constructor; construct a zero HugeInteger with size 1
HugeInteger::HugeInteger()
   : integer( 1 )
{
}

// constructor; construct a zero HugeInteger with size n
HugeInteger::HugeInteger( unsigned int n )
   : integer( ( n > 0 ) ? n : 1 )
{
} // end HugeInteger constructor

// copy constructor
// constructs a HugeInteger with a copy of each of the elements in integerToCopy
HugeInteger::HugeInteger( const HugeInteger &integerToCopy )
   : integer( integerToCopy.integer )
{
} // end HugeInteger copy constructor

// destructor; destroys the HugeInteger
HugeInteger::~HugeInteger()
{
} // end HugeInteger destructor

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const HugeInteger &HugeInteger::assign( const HugeInteger &right )
{
   if( &right != this ) // avoid self-assignment
      integer.assign( right.integer );

   return *this; // enables x = y = z, for example
}

// function that tests if two HugeIntegers are equal
bool HugeInteger::equal( const HugeInteger &right ) const
{
    if (integer.size() < right.integer.size())
        return false;
    else if (integer.size() > right.integer.size())
        return false;
    else
    {
        for (int i = integer.size() - 1; i >= 0; i--)
        {
            if (integer.begin()[i] < right.integer.begin()[i])
                return false;
            else if (integer.begin()[i] > right.integer.begin()[i])
                return false;
        }
        return true;
    }
} // end function equal

// function that tests if one HugeInteger is less than another
bool HugeInteger::less( const HugeInteger &right ) const
{
    if (integer.size() < right.integer.size())
        return true;
    else if (integer.size() > right.integer.size())
        return false;
    else
    {
        for (int i = integer.size() - 1; i >= 0; i--)
        {
            if (integer.begin()[i] < right.integer.begin()[i])
                return true;
            else if (integer.begin()[i] > right.integer.begin()[i])
                return false;
        }
        if (integer.begin()[0] == right.integer.begin()[0])
            return false;
    }
} // end function less

// function that tests if one HugeInteger is less than or equal to another
bool HugeInteger::lessEqual( const HugeInteger &right ) const
{
   return ( less( right ) || equal( right ) );
} // end function lessEqual

// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::add( HugeInteger &op2 )
{
   unsigned int op1Size = integer.size();
   unsigned int op2Size = op2.integer.size();
   unsigned int sumSize = ( op1Size >= op2Size ) ? op1Size + 1 : op2Size + 1;

   HugeInteger sum( sumSize );

   vector::iterator it1 = integer.begin();
   vector::iterator it3 = sum.integer.begin();
   for( ; it1 != integer.end(); ++it1, ++it3 )
      *it3 = *it1;

   vector::iterator it2 = op2.integer.begin();
   for( it3 = sum.integer.begin(); it2 != op2.integer.end(); ++it2, ++it3 )
      *it3 += *it2;

   for( it3 = sum.integer.begin(); it3 != sum.integer.end() - 1; ++it3 )
      if( *it3 > 9 )
      {
         ( *it3 ) -= 10;
         ( *( it3 + 1 ) )++;
      }

   if( *it3 == 0 )
      sum.integer.pop_back();

   return sum;
} // end function add

// subtraction operator; HugeInteger - HugeInteger
HugeInteger HugeInteger::subtract( HugeInteger &op2 )
{
   HugeInteger zero;

   if( equal( op2 ) )
      return zero;

   unsigned int op1Size = integer.size();
   unsigned int op2Size = op2.integer.size();

   HugeInteger difference(*this);

   vector::iterator it1 = integer.begin();
   vector::iterator it2 = op2.integer.begin();
   vector::iterator it3 = difference.integer.begin();

   for (int i = 0; i < op2Size; i++)
       it3[i] -= it2[i];

   for (int i = 0; i < op1Size - 1; i++)
       if (it3[i] < 0)
       {
           it3[i] += 10;
           it3[i + 1]--;
       }

   for (int i = op1Size - 1; i >= 0; i--)
       if (it3[i] == 0)
           difference.integer.pop_back();
       else
           break;

   return difference;
} // end function subtract

// multiplication operator; HugeInteger * HugeInteger
HugeInteger HugeInteger::multiply( HugeInteger &op2 )
{
   HugeInteger zero;
   if( isZero() || op2.isZero() )
      return zero;
   unsigned int multiplierSize = integer.size();
   unsigned int multiplicandSize = op2.integer.size();

   unsigned int productSize = integer.size() + op2.integer.size();
   HugeInteger product( productSize );

   vector::iterator it1 = integer.begin();
   vector::iterator it2 = op2.integer.begin();
   vector::iterator it3 = product.integer.begin();

   for (int i = 0; i < productSize; i++)
       it3[i] = 0;

   for (int i = 0; i < multiplierSize; i++)
       for (int j = 0; j < multiplicandSize; j++)
           it3[i + j] += it1[i] * it2[j];

   for (int i = 0; i < productSize - 1; i++)
   {
       if (it3[i] > 9)
       {
           it3[i + 1] += it3[i] / 10;
           it3[i] = it3[i] % 10;
       }
   }

   for (int i = productSize - 1; i >= 0; i--)
       if (it3[i] == 0)
           product.integer.pop_back();
       else
           break;

   return product;
} // end function multiply

// division operator; HugeInteger / HugeInteger provided that op2 is not zero
HugeInteger HugeInteger::divide( HugeInteger &op2 )
{
    HugeInteger zero;
    if( less( op2 ) )
       return zero;
    /*HugeInteger quotient;
    return quotient;*/

    /*HugeInteger quotient( integer.size() - op2.integer.size() + 1 );
    HugeInteger remainder;
    remainder.assign(*this);

    int n = integer.size() - op2.integer.size();
    HugeInteger buffer( integer.size() );
    vector::iterator it1 = integer.begin();
    vector::iterator it2 = op2.integer.begin();
    vector::iterator it3 = quotient.integer.begin();
    for (int i = 0; i < buffer.integer.size(); i++)
    {
        if (i < n)
            buffer.integer.begin()[i] = 0;
        else
            buffer.integer.begin()[i] = it2[i-n];
    }
    if ( less( buffer ) )
    {
        buffer.divideByTen();
        quotient.integer.pop_back();
    }
    for (int k = quotient.integer.size() - 1; k >= 0; k++)
    {
        while (buffer.lessEqual(remainder))
        {
            HugeInteger temp = remainder.subtract(buffer);
            remainder.assign(temp);
            it3[k]++;
            if (remainder.isZero())
                return quotient;
        }
        buffer.divideByTen();
    }
    return quotient;*/

    else if ( equal( op2 ) )
    {
        HugeInteger quotient;
        quotient.integer.begin()[0] = 1;
        return quotient;
    }
    else
    {
        unsigned int dividendSize = integer.size();
        unsigned int divisorSize = op2.integer.size();

        unsigned int bufferSize = dividendSize;
        HugeInteger buffer(bufferSize);

        unsigned int quotientSize = dividendSize - divisorSize + 1;
        HugeInteger quotient(quotientSize);

        vector::iterator it1 = integer.begin();
        vector::iterator it2 = op2.integer.begin();
        vector::iterator it3 = quotient.integer.begin();
        vector::iterator it4 = buffer.integer.begin();

        //for (int i = quotientSize; i < bufferSize; i++)
            //it4[i] = it2[i - quotientSize];
        //for (int i = 0; i < quotientSize; i++)
            //it4[i] = 0;

        //if (less( buffer ) )
        //{
           //quotient.integer.pop_back();
           //quotientSize--;
        //}

        //for (int i = 0; i < quotientSize; i++)
            //it3[i] = 0;

        for (int k = quotientSize - 1; k >= 0; k--)
        {
            it3[k] = 10;
            do {
                it3[k]--;
                buffer.assign( op2.multiply(quotient) );
            } while (less(buffer));
            if (equal(buffer))
                break;
        }
        for (int i = quotientSize - 1; i >= 0; i--)
        {
            if (it3[i] == 0)
                quotient.integer.pop_back();
            else
                break;
        }
        //quotient.output(cout);
        return quotient;
    }


    
   
} // end function divide

// modulus operator; HugeInteger % HugeInteger provided that op2 is not zero
HugeInteger HugeInteger::modulus( HugeInteger &op2 )
{
   HugeInteger quotient = divide( op2 );
   HugeInteger product = quotient.multiply( op2 );
   HugeInteger remainder = subtract( product );
   return remainder;
}

// convert a vector of decimal digits into a HugeInteger
void HugeInteger::convert( vector &v )
{
   integer.resize( v.size() );
   vector::iterator it1 = integer.end() - 1;
   vector::iterator it2 = v.begin();
   for( ; it2 != v.end(); --it1, ++it2 )
      *it1 = *it2;
} // end function convert

// function that tests if a HugeInteger is zero
bool HugeInteger::isZero()
{
   for( vector::iterator it = integer.begin(); it != integer.end(); ++it )
      if ( *it != 0 )
         return false;
         
   return true;
}

// function that divides a HugeInteger by 10; shift a HugeInteger one position to the right
void HugeInteger::divideByTen()
{
   vector::iterator it = integer.begin();
   vector::iterator it2 = it;
   for( ++it2; it2 != integer.end(); ++it, ++it2 )
      *it = *it2;
   integer.pop_back();
}

// overloaded output operator
void HugeInteger::output( ostream &outFile )
{
   vector::iterator it = integer.end() - 1;
   for( ; it != integer.begin() - 1; --it )
      if( *it < 10 )
         outFile << *it;
   outFile << endl;
} // end function output