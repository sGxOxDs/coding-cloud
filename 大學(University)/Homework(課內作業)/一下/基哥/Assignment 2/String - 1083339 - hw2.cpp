#include "String.h" // include definition of class String

string::string()
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
}

string::string( const char *const ptr, const size_type count )
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
    size_type newCap;
    for (newCap = myRes; newCap < count; newCap +=16);
    if (newCap < 16) {
        for (size_type i = 0; i < count; i++) {
            bx.buf[i] = ptr[i];
        }
        myRes = newCap;
        mySize = count;
    }
    else {
        pointer temp = new value_type[newCap]();
        for (size_type i = 0; i < count; i++) {
            temp[i] = ptr[i];
        }
        bx.ptr = temp;
        myRes = newCap;
        mySize = count;
    }
}

string::string( const size_type count, const char ch )
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
    size_type newCap;
    for (newCap = myRes; newCap < count; newCap += 16);
    if (newCap < 16) {
        for (size_type i = 0; i < count; i++) {
            bx.buf[i] = ch;
        }
        myRes = newCap;
        mySize = count;
    }
    else {
        pointer temp = new value_type[newCap]();
        for (size_type i = 0; i < count; i++) {
            temp[i] = ch;
        }
        bx.ptr = temp;
        myRes = newCap;
        mySize = count;
    }
}

string::string( const string &right )
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
    size_type newCap;
    for (newCap = myRes; newCap < right.size(); newCap += 16);

    if (newCap < 16) {
        for (size_type i = 0; i < newCap; i++) {
            bx.buf[i] = right.myPtr()[i];
        }
        myRes = newCap;
        mySize = right.size();
    }
    else {
        pointer temp = new value_type[newCap]();
        for (size_type i = 0; i < newCap; i++) {
            if (i < right.size())
                temp[i] = right.myPtr()[i];
            else
                temp[i]='\0';
        }
        bx.ptr = temp;
        myRes = newCap;
        mySize = right.size();
    }
    

}

string::~string()
{
   if( myRes > 15 )
      delete[] bx.ptr;
}

string::value_type* string::myPtr()
{
   if( myRes < 16 )
      return bx.buf;
   else
      return bx.ptr;
}

const string::value_type* string::myPtr() const
{
   if( myRes < 16 )
      return bx.buf;
   else
      return bx.ptr;
}

string& string::assign( const string &right )
{
    if( this != &right )
    {
        //*this = right;


        /*if (right.size() > capacity()) {
            size_type newCap = 38;
            for (size_type k = 38; newCap < right.size(); k *= 1.5)
                newCap = k;
            pointer temp = new value_type[newCap];
            for (size_type i = 0; i < newCap; i++) {
                if (i < size())
                    temp[i] = myPtr()[i];
                else
                    temp[i] = '\0';
            }
            if (!bx.ptr)
                delete bx.ptr;
            bx.ptr = temp;
            myRes = newCap;
        }*/


        //for (size_type i = 0; right.size() > capacity();i++) {
            resize(right.size());
        //}
        if (right.capacity() < 16 && capacity() < 16) {
            for (size_type i = 0; i < right.size(); i++) {
                bx.buf[i] = right.myPtr()[i];
            }
        }
        else {
            for (size_type i = 0; i < right.size(); i++) {
                bx.ptr[i] = right.myPtr()[i];
            }
        }
        mySize = right.size();


        /*if (capacity() > right.size()) {
            //cover
            if (capacity() < 16) {
                for (size_type i = 0; i < right.size(); i++) {
                    bx.buf[i] = right.myPtr()[i];
                }
            }
            else {
                for (size_type i = 0; i < right.size(); i++) {
                    bx.ptr[i] = right.myPtr()[i];
                }
            }
            mySize = right.size();
        }
        else {
            //resize
            size_type newCap;
            for (newCap = myRes; newCap < right.size(); newCap += 16);
            if (right.capacity() > capacity() * 1.5) {
                newCap = right.capacity() + 15;
            }
            else if (right.capacity() > capacity()) {
                newCap = capacity() * 1.5;
            }
            for (newCap = 0; newCap < right.size(); newCap += 16);
            newCap--; 

            pointer temp = new value_type[newCap];
            for (size_type i = 0; i < right.size(); i++) {
                temp[i] = right.myPtr()[i];
            }
            if (!bx.ptr)
                delete bx.ptr;
            bx.ptr = temp;
            myRes = newCap;
            mySize = right.size();
        }*/
    }

   return *this;
}

