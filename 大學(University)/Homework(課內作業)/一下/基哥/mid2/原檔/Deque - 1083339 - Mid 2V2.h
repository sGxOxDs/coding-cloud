#ifndef DEQUE_H
#define DEQUE_H

//#include "XUtility.h" // include definition of class template ReverseIterator

// CLASS TEMPLATE DequeConstIterator
template< typename MyDeque >
class DequeConstIterator // iterator for nonmutable deque
{
private:
   using size_type = typename MyDeque::size_type;

public:
   using value_type      = typename MyDeque::value_type;
   using difference_type = typename MyDeque::difference_type;
   using pointer         = typename MyDeque::const_pointer;
   using reference       = const value_type &;

   // construct with null pointer
   DequeConstIterator()
      : myOff( 0 ),
        myCont( nullptr )
   {
   }

   // construct with offset off in *pDeque
   DequeConstIterator( size_type off, const MyDeque *pDeque )
      : myOff( off ),
        myCont( pDeque )
   {
   }

   DequeConstIterator( const DequeConstIterator &right ) // copy constructor
      : myOff( right.myOff ),
        myCont( right.myCont )
   {
   }

   ~DequeConstIterator() // destructor
   {
   }

   // const return avoids: ( a1 = a2 ) = a3
   const DequeConstIterator& operator=( const DequeConstIterator &right )
   {
      if( &right != this ) // avoid self-assignment
      {
         myCont = right.myCont;
         myOff = right.myOff;
      }
      return *this; // enables x = y = z, for example
   }

   reference operator*() const
   {
//      size_type block = myOff % ( 4 * myCont->mapSize ) / 4;
      size_type block = myCont->getBlock( myOff );
      size_type off = myOff % 4;
      return myCont->map[ block ][ off ];
   }

   pointer operator->() const
   {
      return &( operator*() );
   }

   DequeConstIterator& operator++() // preincrement
   {
      ++myOff;
      return *this;
   }

   DequeConstIterator operator++( int ) // postincrement
   {
      DequeConstIterator tmp = *this;
      ++*this;
      return tmp;
   }

   DequeConstIterator& operator--() // predecrement
   {
      --myOff;
      return *this;
   }

   DequeConstIterator operator--( int ) // postdecrement
   {
      DequeConstIterator tmp = *this;
      --*this;
      return tmp;
   }

   // increment by integer
   DequeConstIterator& operator+=( const difference_type off )
   {
      myOff += off;
      return *this;
   }

   // return this + integer
   DequeConstIterator operator+( const difference_type off ) const
   {
      DequeConstIterator tmp = *this;
      return tmp += off;
   }

   // decrement by integer
   DequeConstIterator& operator-=( const difference_type off )
   {
      return *this += -off;
   }

   // return this - integer
   DequeConstIterator operator-( const difference_type off ) const
   {
      DequeConstIterator tmp = *this;
      return tmp -= off;
   }

   // return difference of iterators
   difference_type operator-( const DequeConstIterator &right ) const
   {
      return ( static_cast< difference_type >( this->myOff - right.myOff ) );
   }

   reference operator[]( const difference_type off ) const // subscript
   {
      return *( *this + off );
   }

   // test for iterator equality
   bool operator==( const DequeConstIterator &right ) const
   {
      return this->myCont == right.myCont && this->myOff == right.myOff;
   }

   // test for iterator inequality
   bool operator!=( const DequeConstIterator &right ) const
   {
      return !( *this == right );
   }

   // test if this < right
   bool operator<( const DequeConstIterator &right ) const
   {
      return this->myOff < right.myOff;
   }

   // test if this > right
   bool operator>( const DequeConstIterator &right ) const
   {
      return right < *this;
   }

   // test if this <= right
   bool operator<=( const DequeConstIterator &right ) const
   {
      return !( right < *this );
   }

   // test if this >= right
   bool operator>=( const DequeConstIterator &right ) const
   {
      return !( *this < right );
   }

   const MyDeque *myCont; // keep a pointer to deque
   size_type myOff;       // offset of element in deque
};


