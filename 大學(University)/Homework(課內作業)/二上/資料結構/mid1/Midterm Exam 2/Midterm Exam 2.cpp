#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <set>
#include "set.h"

template< typename T, typename T1 = less< T >, typename T2 = std::less< T > >
void testSet();

struct Triple
{
   unsigned int low;
   unsigned int mid;
   unsigned int high;
};

void preSequence( Triple preorder[], unsigned int number );

// returns true if and only if set1 == set2
template< typename T, typename T1, typename T2 >
bool equal( set< T, T1 > &set1, std::set< T, T2 > &set2 );

// returns true if and only if 
// the subtree rooted at node1 is equal to the subtree rooted at node2
template< typename Kty >
bool equal( size_t *node1, size_t *head1,
   size_t *node2, size_t *head2 );

// call preorder1 and inorder1
template< typename T, typename T1 >
void twoTraversals1( set< T, T1 > &set1 );

// preorder traversal on our set
template< typename Kty >
void preorder1( size_t *node, size_t *head );

// inorder traversal on our set
template< typename Kty >
void inorder1( size_t *node, size_t *head );

// call preorder2 and inorder2
template< typename T, typename T2 >
void twoTraversals2( std::set< T, T2 > &set2 );

// preorder traversal on STL set
template< typename Kty >
void preorder2( size_t *node, size_t *head );

// inorder traversal on STL set
template< typename Kty >
void inorder2( size_t *node, size_t *head );

unsigned long long int twoTo32 = static_cast< unsigned long long int >( ULONG_MAX ) + 1;

int main()
{
   for( unsigned int seed = 1; seed <= 4; seed++ )
   {
      srand( seed );
      testSet< unsigned int >();
   }

   for( unsigned int seed = 1; seed <= 4; seed++ )
   {
      srand( seed );
      testSet< unsigned int, greater< unsigned int >, std::greater< unsigned int > >();
   }

   for( unsigned int seed = 1; seed <= 4; seed++ )
   {
      srand( seed );
      testSet< unsigned short >();
   }

   for( unsigned int seed = 1; seed <= 4; seed++ )
   {
      srand( seed );
      testSet< unsigned short, greater< unsigned short >, std::greater< unsigned short > >();
   }

   system( "pause" );
}

