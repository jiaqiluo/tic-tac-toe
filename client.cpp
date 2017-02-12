// Jiaqi Luo, cs202, hw3, client.cpp, 8/1/2014
// this file contains the declaration of functions of the client class
#include "client.h"
#include <iostream>

using namespace std;

// constructor
client::client() : num_of_game(0) {}

// destructor
client::~client() {}

// this function asks the user
// the number of games and
// save the value to num_of_game
// input:
//     num_of_game -- int for number of games
void client::prompt_num_of_games() {
  cout << "how namy games do you wnat to play: ";
  cin >> num_of_game;
  cin.ignore();
}

// this fucntoin asks user to choose a game to play
// and check the choice until it is available
int client::prompt_choice() {
  cout << "\nnotice: the order of games may different with last time" << endl;
  cout << "\ncurrent priority list: ";
  tree.display_priority();
  cout << "\nthe  index  of  games: ";
  for (int i = 0; i < num_of_game; ++i)
    cout << i + 1 << "  ";
  int index = 0;
  cout << "\nenter the index of the game you wnat to play: ";
  cin >> index;
  cin.ignore();
  while (index < 0 || index > num_of_game) {
    index = 0;
    cout << "invaild index. try again:";
    cin >> index;
    cin.ignore();
  }
  return index;
}

// initial the heap,
// create nodes deponding on the user's
// willing
void client::initial_game() {
  node *temp = new node;
  for (int i = 0; i < num_of_game; ++i)
    tree += temp;
  delete temp;
}

// this function plays a game deponding on
// the index,
// and reset the mumber of games after game
// input:
//    index -- the index of game for playing
void client::play_a_game(int index) {
  tree.play_a_game(index);
  num_of_game = tree.check_num_of_node();
}

// this function starts the whole game
void client::play() {
  prompt_num_of_games();
  initial_game();
  while (num_of_game > 0) {
    int index = prompt_choice();
    play_a_game(index);
  }
  cout << "\n\tGAME OVER" << endl;
  return;
}
