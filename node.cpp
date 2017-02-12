// Jiaqi Luo, cs202, hw3, node.cpp, 8/1/2014
// this file contains the declaration of functions of the node class
#include "node.h"
#include <iostream>
using namespace std;

// construcor,
// call the tic_tac_toe's constructor first,
// then set left and right to NULL, and priority to 0
node::node() : tic_tac_toe(), left(NULL), right(NULL) {}

// distructor,
// delete left and right if they are not NULL
node::~node() {
  if (left) {
    delete left;
    left = NULL;
  }
  if (right) {
    delete right;
    right = NULL;
  }
}

// copy constructor,
// deeply copy from the source by calling the tic_tac_toe's copy constructor and
// copying the left and right pointer
node::node(const node *&source) : tic_tac_toe(*source) {
  if (source) {
    if (left) {
      delete left;
      left = source->left;
    }
    if (right) {
      delete right;
      right = source->right;
    }
  }
}

// return the node poitner to left in the current ndoe
// output:
//     node pointer to the left
node *&node::goto_left() { return left; }

// return the node poitner to right in the current ndoe
// output:
//     node pointer to the right
node *&node::goto_right() { return right; }

// this function set the pointer to left to the soruce.
void node::set_left(node *left) { this->left = left; }

// this function set the pointer to right to the soruce.
void node::set_right(node *right) { this->right = right; }

// this function overload the operator > ,
// it compares the drawed value in node b with the one in the current node
// input:
//     a node poitner
// output:
//     true -- current > b
//     false -- current < b
bool node::operator>(const node *b) { return (this->drawed > b->drawed); }

// this function overload the operator < ,
// it compares the drawed value in node b with the one in the current node
// input:
//     a node poitner
// output:
//     true -- current < b
//     false -- current > b
bool node::operator<(const node *b) { return (this->drawed < b->drawed); }

// this function overload the operator == ,
// it compares the drawed value in node b with the one in the current node
// input:
//     a node poitner
// output:
//     true -- current = b
//     false -- current != b
bool node::operator==(const node *b) { return (this->drawed == b->drawed); }

// this function display the priority
// output:
//       the value of priority
void node::display_priority() { cout << get_priority(); }