template< typename T, typename T1, typename T2 >
void testSet()
{
   unsigned int number = 16;
   Triple *pre = new Triple[ number + 2 ];
   preSequence( pre, 4 * number );

   set< T, T1 > set1;
   std::set< T, T2 > set2;
   for( unsigned int i = 1; i <= number; i++ )
   {
      set1.insert( pre[ i ].mid );
      set2.insert( pre[ i ].mid );
//      cout << setw( 5 ) << pre[ i ].mid;
   }
//   cout << endl;

   set1.insert( 1 );
   set2.insert( 1 );
   set1.insert( pre[ 1 ].mid - 2 );
   set2.insert( pre[ 1 ].mid - 2 );
   set1.insert( pre[ 1 ].mid - 1 );
   set2.insert( pre[ 1 ].mid - 1 );

//   twoTraversals1< T, T1 >( set1 );
//   twoTraversals2< T, T2 >( set2 );

   unsigned int numErrors = number / 2 + 1;
   if( equal( set1, set2 ) )
      numErrors--;

   unsigned int k;
   for( unsigned int i = 1; i <= number / 2; i++ )
   {
      k = rand() % ( number + 1 );
      set1.erase( pre[ k ].mid );
      set2.erase( pre[ k ].mid );

//      twoTraversals1< T, T1 >( set1 );
//      twoTraversals2< T, T2 >( set2 );

      if( equal( set1, set2 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}

void preSequence( Triple preorder[], unsigned int number )
{
   preorder[ 1 ].low = 1;
   preorder[ 1 ].high = number;
   preorder[ 1 ].mid = ( preorder[ 1 ].low + preorder[ 1 ].high ) / 2;

   unsigned int parent = 0;
   unsigned int child = 1;
   while( child < number / 4 )
   {
      parent++;
      child++;
      preorder[ child ].low = preorder[ parent ].low;
      preorder[ child ].high = preorder[ parent ].mid - 1;
      preorder[ child ].mid = ( preorder[ child ].low + preorder[ child ].high ) / 2;

      child++;
      preorder[ child ].low = preorder[ parent ].mid + 1;
      preorder[ child ].high = preorder[ parent ].high;
      preorder[ child ].mid = ( preorder[ child ].low + preorder[ child ].high ) / 2;
   }
}

// returns true if and only if set1 == set2
template< typename T, typename T1, typename T2 >
bool equal( set< T, T1 > &set1, std::set< T, T2 > &set2 )
{
   size_t size1 = *( reinterpret_cast< size_t * >( &set1 ) + 2 );
   size_t size2 = *( reinterpret_cast< size_t * >( &set2 ) + 2 );
   //   cout << "size1  " << size1 << endl;
   //   cout << "size2  " << size2 << endl;

   if( size1 != size2 )
      return false;

   size_t *head1 = *( reinterpret_cast< size_t ** >( &set1 ) + 1 );
   size_t *head2 = *( reinterpret_cast< size_t ** >( &set2 ) + 1 );

   size_t color1 = *( head1 + 3 ) % twoTo32;
   size_t color2 = *( head2 + 3 ) % 256;

   if( color1 != color2 )
      return false;

   bool isNil1;
   if( sizeof( size_t ) == 8 ) // x64 platform
      isNil1 = static_cast< bool >( *( head1 + 3 ) / twoTo32 % 256 );
   else // x86 platform
      isNil1 = static_cast< bool >( *( head1 + 4 ) % 256 );
   bool isNil2 = static_cast< bool >( *( head2 + 3 ) / 256 % 256 );

   if( isNil1 != isNil2 )
      return false;

   if( size1 == 0 )
      return true;

   size_t *root1 = *( reinterpret_cast< size_t ** >( head1 ) + 1 );
   size_t *root2 = *( reinterpret_cast< size_t ** >( head2 ) + 1 );
   return equal< T >( root1, head1, root2, head2 );
}

// returns true if and only if 
// the subtree rooted at node1 is equal to the subtree rooted at node2
template< typename Kty >
bool equal( size_t *node1, size_t *head1,
   size_t *node2, size_t *head2 )
{
   // node1 == head1 if and only if node1 is an external node
   // node2 == head2 if and only if node2 is an external node
   if( node1 == head1 && node2 == head2 )
      return true;

   if( node1 == head1 && node2 != head2 )
      return false;

   if( node1 != head1 && node2 == head2 )
      return false;

   Kty myVal1;
   Kty myVal2;
   if( sizeof( size_t ) == 8 ) // x64 platform
   {
      myVal1 = static_cast< Kty >( *( node1 + 4 ) % twoTo32 );
      myVal2 = static_cast< Kty >( *( node2 + 3 ) / twoTo32 );
   }
   else // x86 platform
   {
      myVal1 = static_cast< Kty >( *( node1 + 5 ) );
      myVal2 = static_cast< Kty >( *( node2 + 4 ) );
   }

   if( myVal1 != myVal2 )
      return false;

   size_t color1 = *( node1 + 3 ) % twoTo32;
   size_t color2 = *( node2 + 3 ) % 256;
   if( color1 != color2 )
      return false;

   bool isNil1;
   if( sizeof( size_t ) == 8 ) // x64 platform
      isNil1 = static_cast< bool >( *( node1 + 3 ) / twoTo32 % 256 );
   else // x86 platform
      isNil1 = static_cast< bool >( *( node1 + 4 ) % 256 );
   bool isNil2 = static_cast< bool >( *( node2 + 3 ) / 256 % 256 );

   if( isNil1 != isNil2 )
      return false;

   size_t *leftChild1 = *( reinterpret_cast< size_t ** >( node1 ) );
   size_t *rightChild1 = *( reinterpret_cast< size_t ** >( node1 ) + 2 );
   size_t *leftChild2 = *( reinterpret_cast< size_t ** >( node2 ) );
   size_t *rightChild2 = *( reinterpret_cast< size_t ** >( node2 ) + 2 );

   return equal< Kty >( leftChild1, head1, leftChild2, head2 ) &&
      equal< Kty >( rightChild1, head1, rightChild2, head2 );
}

template< typename T, typename T1 >
void twoTraversals1( set< T, T1 > &set1 )
{
   size_t *head1 = *( reinterpret_cast< size_t ** >( &set1 ) + 1 );
   size_t *root1 = *( reinterpret_cast< size_t ** >( head1 + 1 ) );

   cout << "our set:\n";
   cout << "Preorder sequence:\n";
   preorder1< size_t >( root1, head1 );

   cout << "\nInorder sequence:\n";
   inorder1< size_t >( root1, head1 );
   cout << endl << endl;
}

// preorder traversal
template< typename Kty >
void preorder1( size_t *node, size_t *head )
{
   if( node != head )
   {
      Kty myVal;
      if( sizeof( size_t ) == 8 ) // x64 platform
         myVal = static_cast< Kty >( *( node + 4 ) % twoTo32 );
      else // x86 platform
         myVal = static_cast< Kty >( *( node + 5 ) );

      size_t color = *( node + 3 ) % twoTo32;
      cout << setw( 5 ) << myVal << ( static_cast< Color >( color ) == Color::Red ? "R" : "B" );

      size_t *leftChild = *( reinterpret_cast< size_t ** >( node ) );
      size_t *rightChild = *( reinterpret_cast< size_t ** >( node ) + 2 );
      preorder1< size_t >( leftChild, head );
      preorder1< size_t >( rightChild, head );
   }
}

// inorder traversal
template< typename Kty >
void inorder1( size_t *node, size_t *head )
{
   if( node != head )
   {
      size_t *leftChild = *( reinterpret_cast< size_t ** >( node ) );
      inorder1< size_t >( leftChild, head );

      Kty myVal;
      if( sizeof( size_t ) == 8 ) // x64 platform
         myVal = static_cast< Kty >( *( node + 4 ) % twoTo32 );
      else // x86 platform
         myVal = static_cast< Kty >( *( node + 5 ) );

      size_t color = *( node + 3 ) % twoTo32;
      cout << setw( 5 ) << myVal << ( static_cast< Color >( color ) == Color::Red ? "R" : "B" );

      size_t *rightChild = *( reinterpret_cast< size_t ** >( node ) + 2 );
      inorder1< size_t >( rightChild, head );
   }
}

template< typename T, typename T2 >
void twoTraversals2( std::set< T, T2 > &set2 )
{
   size_t *head2 = *( reinterpret_cast< size_t ** >( &set2 ) + 1 );
   size_t *root2 = *( reinterpret_cast< size_t ** >( head2 + 1 ) );

   cout << "STL set:\n";
   cout << "Preorder sequence:\n";
   preorder2< size_t >( root2, head2 );

   cout << "\nInorder sequence:\n";
   inorder2< size_t >( root2, head2 );
   cout << endl << endl;
}

// preorder traversal
template< typename Kty >
void preorder2( size_t *node, size_t *head )
{
   if( node != head )
   {
      Kty myVal;
      if( sizeof( size_t ) == 8 ) // x64 platform
         myVal = static_cast< Kty >( *( node + 3 ) / twoTo32 );
      else // x86 platform
         myVal = static_cast< Kty >( *( node + 4 ) );

      size_t color = *( node + 3 ) % 256;
      cout << setw( 5 ) << myVal << ( static_cast< Color >( color ) == Color::Red ? "R" : "B" );

      size_t *leftChild = *( reinterpret_cast< size_t ** >( node ) );
      size_t *rightChild = *( reinterpret_cast< size_t ** >( node ) + 2 );
      preorder2< size_t >( leftChild, head );
      preorder2< size_t >( rightChild, head );
   }
}

// inorder traversal
template< typename Kty >
void inorder2( size_t *node, size_t *head )
{
   if( node != head )
   {
      size_t *leftChild = *( reinterpret_cast< size_t ** >( node ) );
      inorder2< size_t >( leftChild, head );

      Kty myVal;
      if( sizeof( size_t ) == 8 ) // x64 platform
         myVal = static_cast< Kty >( *( node + 3 ) / twoTo32 );
      else // x86 platform
         myVal = static_cast< Kty >( *( node + 4 ) );

      size_t color = *( node + 3 ) % 256;
      cout << setw( 5 ) << myVal << ( static_cast< Color >( color ) == Color::Red ? "R" : "B" );

      size_t *rightChild = *( reinterpret_cast< size_t ** >( node ) + 2 );
      inorder2< size_t >( rightChild, head );
   }
}