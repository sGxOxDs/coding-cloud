// SourceLine class member-function definitions.

#include <iostream>
using std::cout;

#include "SourceLine.h" // SourceLine class definition

// default constructor
SourceLine::SourceLine()
   : sourceLine()
{
}

SourceLine& SourceLine::operator=( const char * const ptr )
{
   sourceLine = ptr;
   return *this;
}

void SourceLine::delComments()
{
   if( sourceLine.size() > 1 )

}

void SourceLine::delStrConst()
{

}

void SourceLine::delCharConst()
{

}

string SourceLine::delFirstIdentifier()
{

}