// CLASS TEMPLATE DequeIterator
template< typename MyDeque >
class DequeIterator : public DequeConstIterator< MyDeque >
{ // iterator for mutable deque
private:
   using size_type = typename MyDeque::size_type;
   using MyBase = DequeConstIterator< MyDeque >;

public:
   using value_type      = typename MyDeque::value_type;
   using difference_type = typename MyDeque::difference_type;
   using pointer         = typename MyDeque::pointer;
   using reference       = value_type &;

   DequeIterator() // construct with null deque pointer
   {
   }

   DequeIterator( size_type off, const MyDeque *pDeque )
      : MyBase( off, pDeque ) // construct with offset off in *pDeque
   {
   }

   reference operator*() const // return designated object
   {
      return const_cast< reference >( MyBase::operator*() );
   }

   pointer operator->() const // return pointer to class object
   {
      return const_cast< pointer >( MyBase::operator->() );
//      return &( operator*() );
   }

   DequeIterator& operator++() // preincrement
   {
      MyBase::operator++();
      return *this;
   }

   DequeIterator operator++( int ) // postincrement
   {
      DequeIterator tmp = *this;
      MyBase::operator++();
      return tmp;
   }

   DequeIterator& operator--() // predecrement
   {
      MyBase::operator--();
      return *this;
   }

   DequeIterator operator--( int ) // postdecrement
   {
      DequeIterator tmp = *this;
      MyBase::operator--();
      return tmp;
   }

   // increment by integer
   DequeIterator& operator+=( const difference_type off )
   {
      MyBase::operator+=( off );
      return *this;
   }

   // return this + integer
   DequeIterator operator+( const difference_type off ) const
   {
      DequeIterator tmp = *this;
      return tmp += off;
   }

   // decrement by integer
   DequeIterator& operator-=( const difference_type off )
   {
      MyBase::operator-=( off );
      return *this;
   }

   using MyBase::operator-; // return difference of iterators

   // return this - integer
   DequeIterator operator-( const difference_type off ) const
   {
      DequeIterator tmp = *this;
      return tmp -= off;
   }

   reference operator[]( const difference_type off ) const // subscript
   {
      return const_cast< reference >( MyBase::operator[]( off ) );
   }
};

// CLASS TEMPLATE DequeVal
template< typename Ty >
class DequeVal // base class for deque to hold data
{
public:
   using value_type = Ty;
   using size_type = size_t;
   using difference_type = ptrdiff_t;
   using pointer = value_type *;
   using const_pointer = const value_type *;
   using reference       = value_type &;
   using const_reference = const value_type &;
   using MapPtr = Ty **;

   DequeVal() // initialize values
      : map(),
        mapSize( 0 ),
        myOff( 0 ),
        mySize( 0 )
   {
   }

   // determine block from offset
   size_type getBlock( size_type off ) const
   {
      return off % ( 4 * mapSize ) / 4;
//      return ( off / 4 ) & ( mapSize - 1 );
   }

   MapPtr map;        // pointer to array of pointers to blocks
   size_type mapSize; // size of map array, zero or 2^N
   size_type myOff;   // offset of initial element
   size_type mySize;  // current length of sequence
};


// CLASS TEMPLATE deque
template< typename Ty >
class deque // circular queue of pointers to blocks
{
private:
   using MapPtr = Ty **;
   using ScaryVal = DequeVal< Ty >;

public:
   using value_type      = Ty;
   using size_type       = size_t;
   using difference_type = ptrdiff_t;
   using pointer         = value_type *;
   using const_pointer   = const value_type *;
   using reference       = value_type &;
   using const_reference = const value_type &;

   using iterator               = DequeIterator< ScaryVal >;
   using const_iterator         = DequeConstIterator< ScaryVal >;

   // construct empty deque
   deque()
      : myData()
   {
   }

