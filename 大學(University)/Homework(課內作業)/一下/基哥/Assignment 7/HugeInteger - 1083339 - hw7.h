// HugeInteger class template definition.
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

//#include "Vector.h" // include definition of class template vector
//#include "List.h"   // include definition of class template list
#include "Vector - 1083339 - hw7.h"
#include "List - 1083339 - hw7.h"

/*
#include <vector> // include definition of class template vector
#include <list>   // include definition of class template list
using std::vector;
using std::list;
*/

template< typename T >
class HugeInteger
{
   template< typename T >
   friend ostream& operator<<( ostream &output, HugeInteger< T > hugeInteger );
public:
   HugeInteger( size_t n = 0 ); // constructor; construct a zero HugeInteger with mySize n

   // copy constructor; constructs a HugeInteger with a copy of each of the elements in integerToCopy
   HugeInteger( const HugeInteger &integerToCopy );

   ~HugeInteger(); // destructor; destroys the HugeInteger

   const HugeInteger& operator=( const HugeInteger &right ); // assignment operator

   bool operator==( HugeInteger &right ); // less than or equal to
   bool operator<( HugeInteger &right );  // less than
   bool operator<=( HugeInteger &right ); // less than or equal to

   // addition operator; HugeInteger + HugeInteger
   HugeInteger operator+( HugeInteger &op2 );

   // subtraction operator; HugeInteger - HugeInteger provided that
   // the minuend is greater than or equal to the subtrahend
   HugeInteger operator-( HugeInteger &op2 );

   // multiplication operator; HugeInteger * HugeInteger
   HugeInteger operator*( HugeInteger &op2 );

   // division operator; HugeInteger / HugeInteger
   // provided that the divisor is not equal to 0
   HugeInteger operator/( HugeInteger &op2 );

   // modulus operator; HugeInteger % HugeInteger
   // provided that the divisor is not equal to 0
   HugeInteger operator%( HugeInteger &op2 );

   HugeInteger& operator++(); // prefix increment operator
     
   HugeInteger operator++( int ); // postfix increment operator

   HugeInteger& operator--(); // prefix decrement operator

   HugeInteger operator--( int ); // postfix decrement operator

   bool isZero(); // return true if and only if all digits are zero

   void convert( T &v ); // convert a vector of decimal digits into a HugeInteger

private:
   T integer;

   void divideByTen();            // divides a HugeInteger by 10
   void helpIncrement();          // increments a HugeInteger by 1
   void helpDecrement();          // decrements a HugeInteger by 1
}; // end class template HugeInteger

#endif


// constructor; construct a zero HugeInteger with mySize n
template< typename T >
HugeInteger< T >::HugeInteger( size_t n )
   : integer( ( n > 0 ) ? n : 1 )
{
}

// copy constructor; constructs a HugeInteger with a copy of each of the elements in integerToCopy
template< typename T >
HugeInteger< T >::HugeInteger( const HugeInteger< T > &integerToCopy )
   : integer( integerToCopy.integer )
{
}

// destructor; destroys the HugeInteger
template< typename T >
HugeInteger< T >::~HugeInteger()
{
}

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
template< typename T >
const HugeInteger< T >& HugeInteger< T >::operator=( const HugeInteger< T > &right )
{
   if( &right != this ) // avoid self-assignment
      integer = right.integer;

   return *this; // enables x = y = z, for example
} // end function operator=

// function that tests if two HugeIntegers are equal
template< typename T >
bool HugeInteger< T >::operator==( HugeInteger< T > &right )
{
   return ( integer == right.integer );
} // end function operator==

// function that tests if one HugeInteger< T > is less than another
template< typename T >
bool HugeInteger< T >::operator<( HugeInteger< T > &right )
{
    if (integer.size() < right.integer.size())
        return true;
    else if (integer.size() > right.integer.size())
        return false;
    else
    {
        int i = 0;
        typename T::reverse_iterator it = integer.rbegin();
        typename T::reverse_iterator itr = right.integer.rbegin();
        for (; it != integer.rend() ; it++, itr++)
        {
            if (*it < *itr)
                return true;
            else if (*it > * itr)
                return false;          
        }
        return false;
    }
} // end function operator<

// function that tests if one HugeInteger< T > is less than or equal to another
template< typename T >
bool HugeInteger< T >::operator<=( HugeInteger< T > &right )
{
   return ( *this == right || *this < right );
}

