// HugeInteger class template definition.
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include "Deque - 1083339 - hw9.h"

//#include <deque>
//using std::deque;

template< typename T >
class HugeInteger : public deque< T >
{
public:
//   HugeInteger(); // default constructor; construct a HugeInteger with mySize 0
   HugeInteger( size_t n = 0 ); // constructor; construct a zero HugeInteger with mySize n

   // copy constructor; constructs a HugeInteger with a copy of each of the elements in integerToCopy
   HugeInteger( const HugeInteger &integerToCopy );

   ~HugeInteger(); // destructor; destroys the HugeInteger

   const HugeInteger& operator=( const HugeInteger &right ); // assignment operator
   
   // assign right to integer, i.e., integer = right
   void operator=( const deque< T > &right );

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

private:
   void divideByTen();   // divides a HugeInteger by 10
   void helpIncrement(); // increments a HugeInteger by 1
   void helpDecrement(); // decrements a HugeInteger by 1
}; // end class template HugeInteger

#endif


// constructor; construct a zero HugeInteger with mySize n
template< typename T >
HugeInteger< T >::HugeInteger( size_t n )
   : deque< T >( ( n == 0 ) ? 1 : n )
{
}

// copy constructor; constructs a HugeInteger with a copy of each of the elements in integerToCopy
template< typename T >
HugeInteger< T >::HugeInteger( const HugeInteger< T > &integerToCopy )
   : deque< T >( integerToCopy )
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
      typename deque< T >::operator=( right );

   return *this; // enables x = y = z, for example
} // end function operator=

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
template< typename T >
void HugeInteger< T >::operator=( const deque< T > &right )
{
   typename deque< T >::operator=( right );
} // end function operator=

