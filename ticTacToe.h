// Jiaqi Luo, cs202, hw3, tic_tac_toe.h
// this file contains the declaration of the tic_tac_toe class
#include "board.h"

class tic_tac_toe : public board {
public:
  // constructor
  // declear a new array of char whose size is 9
  // and all the values are blank
  tic_tac_toe();
  // copy constructor
  tic_tac_toe(const tic_tac_toe &source);
  // disctructor
  // delete the board if it is not empty
  ~tic_tac_toe();
  // This function prompt the position for marking from the player
  // output:
  //      int value for marking
  int prompt_position();
  // this function play a drawing for a particular player
  // output:
  //      1 -- win
  //      2 -- tie
  //      3 -- continue
  //      0 -- error
  int play(int player);
  // this fucntion plays a round of the game,
  // player1 play a step first, then player2 plays a step
  void play_a_round();
  // this function changes the value of choiced position to 'X' or 'O'
  // deponding on the player number
  // input:
  //     player's number, ex. 1 or 2
  //     the position for marking, ex. 0 - 8
  // output:
  //     1 -- mark successful
  //     0 -- error or false
  int draw_a_mark(int player, int choice);
  // this function check whether the game is finished
  bool is_game_finished();
  // return the value of drawed as the priority
  //      int -- for priority
  int get_priority();

protected:
  // a booling value
  // true -- game over
  // false -- game doesn't finish
  bool game_over;
};