// addition operator; HugeInteger< T > + HugeInteger< T >
template< typename T >
HugeInteger< T > HugeInteger< T >::operator+( HugeInteger< T > &op2 )
{
   size_t op1Size = integer.size();
   size_t op2Size = op2.integer.size();
   size_t sumSize = ( op1Size >= op2Size ) ? op1Size + 1 : op2Size + 1;

   HugeInteger< T > sum( sumSize );
   typename T::iterator it1 = integer.begin();
   typename T::iterator it3 = sum.integer.begin();
   for( ; it1 != integer.end(); ++it1, ++it3 )
      *it3 = *it1;

   typename T::iterator it2 = op2.integer.begin();
   it3 = sum.integer.begin();
   for( ; it2 != op2.integer.end(); ++it2, ++it3 )
      *it3 += *it2;

   it3 = sum.integer.begin();
   typename T::iterator it4 = it3;
   for( ++it4; it4 != sum.integer.end(); ++it3, ++it4 )
      if( *it3 > 9 )
      {
         ( *it3 ) -= 10;
         ( *it4 )++;
      }

   if( *it3 == 0 )
      sum.integer.pop_back();

   return sum;
} // end function operator+

// subtraction operator; HugeInteger< T > - HugeInteger< T >
template< typename T >
HugeInteger< T > HugeInteger< T >::operator-( HugeInteger< T > &op2 )
{
   HugeInteger< T > zero;

   if( *this == op2 )
      return zero;

   HugeInteger< T > difference( *this );

   //typename T::iterator it1 = integer.begin();
   //typename T::iterator it2 = op2.integer.begin();
   //typename T::iterator it3 = difference.integer.begin();
   //auto it2 = op2.integer.begin();
   //auto it3 = difference.integer.begin();

   for (auto it3 = difference.integer.begin(); it3 != difference.integer.end(); it3++)
       *it3 += 10;

   for (auto it2 = op2.integer.begin(), it3 = difference.integer.begin(); it2 != op2.integer.end(); it2++, it3++)
       *it3 -= *it2;

   for (auto it3 = difference.integer.begin(); it3 != difference.integer.end(); )
   {
       if (*it3 > 9) 
       {
           *it3 -= 10;
           it3++;
       }
       else if (*it3 >= 0)
       {
           it3++;
           if (it3 != difference.integer.end())
               *it3 -= 1;          
       }
       
   }
   for (auto it3 = difference.integer.rbegin(); it3 != difference.integer.rend(); it3 = difference.integer.rbegin())
       if (*it3 == 0)
           difference.integer.pop_back();
       else
           break;

   return difference;
} // end function operator-

// multiplication operator; HugeInteger< T > * HugeInteger< T >
template< typename T >
HugeInteger< T > HugeInteger< T >::operator*( HugeInteger< T > &op2 )
{
   HugeInteger zero;
   if( isZero() || op2.isZero() )
      return zero;

   size_t op1Size = integer.size();
   size_t op2Size = op2.integer.size();
   size_t productSize = op1Size + op2Size;

   HugeInteger< T > product( productSize );

   //typename T::iterator it1 = integer.begin();
   //typename T::iterator it2 = op2.integer.begin();
   //typename T::iterator it3 = product.integer.begin();

   //for (int i = 0; i < multiplierSize; i++)
   //    for (int j = 0; j < multiplicandSize; j++)
   //        it3[i + j] += it1[i] * it2[j];


   {
       auto it3 = product.integer.begin();
       auto it4 = product.integer.begin();
       for (auto it1 = integer.begin(); it1 != integer.end(); it1++)
       {
           for (auto it2 = op2.integer.begin(); it2 != op2.integer.end(); it2++, it3++)
               *it3 += (*it1) * (*it2);
           it4++;
           for (; it3 != it4; it3--);
       }
   }
       
           

   for (auto it3 = product.integer.begin(); it3 != product.integer.end(); it3++)
   {
       if (*it3 > 9)
       {
           auto temp = *it3 / 10;
           *it3 %= 10;
           it3++;
           *it3 += temp;
           it3--;
       }
   }

   for (auto it3 = product.integer.rbegin(); it3 != product.integer.rend(); it3 = product.integer.rbegin())
       if (*it3 == 0)
           product.integer.pop_back();
       else
           break;

   return product;
} // end function operator*

