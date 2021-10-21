// xtree internal header

#ifndef XTREE
#define XTREE

enum class Color{ Red, Black }; // colors for link to parent

template< typename Ty >
struct TreeNode
{
   using NodePtr = TreeNode *;
   using value_type = Ty;

   NodePtr    left;   // left subtree, or smallest element if head
   NodePtr    parent; // parent, or root of tree if head
   NodePtr    right;  // right subtree, or largest element if head
   Color      color;  // Red or Black, Black if head
   bool       isNil;  // true only if head (also nil) node
   value_type myval;  // the stored value, unused if head
};

// CLASS TEMPLATE TreeVal
template< typename Ty >
class TreeVal
{
public:
   using NodePtr = TreeNode< Ty > *;

   using value_type = Ty;
   using size_type  = size_t;

   TreeVal()
      : myHead( new TreeNode< value_type > ),
        mySize( 0 )
   {
      myHead->left = myHead;
      myHead->parent = myHead;
      myHead->right = myHead;
      myHead->color = Color::Black;
      myHead->isNil = true;
   }

   ~TreeVal()
   {
      clear( myHead->parent );
      delete myHead;
   }

   // Removes all elements from the set object (which are destroyed)
   void clear( TreeNode< value_type > *node )
   {
      if( !node->isNil ) // node is not an external node
      {
         clear( node->left );
         clear( node->right );
         delete node;
      }
   }

   // rebalance for insertion
   void reBalance( TreeNode< value_type > *node )
   {  // node->parent cannot be the root
	   if (node->parent == myHead->parent)
		   return;
	   NodePtr p = node->parent;
	   NodePtr g = p->parent;
	   if (node->color == Color::Red && p->color == Color::Red)
	   {
		   if (g->left == p)
		   {
			   if (g->right->color == Color::Red)
			   {
				   if (g != myHead->parent)
					   g->color = Color::Red;
				   g->left->color = Color::Black;
				   g->right->color = Color::Black;
			   }
			   else
			   {
				   if (p->left == node)
					   LLRotation(p);
				   else if (p->right == node)
				   {
					   RRRotation(node);
					   LLRotation(node);
				   }
			   }
		   }
		   else if (g->right == p)
		   {
			   if (g->left->color == Color::Red)
			   {
				   if (g != myHead->parent)
					   g->color = Color::Red;
				   g->left->color = Color::Black;
				   g->right->color = Color::Black;
			   }
			   else
			   {
				   if (g->right == p && p->right == node)
					   RRRotation(p);
				   else if (g->right == p && p->left == node)
				   {
					   LLRotation(node);
					   RRRotation(node);
				   }
			   }
		   }
	   }
	   reBalance(p);
   }

   // rotate right at g, where p = g->left and node = p->left
   //void set< Kty >::LLbRotation( TreeNode< value_type > *node )
   void LLRotation( TreeNode< value_type > *p )
   {
	   NodePtr g = p->parent;

	   Color temp = p->color;
	   p->color = g->color;
	   g->color = temp;

	   if (g->parent->left == g)
		   g->parent->left = p;
	   else if (g->parent->right == g)
		   g->parent->right = p;
	   p->parent = g->parent;

	   g->left = p->right;
	   if (!g->left->isNil)
		   g->left->parent = g;

	   p->right = g;
	   g->parent = p;

   }

   // rotate left at g, where p = g->right and node = p->right
   //void set< Kty >::RRbRotation( TreeNode< value_type > *node )
   void RRRotation( TreeNode< value_type > *p )
   {
	   NodePtr g = p->parent;

	   Color temp = p->color;
	   p->color = g->color;
	   g->color = temp;

	   if (g->parent->left == g)
		   g->parent->left = p;
	   else if (g->parent->right == g)
		   g->parent->right = p;
	   p->parent = g->parent;

	   g->right = p->left;
	   if (!g->right->isNil)
		   g->right->parent = g;

	   p->left = g;
	   g->parent = p;
   }

   // erase node provided that the degree of node is at most one
   void eraseDegreeOne( TreeNode< value_type > *node )
   {
	   NodePtr p = node->parent;
	   NodePtr child = myHead;
	   if (!node->right->isNil)
		   child = node->right;
	   if (!node->left->isNil)
		   child = node->left;
	  
	   if (p->left == node)
		   p->left = child;
	   else if (p->right == node)
		   p->right = child;
	   if (child != myHead)
		   child->parent = p;

	   if (child->color == Color::Red)
	   {
		   child->color = Color::Black;
	   }
	   else if (node->color == Color::Black)
	   {
		   fixUp(child, p);
	   }
	   delete node;
	   mySize--;
   }

