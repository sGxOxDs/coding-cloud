#include "vector.h" // include definition of class vector 
#include <iostream>
using namespace std;

// empty container constructor (default constructor)
// Constructs an empty container, with no elements.
vector::vector()
{
   myFirst = myLast = myEnd = nullptr;
}

// fill constructor
// Constructs a container with "count" elements.
// Each element is initialized as 0.
vector::vector( const size_type count )
{
    if (count <= 0)
        vector v;

    myFirst = new int[count] {0};
    myEnd = myFirst + count;
    myLast = myEnd - 1;
}

// copy constructor
// Constructs a container with a copy of each of the elements in "right",
// in the same order.
vector::vector( const vector &right )
{
}

// Vector destructor
// Destroys the container object.
// Deallocates all the storage capacity allocated by the vector.
vector::~vector()
{
   if( myFirst != nullptr )
      delete[] myFirst;
}

// The vector is extended by inserting a new element before the element
// at the specified position, effectively increasing the container size by one.
// This causes an automatic reallocation of the allocated storage space
// if and only if the new vector size surpasses the current vector capacity.
// Relocates all the elements that were after "where" to their new positions.
vector::iterator vector::insert( const_iterator where, const value_type &val )
{
    if (myFirst == nullptr)
    {
        myFirst = new value_type;
        myLast = myFirst ;
        myEnd = myFirst ;
    }

    if (where == nullptr) where = myFirst;

    size_type index = static_cast<size_type>(where - myFirst);
   

    
    if (myLast == myEnd)
    {
        size_type count = size() * 3 / 2;

        if (count == 0 || count == 1) count++;

        //cout << "count :" << count << endl;

        size_type originalSize = size();
        pointer v = new value_type[count];


        for (size_type i = 0; i < count; i++)
        {
            if(i <= originalSize)
                myLast = &v[i + 1];

            if (i <= index)
            {
                if (i == index)
                    *(v + i) = val;
                else if (i < index)
                    *(v + i) = *(myFirst + i - 1);
            }
            else if (count >= i)
                *(v + i) = *(myFirst + i - 1);
        }

        /*for (size_t i = 0; i < count; i++)
        {
            cout << "A val:" << *(v + i) << "\n";
        }*/

        myFirst = v;
        myEnd = v + count;
    }
    else
    { 
        //cout << "else" << endl;
        myLast++;
        for (size_type i = size(); i >= index; i--)
        {

            if (i == index)
            {
                myFirst[i] = val;
                break;
            }

            myFirst[i] = myFirst[i - 1];
        }

        /*for (size_t i = 0; i < capacity(); i++)
        {
            cout << "B val:" << *(myFirst + i) << "\n";
        }*/
    }
    
    //cout << endl;
    return myFirst;
}

// Assigns new contents to the container, replacing its current contents,
// and modifying its size accordingly.
// Copies all the elements from "right" into the container
// (with "right" preserving its contents).
vector& vector::assign( const vector &right )
{
    vector v;
    return v;
}

// Removes from the vector a single element (where).
// This effectively reduces the container size by one, which is destroyed.
// Relocates all the elements after the element erased to their new positions.
vector::iterator vector::erase( const_iterator where )
{
    return nullptr;
}

// Removes all elements from the vector (which are destroyed),
// leaving the container with a size of 0.
// A reallocation is not guaranteed to happen,
// and the vector capacity is not guaranteed to change due to calling this function.
void vector::clear()
{
   myLast = myFirst;
}

// Returns an iterator pointing to the first element in the vector.
// If the container is empty, the returned iterator value shall not be dereferenced.
vector::iterator vector::begin()
{
   return myFirst;
}

// Returns an iterator referring to the past-the-end element in the vector container.
// The past-the-end element is the theoretical element
// that would follow the last element in the vector.
// It does not point to any element, and thus shall not be dereferenced.
// If the container is empty, this function returns the same as vector::begin.
vector::iterator vector::end()
{
   return myLast;
}

// Returns whether the vector is empty (i.e. whether its size is 0).
bool vector::empty()
{
   return myFirst == myLast;
}

// Returns the number of elements in the vector.
// This is the number of actual objects held in the vector,
// which is not necessarily equal to its storage capacity.
vector::size_type vector::size()
{
   return static_cast< size_type >( myLast - myFirst );
}

// Returns the size of the storage space currently allocated for the vector,
// expressed in terms of elements.
// This capacity is not necessarily equal to the vector size.
// It can be equal or greater, with the extra space allowing to accommodate
// for growth without the need to reallocate on each insertion.
vector::size_type vector::capacity()
{
   return static_cast< size_type >( myEnd - myFirst );
}

// Returns a reference to the element at position "pos" in the vector container.
vector::value_type& vector::element( const size_type pos )
{
   return myFirst[ pos ];
}