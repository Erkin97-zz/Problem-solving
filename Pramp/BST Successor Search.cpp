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

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}

/*
if node has right subtree, return minimum node of right subtree, 
else return parent node.
*/

Node* findSmallestNode(Node *inputNode) {
  if (inputNode->left != NULL) {
    return findSmallestNode(inputNode->left);
  } else {
    return inputNode;
  }
}
Node* findRightParent(Node *inputNode) 
{ 
  if (inputNode == NULL || inputNode->parent == NULL) return NULL;
  if (inputNode->parent->key > inputNode->key) {
    return inputNode->parent; 
  } else {
    return findRightParent(inputNode->parent);
  }
}

Node* findInOrderSuccessor( Node *inputNode )
{ 
  if (inputNode->right != NULL) {
    return findSmallestNode(inputNode->right);
  } else if (inputNode->parent != NULL) {
    if (inputNode->parent->key > inputNode->key) {
      return inputNode->parent;  
    } else {
      return findRightParent(inputNode->parent);
    }
  } else {
    return NULL;
  }
}

int main() {
  Node* tree = new Node();
  int a[] = {20, 9, 12, 11, 14, 25, 5};
  for (int i = 0; i < 7; i++) {
    tree = insert(tree, a[i]);
  }
  Node* answer = findInOrderSuccessor(getNodeByKey(tree, 11)); // 20 and 25 - > 20
  if (answer == NULL) {
    cout << "undefined" << endl;
  } else {
    cout << answer->key << endl;
  }
  return 0;
}