   // rebalance for deletion
   void fixUp( TreeNode< value_type > *N, TreeNode< value_type > *P )
   {
	   if (P->left == N)
	   {
		   P->right->right->color = Color::Black;
		   RRRotation(P->right);
	   }
	   else //if(P->right == N)
	   {
		   P->left->left->color = Color::Black;
		   LLRotation(P->left);
	   }
   }

/*
   // preorder traversal and inorder traversal
   void twoTraversals()
   {
      cout << "Preorder sequence:\n";
      preorder( myHead->parent );

      cout << "\nInorder sequence:\n";
      inorder( myHead->parent );
      cout << endl;
   }

   // preorder traversal
   void preorder( TreeNode< value_type > *node )
   {
      if( node != myHead )
      {
         cout << setw( 5 ) << node->myval << ( node->color == Color::Red ? "R" : "B" );
         preorder( node->left );
         preorder( node->right );
      }
   }

   // inorder traversal
   void inorder( TreeNode< value_type > *node )
   {
      if( node != myHead )
      {
         inorder( node->left );
         cout << setw( 5 ) << node->myval << ( node->color == Color::Red ? "R" : "B" );
         inorder( node->right );
      }
   }
*/

   NodePtr myHead;   // pointer to head node
   size_type mySize; // number of elements
};

// CLASS TEMPLATE Tree
template< typename Traits >
class Tree // ordered red-black tree for map/multimap/set/multiset
{
public:
   using value_type = typename Traits::value_type;

protected:
   using ScaryVal = TreeVal< value_type >;

public:
   using key_type      = typename Traits::key_type;
   using key_compare   = typename Traits::key_compare;

   using size_type       = size_t;

   Tree( const key_compare &parg )
      : keyCompare( parg ),
        scaryVal()
   {
   }

   ~Tree()
   {
   }

   // Extends the container by inserting a new element,
   // effectively increasing the container size by one.
   void insert( const value_type &val )
   {
	   TreeNode< value_type >* newTN = new  TreeNode< value_type >();
	   newTN->parent = scaryVal.myHead;
	   newTN->left = scaryVal.myHead;
	   newTN->right = scaryVal.myHead;
	   newTN->myval = val;
	   newTN->color = Color::Red;
	   newTN->isNil = false;

	   TreeNode< value_type >* fip = scaryVal.myHead->parent; //find insert position;
	   for (; !fip->isNil;)
	   {
		   if (keyCompare(val, fip->myval))
		   {
			   if (fip->left->isNil)
				   break;
			   fip = fip->left;
		   }
		   else if (keyCompare(fip->myval, val))
		   {
			   if (fip->right->isNil)
				   break;
			   fip = fip->right;
		   }
		   else
			   return;
	   }
	   if(fip == scaryVal.myHead) //fip is myhead
	   {
		   newTN->color = Color::Black;
		   scaryVal.myHead->left = newTN;
		   scaryVal.myHead->right = newTN;
		   scaryVal.myHead->parent = newTN;
	   }
	   else if (keyCompare(val, fip->myval))
	   {
		   fip->left = newTN;
		   if (keyCompare(val, scaryVal.myHead->left->myval))
			   scaryVal.myHead->left = newTN;
	   }
	   else if (keyCompare(fip->myval, val))
	   {
		   fip->right = newTN;
		   if (keyCompare(scaryVal.myHead->right->myval, val))
			   scaryVal.myHead->right = newTN;
	   }
	   newTN->parent = fip;

	   scaryVal.reBalance(newTN);
	   scaryVal.mySize++;
   }

   // Removes from the set container a single element whose value is val
   // This effectively reduces the container size by one, which are destroyed.
   // Returns the number of elements erased.
   size_type erase( const key_type &val )
   {
	   TreeNode< value_type >* fep = scaryVal.myHead->parent; //find erase position;
	   for (; !fep->isNil;)
	   {
		   if (keyCompare(val, fep->myval))
			   fep = fep->left;
		   else if (keyCompare(fep->myval, val))
			   fep = fep->right;
		   else
			   break;
	   }
	   if(fep->isNil)
		   return scaryVal.mySize;
	   if (!fep->left->isNil && !fep->right->isNil)
	   {
		   TreeNode< value_type >* keep = fep;
		   fep = fep->right;
		   for (;!fep->left->isNil; fep = fep->left);
		   keep->myval = fep->myval;
	   }
	   
	   scaryVal.eraseDegreeOne(fep);

	   return scaryVal.mySize;
   }

private:
   key_compare keyCompare;
   ScaryVal scaryVal;
};

#endif // XTREE