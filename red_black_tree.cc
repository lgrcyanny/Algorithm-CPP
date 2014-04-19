#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
  int key;
  Color color;
  Node* left;
  Node* right;
  Node* parent;

  Node(int x):key(x), color(BLACK), left(NULL), right(NULL), parent(NULL){}
};

class RedBlackTree
{
public:
  Node* root;
  Node* nil; // sentry
  RedBlackTree(){
    nil = new Node(-1);
    root = nil;
  }
  ~RedBlackTree();

  void LeftRotate(Node* x);
  void RightRotate(Node* x);
  void Insert(Node* z);
  void InsertFixup(Node* z);
  Node* Delete(Node* x);
  void InorderTreeWalk(Node* root);
};

/**
 * Define the class RedBlackTree
 */
void RedBlackTree::LeftRotate(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  if (y->left != nil) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nil) {
    root = y;
  } else if (x->parent->left == x) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  x->parent = y;
  y->left = x;
}

void RedBlackTree::RightRotate(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  if (y->right != nil) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nil) {
    root = y;
  } else if (x->parent->left == x) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  x->parent = y;
  y->right = x;
}

void RedBlackTree::Insert(Node* z) {
  Node* y = nil;
  Node* x = root;
  while (x != nil) {
    y = x;
    if (x->key < z->key) {
      x = x->right;
    } else {
      x = x->left;
    }
  }
  z->parent = y;
  if (y == nil) {
    root = z;
  } else {
    if (y->key > z->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
  z->left = nil;
  z->right = nil;
  z->color = RED;
  InsertFixup(z);
}

void RedBlackTree::InsertFixup(Node* z) {
  while (z->parent->color == RED) {
    if (z->parent == z->parent->parent->left) {
      // 1. The brother of z parent is Red
      if (z->parent->parent->right->color == RED) {
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        z->parent->parent->right->color = BLACK;
        z = z->parent->parent;
      } else {
        // 2. The brother of z parent is Black, z is right child of z parent
        if (z == z->parent->right) {
          z = z->parent;
          LeftRotate(z);
        }
        // 2. The brother of z parent is Black, z is left child of z parent
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        RightRotate(z->parent->parent);
      }
    } else {
      // 1. The brother of z parent is Red
      if (z->parent->parent->left->color == RED) {
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        z->parent->parent->left->color = BLACK;
        z = z->parent->parent;
      } else {
        // 2. The brother of z parent is Black, z is left child of z parent
        if (z == z->parent->left) {
          z = z->parent;
          RightRotate(z);
        }
        // 2. The brother of z parent is Black, z is right child of z parent
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        LeftRotate(z->parent->parent);
      }
    }
  }
  root->color = BLACK;
}

void RedBlackTree::InorderTreeWalk(Node* root) {
  if (root != nil) {
    InorderTreeWalk(root->left);
    printf("%d, %s\n", root->key, root->color == RED ? "RED" : "BLACK");
    InorderTreeWalk(root->right);
  }
}

int main(int argc, char const *argv[]) {
  Node* n0 = new Node(11);
  Node* n1 = new Node(2);
  Node* n2 = new Node(1);
  Node* n3 = new Node(7);
  Node* n4 = new Node(4);
  Node* n5 = new Node(5);
  Node* n6 = new Node(8);
  Node* n7 = new Node(14);
  Node* n8 = new Node(15);

  RedBlackTree* tree = new RedBlackTree();
  tree->Insert(n0);
  tree->Insert(n1);
  tree->Insert(n2);
  tree->Insert(n3);
  tree->Insert(n4);
  tree->Insert(n5);
  tree->Insert(n6);
  tree->Insert(n7);
  tree->Insert(n8);

  tree->InorderTreeWalk(tree->root);
  return 0;
}





