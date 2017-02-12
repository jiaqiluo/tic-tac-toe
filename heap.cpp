// Jiaqi Luo, cs202, hw3, heap.cpp, 8/1/2014
// this file contains the declaration of functions of the heap class

#include "heap.h"
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

// constructor
// set root to NULL, deepth and num_of_nodes to 0
heap::heap() : root(NULL), num_of_nodes(0) {}

// distructor
// remove the tree by calling remove_all fucntion
heap::~heap() {
  remove_all(root);
  num_of_nodes = 0;
}

// this function traverse the tree recersively to clear up the heap,
// it goes to the very left of the tree, and delete the node,
// then return to upper level to delet its right child,
// repeating until delete all nodes
void heap::remove_all(node *&root) {
  if (!root)
    return;
  remove_all(root->goto_left());
  remove_all(root->goto_right());
  delete root;
  root = NULL;
  num_of_nodes = 0;
}

// this function copys all noeds but game finished
// from heap source to the current heap
// by incoking another function
// input:
//     source - a heap as soruce
void heap::copy_not_finished(heap &source) {
  remove_all(root);
  num_of_nodes = 0;
  copy_not_finished(source.root);
}

// this function copys nodes source to the current heap
// it will check whether the game in the soruce finish,
// if not finish, copy it to current tree,
// input:
//     source -- a pointer to node as source
void heap::copy_not_finished(node *&source) {
  if (!source)
    return;
  if (source->is_game_finished() == false) {
    insert(root, source);
    ++num_of_nodes;
  }
  copy_not_finished(source->goto_left());
  copy_not_finished(source->goto_right());
}

// this function overloads += operator for inserting
// a new node to the tree by invkoing insert function
// input:
//     source -- pointer to node as the new node
// output:
//     add the node to the tree
heap &heap::operator+=(const node *source) {
  insert(root, source);
  ++num_of_nodes;
  return *this;
}

// this function insert a node to the complete tree,
// because in the game, all nodes are inserted at the begining,
// so they all the default "empty" nodes, which meams we don't
// need to consider the priority.
// strategy:
// 1. check root first, if it's NULL, them deeply copy source to root
// 2. if root exists, count the number of nodes in left sub tree and right sub
// tree. check the left sub tree to see whether it is a full tree
// 3. if the left sub tree is full, check whther both sub trees have the same
// number of nodes.
//   1> if they have the same number of nodes, means both are full, so go to the
//   very left of the heap to insert the source
//   2> otherwise, go to right sub tree by calling itselfe
// 4. if the left sub tree is not full, go to the left sub tree to insert the
// source
// input:
//     root -- node pointer to root
//     source -- node pointrt to source
void heap::insert(node *&root, const node *source) {
  if (!root) {
    root = new node(source);
    return;
  }
  int left = count(root->goto_left());
  int right = count(root->goto_right());
  if (left < right)
    return;
  if (is_full_tree(root->goto_left(), left)) {
    if (left == right)
      insert(root->goto_left(), source);
    else
      insert(root->goto_right(), source);
  } else
    insert(root->goto_left(), source);
}

// this function count the number of nodes in the current tree,
// it traverses the tree recursively, and return the count finally
// input:
//     root -- pointer to node as argument
// output:
//     int -- the count of ndoes
int heap::count(node *root) {
  if (!root)
    return 0;
  return 1 + count(root->goto_left()) + count(root->goto_right());
}

// this function ckecks whether the tree is full or not,
// if the tree is empty, return 0
// else, traverse the tree to count the length of the tree
// because the new ndoe is added from left to right,so the
// length of the very left path is the length of the tree.
// if the maximame of a full tree with the same length is
// equal to the number of nodes in the currnt tree, it means
// that the current tree is full, otherwise, it is not full
// input;
//     soruce -- pointer to node as root of the current tree
//     num_of_nodes == the number of nodes in the current tree
// output:
//     true -- the tree is full
//     false -- the tree is not full
bool heap::is_full_tree(node *&source, int num_of_nodes) {
  if (!source) {
    return true;
  } else {
    int deepth = 1;
    node *temp = source->goto_left();
    while (temp) {
      ++deepth;
      temp = temp->goto_left();
    }
    int max = pow(2, deepth) - 1;
    if (max == num_of_nodes)
      return true;
    else
      return false;
  }
}

// this function displays the priority of
// all nodes in the heap in order
// by invoking conresponding function
void heap::display_priority() { display_priority(root); }

// this function displays the priority of
// all nodes in the heap in order
// it invokes itself recurisively
void heap::display_priority(node *&root) {
  if (!root)
    return;
  root->display_priority();
  cout << "  ";
  display_priority(root->goto_left());
  display_priority(root->goto_right());
}

// this function locates the position of the
// node for playing first,
// then play a round and
// reorganize the heap finally
// input:
//     index -- the index of the node for game
void heap::play_a_game(int index) {
  int count = 1;
  node *temp = NULL;
  locate(root, temp, index, count);
  if (temp->is_game_finished()) {
    cout << "the game is finished";
    return;
  }
  temp->play_a_round();
  heap temptory;
  temptory.copy_not_finished(*this);
  remove_all(root);
  copy_not_finished(temptory);
}

// this fucntion recursively traverse the heap in pre-order
// to find the root which on the same index as the index argument//input:
//     root -- pointer to node as the root of the heap
//     target -- pointer to node which is looking for
//     index  -- the index of the target node
//     count  -- count the index
void heap::locate(node *&root, node *&target, int index, int &count) {
  if (!root)
    return;
  if (index == count) {
    target = root;
    ++count;
    return;
  }
  ++count;
  locate(root->goto_left(), target, index, count);
  locate(root->goto_right(), target, index, count);
}

// check the number of ndoes in the heap
// output:
//      int -- number of nodes
int heap::check_num_of_node() { return num_of_nodes; }
