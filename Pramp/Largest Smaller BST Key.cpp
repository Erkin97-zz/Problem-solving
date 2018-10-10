#include <iostream>

using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}



int findLargestSmallerKey(Node *rootNode, int num) 
{
 if (rootNode == NULL) return -1;
 if (rootNode->key >= num) {
   if (rootNode->left != NULL) {
     return findLargestSmallerKey(rootNode->left, num);
   } else {
     if (rootNode->parent != NULL && rootNode->parent->key < num) {
       return rootNode->parent->key;
     } else {
       return -1;
     }
   }
 } else {
   if (rootNode->right != NULL) {
     return findLargestSmallerKey(rootNode->right, num);
   } else {
     return rootNode->key;
   }
 }
}

int main() {
  Node *tree = newNode(20);
  int test_values[] = {25, 9, 12, 11, 14, 5};
  for (int i = 0; i < 6; i++ ) {
    tree = insert(tree, test_values[i]);
  }
  cout << findLargestSmallerKey(tree, 17);
  return 0;
}
