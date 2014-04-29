#include <iostream>
#include <stack>
using namespace std;

struct Node {
 public:
  Node* left;
  Node* right;
  Node* parent;
  int key;
  int data;
  Node(int x): key(x), data(x), left(NULL), right(NULL), parent(NULL) {}
};


class BinarySearchTree {
public:
  Node* root;
  BinarySearchTree():root(NULL){}

  Node* Insert(Node* node);
  Node* Delete(Node* z);
  void InorderTreeWalkRecursive(Node* x);
  void InorderTreeWalkIterative(Node* x);
  Node* TreeSuccessor(Node* x);
  Node* Minimum(Node* x);
  Node* Maximum(Node* x);
};


/**
 * Define the class
 */
Node* BinarySearchTree::Insert(Node* node) {
  Node* x = root;
  Node* y = NULL;
  while (x != NULL) {
    y = x;
    if (x->key < node->key) {
      x = x->right;
    } else {
      x = x->left;
    }
  }
  node->parent = y;

  // The tree is empty
  if (y == NULL) {
    root = node;
  } else {
    if (y->key > node->key) {
      y->left = node;
    } else {
      y->right = node;
    }
  }
  return node;
}

void BinarySearchTree::InorderTreeWalkRecursive(Node* x) {
  if (x != NULL) {
    InorderTreeWalkRecursive(x->left);
    cout << x->key << endl;
    InorderTreeWalkRecursive(x->right);
  }
}

void BinarySearchTree::InorderTreeWalkIterative(Node* x) {
  stack<Node*> stack;
  while (x != NULL || !stack.empty()) {
    if (x != NULL) {
      stack.push(x);
      x = x->left;
    } else {
      x = stack.top();
      cout << x->key << endl;
      x = x->right;
      stack.pop();
    }
  }
}

Node* BinarySearchTree::Maximum(Node* x) {
  while (x->right != NULL) {
    x = x->right;
  }
  return x;
}

Node* BinarySearchTree::Minimum(Node* x) {
  while (x->left != NULL) {
    x = x->right;
  }
  return x;
}

Node* BinarySearchTree::TreeSuccessor(Node* x) {
  if (x->right != NULL) {
    return Minimum(x->right);
  }
  Node* y = x->parent;
  while (y != NULL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

Node* BinarySearchTree::Delete(Node* z) {
  Node* y = NULL; // The node to be deleted
  Node* x = NULL; // Record the children of y
  // Find the node to be deleted
  if (z->left != NULL || z->right != NULL) {
    y = z;
  } else {
    y = TreeSuccessor(z);
  }

  // Record the children of y
  if (y->left != NULL) {
    x = y->left;
  } else {
    x = y->right;
  }

  // Delete the y from the tree, change the link
  if (x != NULL) {
    x->parent = y->parent;
  }
  if (y->parent == NULL) {
    // The root node;
    root = x;
  } else {
    if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }

  if (y != z) {
    z->key = y->key;
    z->data = y->data;
  }
  return y;
}

int main(int argc, char const *argv[]) {
  Node* n0 = new Node(12);
  Node* n1 = new Node(5);
  Node* n2 = new Node(2);
  Node* n3 = new Node(9);
  Node* n4 = new Node(18);
  Node* n5 = new Node(19);
  Node* n6 = new Node(15);
  Node* n7 = new Node(13);
  Node* n8 = new Node(17);

  BinarySearchTree* tree = new BinarySearchTree();
  tree->Insert(n0);
  tree->Insert(n1);
  tree->Insert(n2);
  tree->Insert(n3);
  tree->Insert(n4);
  tree->Insert(n5);
  tree->Insert(n6);
  tree->Insert(n7);
  tree->Insert(n8);

  tree->Delete(n1);

  tree->InorderTreeWalkIterative(tree->root);

  return 0;
}









