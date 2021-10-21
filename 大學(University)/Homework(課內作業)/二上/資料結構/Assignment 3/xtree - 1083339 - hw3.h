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
       if (node->parent != myHead->parent && node->color==Color::Red && node->parent->color == Color::Red)
       {
           TreeNode< value_type >* p = node->parent;
           TreeNode< value_type >* g = p->parent;
           if (p->left == node)
           {
               if (g->left == p)
               {
                   if (g->right->color == Color::Black)
                       LLRotation(p);
                   else if (g->right->color == Color::Red)
                   {
                       if (g != myHead->parent)
                           g->color = Color::Red;
                       g->left->color = Color::Black;
                       g->right->color = Color::Black;
                   }
               }
               else if (g->right == p)
               {
                   if (g->left->color == Color::Black)
                       RLRotation(node);
                   else if (g->left->color == Color::Red)
                   {
                       if (g != myHead->parent)
                           g->color = Color::Red;
                       g->left->color = Color::Black;
                       g->right->color = Color::Black;
                   }
               }
           }
           else if (p->right == node)
           {
               if (g->left == p)
               {
                   if (g->right->color == Color::Black)
                       LRRotation(node);
                   else if (g->right->color == Color::Red)
                   {
                       if (g != myHead->parent)
                           g->color = Color::Red;
                       g->left->color = Color::Black;
                       g->right->color = Color::Black;
                   }
               }
               else if (g->right == p)
               {
                   if (g->left->color == Color::Black)
                       RRRotation(p);
                   else if (g->left->color == Color::Red)
                   {
                       if (g != myHead->parent)
                           g->color = Color::Red;
                       g->left->color = Color::Black;
                       g->right->color = Color::Black;
                   }
               }
           }
           reBalance(g);
       }
       return;
   }

   // rotate right at g, where p = g->left and node = p->left
   //void set< Kty >::LLbRotation( TreeNode< value_type > *node )
   void LLRotation( TreeNode< value_type > *p )
   {
       TreeNode< value_type >* g = p->parent;
       TreeNode< value_type >* anchor = g->parent;

       Color tempColor = p->color;
       p->color = g->color;
       g->color = tempColor;

       if (!p->right->isNil)
           p->right->parent = g;
       g->left = p->right;

       g->parent = p;
       p->right = g;

       if (anchor == myHead)
           anchor->parent = p;
       else if (anchor->left == g)
           anchor->left = p;
       else if (anchor->right == g)
           anchor->right = p;
       p->parent = anchor;

       return;
   }

   // LR rotation; p = g->left and node = p->right
   void LRRotation( TreeNode< value_type > *node )
   {
       TreeNode< value_type >* p = node->parent;
       TreeNode< value_type >* g = p->parent;
       TreeNode< value_type >* anchor = g->parent;

       Color tempColor = node->color;
       node->color = g->color;
       g->color = tempColor;

       p->parent = node;
       g->parent = node;
       
       if (!node->left->isNil)
           node->left->parent = p;
       p->right = node->left;

       if (!node->right->isNil)
           node->right->parent = g;
       g->left = node->right;

       node->left = p;
       node->right = g;

       if (anchor == myHead)
           anchor->parent = node;
       else if (anchor->left == g)
           anchor->left = node;
       else if (anchor->right == g)
           anchor->right = node;
       node->parent = anchor;

       return;
   }

   // RL rotation; p = g->right and node = p->left
   void RLRotation( TreeNode< value_type > *node )
   {
       TreeNode< value_type >* p = node->parent;
       TreeNode< value_type >* g = p->parent;
       TreeNode< value_type >* anchor = g->parent;

       Color tempColor = node->color;
       node->color = g->color;
       g->color = tempColor;

       p->parent = node;
       g->parent = node;

       if (!node->right->isNil)
           node->right->parent = p;
       p->left = node->right;

       if (!node->left->isNil)
           node->left->parent = g;
       g->right = node->left;

       node->right = p;
       node->left = g;

       if (anchor == myHead)
           anchor->parent = node;
       else if (anchor->left == g)
           anchor->left = node;
       else if (anchor->right == g)
           anchor->right = node;
       node->parent = anchor;

       return;
   }

   // rotate left at g, where p = g->right and node = p->right
   //void set< Kty >::RRbRotation( TreeNode< value_type > *node )
   void RRRotation( TreeNode< value_type > *p )
   {
       TreeNode< value_type >* g = p->parent;
       TreeNode< value_type >* anchor = g->parent;

       Color tempColor = p->color;
       p->color = g->color;
       g->color = tempColor;

       if (!p->left->isNil)
           p->left->parent = g;
       g->right = p->left;

       g->parent = p;
       p->left = g;

       if (anchor == myHead)
           anchor->parent = p;
       else if (anchor->left == g)
           anchor->left = p;
       else if (anchor->right == g)
           anchor->right = p;
       p->parent = anchor;

       return;
   }

   // erase node provided that the degree of node is at most one
   void eraseDegreeOne( TreeNode< value_type > *node )
   {
       TreeNode<value_type>* child;
       if (!node->left->isNil)
           child = node->left;
       else if(!node->right->isNil)
           child = node->right;
       else
           child = myHead;

       if (node->parent->left == node)
           node->parent->left = child;
       else if (node->parent->right == node)
           node->parent->right = child;

       if (!child->isNil)
           child->parent = node->parent;

       if (node->color == Color::Black && child->color == Color::Black)
       {
           
           fixUp(child, node->parent);
       }
       child->color = Color::Black;
           

       delete node;
       mySize--;
   }

   // rebalance for deletion
   void fixUp( TreeNode< value_type > *N, TreeNode< value_type > *P )
   {
       TreeNode< value_type >* S;
       TreeNode< value_type >* S1;
       TreeNode< value_type >* S2;
       if (P->left == N)
       {
           S = P->right;
           S1 = S->right;
           S2 = S->left;
       }
       else //if (P->right == N)
       {
           S = P->left;
           S1 = S->left;
           S2 = S->right;
       }

       //if (S->isNil || S1->isNil || S2->isNil)
           //return;
       //for (int i = 1; i > 0; i--)
       {
           if (S->color == Color::Red)
           { //case 1
               //cout << "case:1 " << endl;
               if (P->left == N)
                   RRRotation(S);
               else if (P->right == N)
                   LLRotation(S);
               //i++;
               fixUp(N, P);
           }
           else if (S->color == Color::Black)
           {
               if (S1->color == Color::Red)
               { //case 2
                   //cout << "case:2 " << endl;
                   //system("pause");
                   S1->color = Color::Black;
                   if (P->left == N)
                       RRRotation(S);
                   else if (P->right == N)
                       LLRotation(S);
               }
               else if (S1->color == Color::Black)
               {
                   if (S2->color == Color::Red)
                   { //case 3
                       //cout << "case:3 " << endl;
                       if (P->left == N)
                           LLRotation(S2);
                       else if (P->right == N)
                           RRRotation(S2);
                       //i++;
                       fixUp(N, P);
                   }
                   else if (S2->color == Color::Black)
                   {
                       if (P->color == Color::Red)
                       { //case 4
                           //cout << "case:4 " << endl;
                           P->color = Color::Black;
                           S->color = Color::Red;
                       }
                       else if (P->color == Color::Black)
                       { //case 5
                           //cout << "case:5 " << endl;
                           S->color = Color::Red;
                           if (P!=myHead->parent)
                               fixUp(P, P->parent);
                       }
                   }
               }
           }
       }
       
       return;
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
       TreeNode<value_type>* newTN = new TreeNode<value_type>;
       newTN->color = Color::Red;
       newTN->isNil = false;
       newTN->myval = val;
       newTN->parent = scaryVal.myHead;
       newTN->left = scaryVal.myHead;
       newTN->right = scaryVal.myHead;

       if (scaryVal.mySize == 0)
       {
           newTN->color = Color::Black;

           scaryVal.myHead->parent = newTN;
           scaryVal.myHead->left = newTN;
           scaryVal.myHead->right = newTN;
       }
       else
       {
           TreeNode<value_type>* fip = scaryVal.myHead->parent; //to find insert pos
           for (;true;) //if fip->myval==val return
           {
               if (keyCompare(newTN->myval, fip->myval))
               {
                   if (fip->left->isNil) break;
                   fip = fip->left;
               }
               else if (keyCompare(fip->myval, newTN->myval))
               {
                   if (fip->right->isNil) break;
                   fip = fip->right;
               }
               else
                   return;
           }

           newTN->parent = fip; //linking
           if (keyCompare(newTN->myval, fip->myval))
               fip->left = newTN;
           else
               fip->right = newTN;

           if (keyCompare(newTN->myval, scaryVal.myHead->left->myval)) //for min
               scaryVal.myHead->left = newTN;
           if (keyCompare(scaryVal.myHead->right->myval, newTN->myval)) //for max
               scaryVal.myHead->right = newTN;
           
           scaryVal.reBalance(newTN); //rebalance
       }

       scaryVal.mySize++;
       return;
   }

   // Removes from the set container a single element whose value is val
   // This effectively reduces the container size by one, which are destroyed.
   // Returns the number of elements erased.
   size_type erase( const key_type &val )
   {
       if (scaryVal.mySize > 0)
       {
           TreeNode<value_type>* fee = scaryVal.myHead->parent; //to find erase element
           for (; true;) //find fee->myval==val 
           {
               if (keyCompare(val, fee->myval))
               {
                   if (fee->left->isNil) return scaryVal.mySize;
                   fee = fee->left;
               }
               else if (keyCompare(fee->myval, val))
               {
                   if (fee->right->isNil) return scaryVal.mySize;
                   fee = fee->right;
               }
               else
                   break;
           }

           if (!fee->left->isNil && !fee->right->isNil)
           {
               TreeNode<value_type>* keep = fee;
               fee = fee->right;
               for (; !fee->left->isNil; fee = fee->left);
               keep->myval = fee->myval;
           }

           scaryVal.eraseDegreeOne(fee);
       }
       return scaryVal.mySize;
   }

private:
   key_compare keyCompare;
   ScaryVal scaryVal;
};

#endif // XTREE