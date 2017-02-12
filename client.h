// Jiaqi Luo, cs202, hw3, client.h, 8/1/2014
// this file contains the declaration of the client class

#include "heap.h"

class client {
public:
  // constructor
  client();
  // destructor
  ~client();
  // this function asks the user
  // the number of games and
  // save the value to num_of_game
  // input:
  //     num_of_game -- int for number of games
  void prompt_num_of_games();
  // initial the heap,
  void initial_game();
  // this fucntoin asks user to choose a game to play
  int prompt_choice();
  // this function plays a game deponding on
  // the index,
  // input:
  //    index -- the index of game for playing
  void play_a_game(int index);
  // this function starts the whole game
  void play();

protected:
  int num_of_game; // number of nodes in the heap
  heap tree;       // a heap
};
