#include "Vector.h" // include definition of class vector 
#include<cstring>
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
	int* temp = new int[count];
	delete[] myFirst;//釋放陣列?
	myFirst = temp;
	myLast = temp + count;
	myEnd = temp + count; //add
	//myEnd 呢?
	
}

// copy constructor
// Constructs a container with a copy of each of the elements in "right",
// in the same order.
vector::vector( const vector &right )
{
	int* temp = new int[right.myLast - right.myFirst]; //change
	for (size_t i = 0; i < right.myLast - right.myFirst; i++) { //change
		*(temp + i) = *(myFirst + i);
	}
	delete[] myFirst;//釋放陣列?
	myFirst = temp;
	myLast = temp + (right.myLast - right.myFirst); //change
	myEnd = temp + (right.myLast - right.myFirst); //add
	//myEnd 呢?
}

// Vector destructor
// Destroys the container object.
// Deallocates all the storage capacity allocated by the vector.
vector::~vector()
{
   if( myFirst != nullptr )
      delete[] myFirst;
}

// Adds a new element at the end of the vector, after its current last element.
// The content of val is copied to the new element.
// This effectively increases the vector size by one,
// which causes an automatic reallocation of the allocated storage space
// if and only if the new vector size surpasses the current vector capacity.
void vector::push_back( const value_type &val )
{
   size_type originalSize = size();
   resize( originalSize + 1 );
   myFirst[ originalSize ] = val;
}

// Assigns new contents to the container, replacing its current contents,
// and modifying its size accordingly.
// Copies all the elements from "right" into the container
// (with "right" preserving its contents).
vector& vector::assign( const vector &right )
{
   if( this != &right ) // avoid self-assignment
   {	
		/*for(size_t i = 0; i < this->size(); i++){
			*(this + i) = *(&right + i);
		} 	
		if (myEnd - myLast == 0) {// 規律: 沒有剩餘的空間 capacity會往上跳1.5倍 又因為int 所以後面的小數點不用理會
			(double)this -> capacity *= 1.5;
		}*/
   }
   return *this; // enables x = y = z, for example
}

// Resizes the vector so that it contains newSize elements.
// If newSize is smaller than the current vector size,
// the content is reduced to its first newSize elements, removing those beyond.
// If newSize is greater than the current vector size,
// the content is expanded by inserting at the end
// as many elements as needed to reach a size of newSize.
// The new elements are initialized as 0.
// If newSize is also greater than the current vector capacity,
// an automatic reallocation of the allocated storage space takes place.
void vector::resize( const size_type newSize )
{	
	if(capacity() > newSize){//大變小 
		myLast -= (size() - newSize);//myLast指標向前移動 原大小改變成newSize 		
	}else{//小變大
		int* f = new int[newSize]; 
		size_t i = 0; //change
		for(; i < size(); i++){ //change
			*(f + i) = *(myFirst + i);
		} //將myFirst所指向的陣列傳給f所指向的陣列 
		delete[] myFirst;//釋放陣列?
		myFirst = f;
		myLast = f + i; //change
		myEnd = f + newSize; //add
	}
}

// Removes the last element in the vector,
// effectively reducing the container size by one.
void vector::pop_back()
{
   if( size() > 0 )
      --myLast;
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
vector::pointer vector::begin()
{
   return myFirst;
}

// Returns the number of elements in the vector.
// This is the number of actual objects held in the vector,
// which is not necessarily equal to its storage capacity.
vector::size_type vector::size()
{
   return ( myLast - myFirst );
}

// Returns the size of the storage space currently allocated for the vector,
// expressed in terms of elements.
// This capacity is not necessarily equal to the vector size.
// It can be equal or greater, with the extra space allowing to accommodate
// for growth without the need to reallocate on each insertion.
vector::size_type vector::capacity()
{
   return ( myEnd - myFirst );
}

// Returns a reference to the element at position "pos" in the vector container.
vector::value_type& vector::element( const size_type pos )
{
   return myFirst[ pos ];
}
