// Jiaqi Luo, cs202, hw3, heap.h, 8/1/2014
// this file contains the declaration of the heap class
#include "ticTacToe.h"
#include <iostream>

class node : public tic_tac_toe {
public:
  node();
  node(const node *&source);
  ~node();
  // return the node poitner to left in the current ndoe
  // output:
  //     node pointer to the left
  node *&goto_left();
  // return the node poitner to right in the current ndoe
  // output:
  //     node pointer to the right
  node *&goto_right();
  // set the pointer to left to the soruce.
  void set_left(node *left);
  // set the pointer to right to the soruce.
  void set_right(node *right);
  // compare the drawed value in node b with the one in the current node
  // input:
  //     a node poitner
  // output:
  //     true -- current > b
  //     false -- current < b
  bool operator>(const node *b);
  // compare the drawed value in node b with the one in the current node
  // input:
  //     a node poitner
  // output:
  //     true -- current < b
  //     false -- current > b
  bool operator<(const node *b);
  // compare the drawed value in node b with the one in the current node
  // input:
  //     a node poitner
  // output:
  //     true -- current = b
  //     false -- current != b
  bool operator==(const node *b);
  // this function overload the operator << to display the priority
  // output:
  //       the value of priority
  void display_priority();

protected:
  node *left;  // a poitner to the left child
  node *right; // a pointer to the right child
};