   // construct from count * val
   deque( size_type count, const value_type &val )
      : myData()
   {
      myData.map = new value_type *[ 8 ]();
      myData.map[ 0 ] = new value_type[ 4 ];
      myData.map[ 0 ][ 0 ] = val;
      myData.mapSize = 8;
      myData.mySize = count;
   }

   // construct by copying right
   deque( const deque &right )
      : myData()
   {
       //clear();  deleted
       //delete[] myData.map;  deleted
       myData.mapSize = right.myData.mapSize;
       myData.myOff = right.myData.myOff;
       myData.mySize = right.myData.mySize;

       myData.map = new pointer[myData.mapSize]();
       if (myData.mapSize > 0)  // added
       { // added
           for (size_type i = 0; i < (myData.myOff + myData.mySize) % (4 * myData.mapSize); i++)
           {
               if (right.myData.map[i / 4] != nullptr)
               {
                   if (myData.map[i / 4] == nullptr)
                       myData.map[i / 4] = new value_type[4]();
                   myData.map[i / 4][i % 4] = right.myData.map[i / 4][i % 4];
               }
           }
           for (size_type i = myData.myOff; i < 4 * myData.mapSize; i++)
           {
               if (right.myData.map[i / 4] != nullptr)
               {
                   if (myData.map[i / 4] == nullptr)
                       myData.map[i / 4] = new value_type[4]();
                   myData.map[i / 4][i % 4] = right.myData.map[i / 4][i % 4];
               }
           }
       } // added
   }

   // destroy the deque
   ~deque()
   {
      clear();
   }

   // return iterator for beginning of mutable sequence
   iterator begin()
   {
      return iterator( myData.myOff, &myData );
   }

   // return iterator for beginning of nonmutable sequence
   const_iterator begin() const
   {
      return const_iterator( myData.myOff, &myData );
   }

   // return iterator for end of mutable sequence
   iterator end()
   {
      return iterator( myData.myOff + myData.mySize, &myData );
   }

   // return iterator for end of nonmutable sequence
   const_iterator end() const
   {
      return const_iterator( myData.myOff + myData.mySize, &myData );
   }

   // return length of sequence
   size_type size() const
   {
      return myData.mySize;
   }

   // test if sequence is empty
   bool empty() const
   {
      return myData.mySize == 0;
   }

   // insert val at where
   void insert( const_iterator where, const value_type &val )
   {
	   unsigned int inserted = 0;
	   if (myData.mySize == 0)
	   {
		   
           if (begin() == where)
           {
               myData.map = new pointer[8]();
               myData.map[7] = new value_type[4]();
               myData.map[7][3] = val;
               myData.mapSize = 8;
               myData.myOff--;
               myData.myOff %= 4 * myData.mapSize;
           }
           else
           {
               myData.map = new pointer[8]();
               myData.map[0] = new value_type[4]();
               myData.map[0][0] = val;
               myData.mapSize = 8;
           }
	   }
	   else
	   {
		   if (begin() <= where && where <= end())
		   {
			   // all elements before where move forward
			   if (where <= begin() + myData.mySize / 2)
			   {
                   if ((myData.myOff - 1) % 4 == 3  &&
                       myData.mySize >= 4 * (myData.mapSize - 1))
                   {
                       doubleMapSize();
                       myData.myOff %= 4 * myData.mapSize;
                   }
				   myData.myOff--;
				   myData.myOff %= 4 * myData.mapSize;
                   size_type i = (myData.myOff) % (4 * myData.mapSize);
                   iterator it1 = this->begin();
                   iterator it2 = this->begin();
                   for (; (it1.myOff + 1 ) % (4 * myData.mapSize) != (where.myOff) % (4 * myData.mapSize); i++)
                   {
                       
                       if (myData.map[(i % (4 * myData.mapSize)) / 4] == nullptr)
                           myData.map[(i % (4 * myData.mapSize)) / 4] = new value_type[4]();
                       it2++;
                       *it1 = *it2;
                       it1++;
                   }
                   if (myData.map[(i % (4 * myData.mapSize)) / 4] == nullptr)
                       myData.map[(i % (4 * myData.mapSize)) / 4] = new value_type[4]();
                   *it1 = val;
			   }
			   else  // all elements after (and at) where move backward
			   {
                   if (((myData.myOff + myData.mySize) % 4 == 0) &&
                       myData.mySize >= 4 * (myData.mapSize - 1))
                   {
                       doubleMapSize();
                       myData.myOff %= 4 * myData.mapSize;
                   }
				   myData.myOff %= 4 * myData.mapSize;

				   size_type i = (myData.myOff + myData.mySize ) % (4 * myData.mapSize);
				   
                   iterator it1 = this->end();
                   iterator it2 = this->end();

                   for (; it1!=where; i--)
				   {
                       it2--;
					   if (myData.map[(i % (4 * myData.mapSize)) / 4] == nullptr)
						   myData.map[(i % (4 * myData.mapSize)) / 4] = new value_type[4]();
                       if ((it1.myOff) % (4 * myData.mapSize) == (where.myOff) % (4 * myData.mapSize))
                           break;
                       *it1 = *it2;
                       it1--;
                   }
                   if (myData.map[(i % (4 * myData.mapSize)) / 4] == nullptr)
                       myData.map[(i % (4 * myData.mapSize)) / 4] = new value_type[4]();
                   *it1 = val;
			   }
		   }
	   }
	   ++myData.mySize;
   }