// function that tests if one HugeInteger< T > is less than another
template< typename T >
bool HugeInteger< T >::operator<( HugeInteger< T > &right )
{
    if (deque< T >::size() < right.size())
        return true;
    else if (deque< T >::size() > right.size())
        return false;
    else
    {
        for (int i = deque< T >::size() - 1; i >= 0; i--)
        {
            if (deque< T >::begin()[i] < right.begin()[i])
                return true;
            else if (deque< T >::begin()[i] > right.begin()[i])
                return false;
        }
        if (deque< T >::begin()[0] == right.begin()[0])
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
   size_t op1Size = this->size();
   size_t op2Size = op2.size();
   size_t sumSize = ( op1Size >= op2Size ) ? op1Size + 1 : op2Size + 1;

   HugeInteger sum( sumSize );
   typename deque< T >::iterator it1 = this->begin();
   typename deque< T >::iterator it3 = sum.begin();
   for( ; it1 != this->end(); ++it1, ++it3 )
      *it3 = *it1;

   typename deque< T >::iterator it2 = op2.begin();
   it3 = sum.begin();
   for( ; it2 != op2.end(); ++it2, ++it3 )
      *it3 += *it2;

   it3 = sum.begin();
   typename deque< T >::iterator it4 = it3;
   for( ++it4; it4 != sum.end(); ++it3, ++it4 )
      if( *it3 > 9 )
      {
         ( *it3 ) -= 10;
         ( *it4 )++;
      }

   if( *it3 == 0 )
      sum.pop_back();

   return sum;
} // end function operator+

// subtraction operator; HugeInteger< T > - HugeInteger< T >
template< typename T >
HugeInteger< T > HugeInteger< T >::operator-( HugeInteger< T > &op2 )
{
   HugeInteger zero;
   if( *this == op2 )
      return zero;

   HugeInteger difference( *this );

   for (auto it3 = difference.begin(); it3 != difference.end(); it3++)
       *it3 += 10;

   for (auto it2 = op2.begin(), it3 = difference.begin(); it2 != op2.end(); it2++, it3++)
       *it3 -= *it2;

   for (auto it3 = difference.begin(); it3 != difference.end(); )
   {
       if (*it3 > 9)
       {
           *it3 -= 10;
           it3++;
       }
       else if (*it3 >= 0)
       {
           it3++;
           if (it3 != difference.end())
               *it3 -= 1;
       }

   }
   for (auto it3 = difference.rbegin(); it3 != difference.rend(); it3 = difference.rbegin())
       if (*it3 == 0)
           difference.pop_back();
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

   HugeInteger product( this->size() + op2.size() );

   {
       auto it3 = product.begin();
       auto it4 = product.begin();
       for (auto it1 = this->begin(); it1 != this->end(); it1++)
       {
           for (auto it2 = op2.begin(); it2 != op2.end(); it2++, it3++)
               *it3 += (*it1) * (*it2);
           it4++;
           for (; it3 != it4; it3--);
       }
   }

   for (auto it3 = product.begin(); it3 != product.end(); it3++)
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

   for (auto it3 = product.rbegin(); it3 != product.rend(); it3 = product.rbegin())
       if (*it3 == 0)
           product.pop_back();
       else
           break;

   return product;
} // end function operator*

// division operator; HugeInteger< T > / HugeInteger< T > provided that the divisor is not equal to 0
template< typename T >
HugeInteger< T > HugeInteger< T >::operator/( HugeInteger< T > &op2 )
{
   HugeInteger zero;
   if( *this < op2 )
      return zero;
   else if (*this == op2)
   {
       HugeInteger< T > quotient;
       auto it3 = quotient.begin();
       *it3 = 1;
       return quotient;
   }
   else
   {
       unsigned int dividendSize = this->size();
       unsigned int divisorSize = op2.size();

       unsigned int bufferSize = dividendSize;
       HugeInteger< T >  buffer(bufferSize);

       unsigned int quotientSize = dividendSize - divisorSize + 1;
       HugeInteger< T >  quotient(quotientSize);

       for (auto it3 = quotient.end(); it3 != quotient.begin();)
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
       for (auto it3 = quotient.rbegin(); it3 != quotient.rend(); it3 = quotient.rbegin())
       {
           if (*it3 == 0)
               quotient.pop_back();
           else
               break;
       }
       return quotient;
   }
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
   HugeInteger temp = *this; // hold current state of object
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
   typename deque< T >::iterator it = this->begin();
   for( ; it != this->end(); ++it )
      if( *it != 0 )
         return false;

   return true;
}

// function that divides a HugeInteger by 10; shift a HugeInteger one position to the right
template< typename T >
void HugeInteger< T >::divideByTen()
{
   typename deque< T >::iterator it1 = this->begin();
   typename deque< T >::iterator it2 = it1;
   for( ++it2; it2 != this->end(); ++it1, ++it2 )
      *it1 = *it2;

   this->pop_back();
   typename deque< T >::iterator it = this->end();
}

// function to help increment the integer
template< typename T >
void HugeInteger< T >::helpIncrement()
{
   typename deque< T >::iterator it = this->begin();
   if( isZero() )
      ( *it )++;
   else
   {
      ( *it )++;
      typename deque< T >::iterator it2 = it;
      for( ++it2; it2 != this->end(); ++it, ++it2 )
         if( *it == 10 )
         {
            *it = 0;
            ( *it2 )++;
         }

      if( ( *it ) == 10 )
      {
         *it = 0;
         this->push_back( 1 );
      }
   }
}

// function to help decrement the integer
template< typename T >
void HugeInteger< T >::helpDecrement()
{
   typename deque< T >::iterator it = this->begin();
   for( ; *it == 0; ++it )
      *it = 9;

   ( *it )--;

   if( !this->isZero() && *it == 0 && it == --( this->end() ) )
      this->pop_back();
}

// overloaded output operator for class HugeInteger
template< typename T >
ostream& operator<<( ostream &output, HugeInteger< T > hugeInteger )
{
   if( hugeInteger.isZero() )
      output << 0;
   else
   {
      typename deque< T >::reverse_iterator it = hugeInteger.rbegin();
      for( ; it != hugeInteger.rend(); ++it )
         if( *it < 10 )
            output << *it;
   }

   return output; // enables cout << x << y;
}