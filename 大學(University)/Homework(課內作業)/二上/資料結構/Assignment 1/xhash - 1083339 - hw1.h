// xhash internal header

#ifndef XHASH
#define XHASH

#include <list>
using std::list;

#include<iostream>
using std::cout;
using std::endl;

// CLASS TEMPLATE VectorVal
template< typename ValueType >
class VectorVal
{
public:
   using value_type = ValueType;
   using pointer    = value_type *;

   VectorVal()
      : myFirst(),
        myLast(),
        myEnd()
   {
   }

   pointer myFirst; // pointer to beginning of array
   pointer myLast;  // pointer to current end of sequence
   pointer myEnd;   // pointer to end of array
};

template< typename Iter >
struct HashVec
{
   using value_type = Iter;
   using size_type  = size_t;

   HashVec()
      : myData()
   {
   }

   // set the elements stored here to cells copies of val
   void assignGrow( const size_type cells, const value_type val )
   {
       if (myData.myFirst != nullptr)
           delete[] myData.myFirst;
       myData.myFirst = new value_type[cells];
       for (size_type i = 0; i < cells; i++)
           myData.myFirst[i] = val;
   }

   ~HashVec()
   {
      if( myData.myFirst != nullptr )
         delete[] myData.myFirst;
   }

   VectorVal< value_type > myData;
};

// CLASS TEMPLATE Hash
template< typename Traits >
class Hash // hash table -- list with vector of iterators for quick access
{
protected:
   using MyList         = list< typename Traits::value_type >;
   using KeyCompare     = typename Traits::key_compare;

public:
   using key_type       = typename Traits::key_type;
   using value_type     = typename MyList::value_type;
   using size_type      = typename MyList::size_type;

   using iterator       = typename MyList::const_iterator;
   using const_iterator = typename MyList::const_iterator;

   static const size_type MinBuckets = 8; // must be a positive power of 2

protected:
   Hash( const KeyCompare &parg ) // construct empty hash table
      : traitsObj( parg ),
        myList(),
        myVec(),
        mask( MinBuckets - 1 ),
        maxidx( MinBuckets )
   {     
      myVec.assignGrow( MinBuckets * 2, myList.end() );
   }

public:
   // Returns the number of elements in the unordered_set container.
   size_type size() const
   {
      return myList.size();
   }

   // Returns the number of buckets in the unordered_set container.
   size_type bucket_count() const
   {
      return maxidx;
   }

   // Returns the bucket number where the element with value keyVal is located.
   size_type bucket( const key_type& keyVal ) const
   {
      return traitsObj( keyVal ) & mask;
//    return traitsObj.operator()( keyVal ) & mask;
//    return traitsObj( keyVal ) % maxidx;
   }

   // Returns the number of elements in bucket n.
   size_type bucket_size( size_type n ) const
   {
       if (myVec.myData.myFirst[2 * n] == myList.end() && myVec.myData.myFirst[2 * n + 1] == myList.end())
           return 0;
       else
       {
           size_type count = 1;
           iterator temp = myVec.myData.myFirst[2 * n];
           for (; temp != myVec.myData.myFirst[2 * n + 1]; temp++, count++);
           return count;
       }
   }

   // Inserts a new element in the unordered_set.
   // The element is inserted only if it is not equivalent to any other element
   // already in the container ( elements in an unordered_set have unique values ).
   // This effectively increases the container size by one.
   void insert( const value_type &val )
   {
       if (myList.size() == maxidx)
       {
           if (maxidx < 512)
               maxidx *= 8;
           else
               maxidx *= 2;
           mask = maxidx - 1;
           myVec.assignGrow(maxidx * 2, myList.end());
           MyList tempList(myList);
           myList.clear();
           for (auto it = tempList.begin(); it != tempList.end(); it++)
               putIn(*it);
       }
       putIn(val);
   }

   // Removes from the unordered_set a single element.
   // This effectively reduces the container size by one.
   void erase( const key_type &keyVal )
   {
       size_type bucketNumber = bucket(keyVal);
       auto it = find(keyVal);
       if (it != myList.end())
       {
           if (it == myVec.myData.myFirst[2 * bucketNumber] && it == myVec.myData.myFirst[2 * bucketNumber + 1])
           {
               myVec.myData.myFirst[2 * bucketNumber] = myList.end();
               myVec.myData.myFirst[2 * bucketNumber + 1] = myList.end();
           }
           else if (it == myVec.myData.myFirst[2 * bucketNumber])
           {
               myVec.myData.myFirst[2 * bucketNumber]++;
           }
           else if (it == myVec.myData.myFirst[2 * bucketNumber + 1])
           {
               myVec.myData.myFirst[2 * bucketNumber + 1]--;
           }
           myList.erase(it);
       }
       
   }

   // Searches the unordered_set for an element with keyVal as value and
   // returns an iterator to it if found, otherwise it returns myList.end()
   iterator find( const key_type &keyVal )
   {
       size_type bucketNumber = bucket(keyVal);
       auto it = myVec.myData.myFirst[2 * bucketNumber];
       if (it == myList.end())
           return it;

       for (; it != myVec.myData.myFirst[2 * bucketNumber + 1]; it++)
           if (*it == keyVal)
               return it;
       if (myVec.myData.myFirst[2 * bucketNumber] == myVec.myData.myFirst[2 * bucketNumber + 1] && *it == keyVal)
           return it;
       if (*it == keyVal)
           return it;
       return myList.end();
   }

private:
   // put a new element in the unordered_set when myVec is large enough
   void putIn( const value_type &val )
   {
       size_type bucketNumber = bucket(val);
       if (myVec.myData.myFirst[2 * bucketNumber] == myList.end())
       {
           myList.push_back(val);
           myVec.myData.myFirst[2 * bucketNumber] = --myList.end();
           myVec.myData.myFirst[2 * bucketNumber + 1] = --myList.end();
       }
       else
       {
           auto existCheck = find(val);
           if (existCheck != myList.end())
           {
               if (*existCheck == val)
                   return;
           }
           
           auto it = myVec.myData.myFirst[2 * bucketNumber];
           myList.insert(it, val);
           it--;
           myVec.myData.myFirst[2 * bucketNumber] = it;
       }
       //cout << "putIn: " << val << " / key: " << bucket(val) << endl;
       
   }

protected:
   Traits traitsObj;          // traits to customize behavior
   MyList myList;             // list of elements, must initialize before myVec
   HashVec< iterator > myVec; // "vector" of list iterators for buckets:
                              // each bucket is 2 iterators denoting
                              // the closed range of elements in the bucket,
                              // or both iterators set to end() if the bucket is empty.
   size_type mask;            // the key mask, equals maxidx - 1
   size_type maxidx;          // current maximum key value, must be a power of 2
};

#endif // XHASH