   // erase element at where
   void erase( const_iterator where )
   {
	   if (myData.mySize > 0 && begin() <= where && where < end())
	   {
		   if (myData.mySize == 1 && begin() == where)
		   {
			   myData.myOff = 0;
			   myData.mySize = 0;
		   }
		   else
		   {
               iterator it1(where.myOff,where.myCont);
               iterator it2(where.myOff, where.myCont);
			   if (where < begin() + myData.mySize / 2)
			   {
                   for (; (it1.myOff) % (4 * myData.mapSize) != (this->begin().myOff) % (4 * myData.mapSize);)
                   {
                       it2--;
                       *it1 = *it2;
                       it1--;
                   }
                   myData.myOff++;
			   }
			   else // all elements after where move forward
			   {
                   for (; (it1.myOff) % (4 * myData.mapSize) != (this->end().myOff) % (4 * myData.mapSize);)
                   {
                       it2++;
                       if ((it2.myOff) % (4 * myData.mapSize) == (this->end().myOff) % (4 * myData.mapSize))
                           break;
                       *it1 = *it2;
                       it1++;
                   }
			   }
			   --myData.mySize;
		   }
	   }
   }

   // erase all
   void clear()
   {
      if( myData.mapSize > 0 )
      {
         for( size_type i = 0; i < myData.mapSize; i++ )
            if( myData.map[ i ] != nullptr )
               delete[] myData.map[ i ];
         delete[] myData.map;

         myData.mapSize = 0;
         myData.mySize = 0;
         myData.myOff = 0;
         myData.map = MapPtr();
      }
   }

private:

   // determine block from offset
   size_type getBlock( size_type off ) const
   {
      return myData.getBlock( off );
//      return ( ( myData.off / 4 ) & ( myData.mapSize - 1 ) );
   }

   void doubleMapSize()
   {
	   size_type newmapsize = myData.mapSize * 2;
	   MapPtr newmap = new pointer[newmapsize]();
	   for (size_type i = myData.myOff; i < myData.myOff + myData.mySize; i++)
	   {
		   if (myData.map[(i % (4 * myData.mapSize)) / 4] != nullptr)
		   {
			   if (newmap[i / 4] == nullptr)
				   newmap[i / 4] = new value_type[4]();
			   newmap[i / 4][i % 4] = myData.map[(i % (4 * myData.mapSize)) / 4][(i % (4 * myData.mapSize)) % 4];
		   }
	   }
	   for (size_type i = 0; i < myData.mapSize; i++)
		   if (myData.map[i] != nullptr)
			   delete[] myData.map[i];
	   delete[] myData.map;
	   myData.map = newmap;
	   myData.mapSize = newmapsize;
   }

   ScaryVal myData;
};

#endif