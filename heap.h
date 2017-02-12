// Jiaqi Luo, cs202, hw3, heap.h, 8/1/2014
// this file contains the declaration of the heap class
#include "node.h"

class heap {
public:
  // constructor
  heap();
  // distructor
  virtual ~heap();
  // this function overloads += operator for inserting
  // a new node to the tree by invkoing insert function
  // input:
  //     source -- pointer to node as the new node
  // output:
  //     add the node to the tree
  heap &operator+=(const node *source);
  // this function traverse the tree recersively to clear up the heap,
  void remove_all(node *&root);
  // this function displays the priority of
  // all nodes in the heap in order
  void display_priority();
  // play a game
  // input:
  //     index -- the index of the node for game
  void play_a_game(int index);
  // check the number of ndoes in the heap
  // output:
  //      int -- number of nodes
  int check_num_of_node();
  // this function copys all noeds but game finished
  // from heap source to the current heap
  // input:
  //     source - a heap as soruce
  void copy_not_finished(heap &source);
  // this function copys all noeds but game finished
  // from heap source to the current heap
  // input:
  //     source -- a pointer to node as source
  void copy_not_finished(node *&source);

protected:
  // return the node for game
  // input:
  //     index -- the index of the node for game
  //     count -- the number for counting the current position(defalut is 1)
  //     index  -- the index of the target node
  //     count  -- count the index
  void locate(node *&root, node *&target, int index, int &count);
  // this function displays the priority of
  // all nodes in the heap in order
  void display_priority(node *&root);
  // this function insert a node to the complete tree
  // input:
  //     root -- node pointer to root
  //     source -- node pointrt to source
  void insert(node *&root, const node *source);
  // this function count the number of nodes in the current tree,
  // input:
  //     root -- pointer to node as argument
  // output:
  //     int -- the count of ndoes
  int count(node *root);
  // this function ckecks whether the tree is full or not,
  // input;
  //     soruce -- pointer to node as root of the current tree
  //     num_of_nodes == the number of nodes in the current tree
  // output:
  //     true -- the tree is full
  //     false -- the tree is not full
  bool is_full_tree(node *&source, int num_of_nodes);
  node *root;       // pointer to node as root
  int num_of_nodes; // number of nodes in the heap
};