void string::clear()
{
   mySize = 0;
   myPtr()[ 0 ] = value_type();
}

string::iterator string::begin()
{
   return iterator( myPtr() );
}

string::const_iterator string::begin() const
{
   return const_iterator( myPtr() );
}

string::iterator string::end()
{
   return iterator( myPtr() + static_cast< difference_type >( mySize ) );
}

string::const_iterator string::end() const
{
   return const_iterator( myPtr() + static_cast< difference_type >( mySize ) );
}

string::reference string::element( const size_type off )
{
   return myPtr()[ off ];
}

string::const_reference string::element( const size_type off ) const
{
   return myPtr()[ off ];
}

void string::push_back( char ch )
{
   resize( mySize + 1 );
   myPtr()[ mySize - 1 ] = ch;
}

void string::pop_back()
{
   if( mySize > 0 )
      --mySize;
}

string::reference string::front()
{
   return myPtr()[ 0 ];
}

string::const_reference string::front() const
{
   return myPtr()[ 0 ];
}

string::reference string::back()
{
   return myPtr()[ mySize - 1 ];
}

string::const_reference string::back() const
{
   return myPtr()[ mySize - 1 ];
}

const char* string::c_str() const
{
   return myPtr();
}

string::size_type string::size() const
{
   return mySize;
}

void string::resize( const size_type newSize, const char ch )
{
    size_type newCap;
    if (newSize > capacity()) {
        if ((newSize | 15) > capacity() * 1.5)
            newCap = (newSize | 15);
        else
            newCap = capacity() * 1.5;
            
        pointer temp = new value_type[newCap];
        for (size_type i = 0; i < newCap; i++) {
            if (i < size())
                temp[i] = myPtr()[i];
            else {
                temp[i] = ch;
            }
        }
        if (myRes > 15)
        {
            delete bx.ptr;
        }
       
        bx.ptr = temp; 
        myRes = newCap;
    }
    else if(newSize > size() && myRes > 15) {
        for (size_type i = 0; i < capacity(); i++) {
            if (i < size())
                bx.ptr[i] = myPtr()[i];
            else
                bx.ptr[i] = ch;
        }
    }
    else if (myRes > 15) {
        for (size_type i = 0; i < capacity(); i++) {
            if (i < newSize)
                bx.ptr[i] = myPtr()[i];
            else
                bx.ptr[i] = ch;
        }
    }
    mySize = newSize;
    /*if (newSize > capacity() * 1.5) {
        newCap = newSize + 16;
        pointer temp = new value_type[newCap];
        for (size_type i = 0; i < newCap; i++) {
            if (i < size())
                temp[i] = myPtr()[i];
            else
                temp[i] = ch;
        }
        if (!bx.ptr)
            delete bx.ptr;
        bx.ptr = temp;
        myRes = newCap;
    }
    else if(newSize > capacity()) {
        newCap = capacity() * 1.5;
        pointer temp = new value_type[newCap];
        for (size_type i = 0; i < newCap; i++) {
            if (i < size())
                temp[i] = myPtr()[i];
            else
                temp[i] = ch;
        }
        if (!bx.ptr)
            delete bx.ptr;
        bx.ptr = temp;
        myRes = newCap;
    }*/
}

string::size_type string::capacity() const
{
   return myRes;
}

bool string::empty() const
{
   return mySize == 0;
}