// division operator; HugeInteger< T > / HugeInteger< T > provided that the divisor is not equal to 0
template< typename T >
HugeInteger< T > HugeInteger< T >::operator/( HugeInteger< T > &op2 )
{
   HugeInteger< T > zero;
   if( *this < op2 )
      return zero;
   
   else if (*this == op2)
   {
       HugeInteger< T > quotient;
       auto it3 = quotient.integer.begin();
       *it3 = 1;
       return quotient;
   }
   else
   {
       unsigned int dividendSize = integer.size();
       unsigned int divisorSize = op2.integer.size();

       unsigned int bufferSize = dividendSize;
       HugeInteger< T >  buffer(bufferSize);

       unsigned int quotientSize = dividendSize - divisorSize + 1;
       HugeInteger< T >  quotient(quotientSize);

       //typename T::iterator it1 = integer.begin();
       //typename T::iterator it2 = op2.integer.begin();
       //typename T::iterator it3 = quotient.integer.begin();
       //typename T::iterator it4 = buffer.integer.begin();
       //auto it1 = integer.begin();
       //auto it2 = op2.integer.begin();
       //auto it3 = quotient.integer.begin();
       //auto it4 = buffer.integer.begin();


       for (auto it3 = quotient.integer.end(); it3 != quotient.integer.begin(); )
       {
           it3--;
           *it3 = 10;
           do {
               *it3 = *it3 - 1;
               buffer = op2 * quotient;
           } while (*this < buffer);
           if (*this == buffer)
               break;
       }
       for (auto it3 = quotient.integer.rbegin(); it3 != quotient.integer.rend(); it3 = quotient.integer.rbegin())
       {
           if (*it3 == 0)
               quotient.integer.pop_back();
           else
               break;
       }
       return quotient;
   }
   HugeInteger< T > quotient;
   return quotient;
} // end function operator/

// modulus operator; HugeInteger< T > % HugeInteger< T > provided that the divisor is not equal to 0
template< typename T >
HugeInteger< T > HugeInteger< T >::operator%( HugeInteger< T > &op2 )
{
   HugeInteger quotient = ( *this ) / op2;
   HugeInteger product = quotient * op2;
   HugeInteger remainder = ( *this ) - product;
   return remainder;
}

// overloaded prefix increment operator 
template< typename T >
HugeInteger< T >& HugeInteger< T >::operator++()
{
   helpIncrement(); // increment integer
   return *this; // reference return to create an lvalue
}

// overloaded postfix increment operator;
// note that the dummy integer parameter does not have a parameter name
template< typename T >
HugeInteger< T > HugeInteger< T >::operator++( int )
{
   HugeInteger< T > temp = *this; // hold current state of object
   helpIncrement();

   // return unincremented, saved, temporary object
   return temp; // value return; not a reference return
}

// overloaded prefix decrement operator 
template< typename T >
HugeInteger< T >& HugeInteger< T >::operator--()
{
   helpDecrement(); // increment integer
   return *this; // reference return to create an lvalue
}

// overloaded postfix decrement operator;
// note that the dummy integer parameter does not have a parameter name
template< typename T >
HugeInteger< T > HugeInteger< T >::operator--( int )
{
   HugeInteger temp = *this; // hold current state of object
   helpDecrement();

   // return unincremented, saved, temporary object
   return temp; // value return; not a reference return
}

// function that tests if a HugeInteger is zero
template< typename T >
bool HugeInteger< T >::isZero()
{
   typename T::iterator it = integer.begin();
   for( ; it != integer.end(); ++it )
      if( *it != 0 )
         return false;

   return true;
}

// function that divides a HugeInteger by 10;
// shift a HugeInteger one position to the right
template< typename T >
void HugeInteger< T >::divideByTen()
{
   typename T::iterator it1 = integer.begin();
   typename T::iterator it2 = it1;
   for( ++it2; it2 != integer.end(); ++it1, ++it2 )
      *it1 = *it2;

   typename T::iterator it = integer.end();
   integer.pop_back();
}

// function to help increment the integer
template< typename T >
void HugeInteger< T >::helpIncrement()
{
   typename T::iterator it = integer.begin();
   if( isZero() )
      ( *it )++;
   else
   {
      ( *it )++;
      typename T::iterator it2 = it;
      for( ++it2; it2 != integer.end(); ++it, ++it2 )
         if( *it == 10 )
         {
            *it = 0;
            ( *it2 )++;
         }

      if( ( *it ) == 10 )
      {
         *it = 0;
         integer.push_back( 1 );
      }
   }
}

// function to help decrement the integer
template< typename T >
void HugeInteger< T >::helpDecrement()
{
   typename T::iterator it = integer.begin();
   for( ; *it == 0; ++it )
      *it = 9;

   ( *it )--;

   if( !isZero() && *it == 0 && it == --( integer.end() ) )
      integer.pop_back();
}

// convert a container of decimal digits into a HugeInteger
template< typename T >
void HugeInteger< T >::convert( T &v )
{
   integer.resize( v.size() );
   typename T::reverse_iterator it1 = integer.rbegin();
   typename T::iterator it2 = v.begin();
   for( ; it2 != v.end(); ++it1, ++it2 )
      *it1 = *it2;
}

// overloaded output operator for class HugeInteger
template< typename T >
ostream &operator<<( ostream &output, HugeInteger< T > hugeInteger )
{
   if( hugeInteger.isZero() )
      output << 0;
   else
   {
      typename T::reverse_iterator it = hugeInteger.integer.rbegin();
      for( ; it != hugeInteger.integer.rend(); ++it )
         if( *it < 10 )
            output << *it;
   }

   return output; // enables cout << x << y;
}