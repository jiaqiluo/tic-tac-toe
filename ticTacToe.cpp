// Jiaqi Luo, cs202, hw3, tic_tac_toe.cpp
// this file contains the functions of the  the tic_tac_toe class
#include "ticTacToe.h"
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

// constructor
tic_tac_toe::tic_tac_toe() : board(), game_over(false) {}

// copy constructor
// deeply copy form the source
tic_tac_toe::tic_tac_toe(const tic_tac_toe &source)
    : board(source), game_over(source.game_over) {}

// disctructor
// delete the board if it is not empty
tic_tac_toe::~tic_tac_toe() {}

// This function prompt the position for marking from the player
// it will repeating asking for inputing until the value is between 0 and
// 8(included 0 and 8)
// finally, it returns the value.
// output:
//      the int value for marking
int tic_tac_toe::prompt_position() {
  int choice = 100;
  do {
    cout << " enter a number(1 - 9): ";
    cin >> choice;
    cin.ignore();
  } while (choice < 1 || choice > 9);
  return choice - 1;
}

// this function play a drawing for a particular player
// it prompts the position for drawing fistly, and draw the 'X' or 'O',
// then, it will check whether one player wins or tie.
// input:
//     the int respenests player
// output:
//      1 -- win
//      2 -- tie
//      3 -- continue
//      0 -- error
int tic_tac_toe::play(int player) {
  display();
  cout << "player" << player;
  int choice = prompt_position();
  draw_a_mark(player, choice);
  display();
  int check = check_win();
  if (check == 1) {
    game_over = true;
    cout << "\nplayer" << player << " wins" << endl;
    return 1;
  }
  if (check == 2) {
    game_over = true;
    cout << "tie" << endl;
    return 2;
  }
}

// this fucntion plays a round of the game,
// player1 play a step first, then player2 plays a step
void tic_tac_toe::play_a_round() {
  if (play(1) == 3)
    play(2);
}

// this function changes the value of choiced position to 'X' or 'O' deponding
// on the player number
// if success marking, return 1, otherwise return 0
// input:
//     player's number, ex. 1 or 2
//     the position for marking, ex. 0 - 8
// output:
//     1 -- mark successful
//     0 -- error or false
int tic_tac_toe::draw_a_mark(int player, int choice) {
  if (array[choice] == 32) {
    if (player == 1)
      array[choice] = 'X';
    else if (player == 2)
      array[choice] = 'O';
    ++drawed;
    return 1;
  } else {
    cout << "\nThe position has been used." << endl;
    draw_a_mark(player, tic_tac_toe::prompt_position());
  }
}

// this function check whether the game is finished
// output:
//     true -- game over
//     false -- game doesn't finish
bool tic_tac_toe::is_game_finished() { return game_over; }

// this function return the value of drawed as the priority
// output:
//      int -- for priority
int tic_tac_toe::get_priority() { return drawed; }
