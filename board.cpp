// Jiaqi Luo, cs202, hw3, board.cpp
// this file contains the functions of the board class

#include "board.h"
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

// constructor
// declear a new array of char whose size is 9
// and all the values are blank
// and set the drawed to 0
board::board() : drawed(0) {
  array = new char[9];
  for (int i = 0; i < 9; ++i)
    array[i] = 32;
}

// copy constructor
// deeply copy form the source
board::board(const board &source) : drawed(source.drawed) {
  array = new char[9];
  for (int i = 0; i < 9; ++i)
    array[i] = source.array[i];
}

// disctructor
// delete the board if it is not empty
board::~board() {
  if (array)
    delete[] array;
}

// display the 3*3 board, and the values in the array on the corresponsed
// positon
// output:
//      |   |
//   -----------
//      |   |
//   -----------
//      |   |
void board::display() {
  cout << "\n\n\tTic Tac Toe\n\n";
  cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
  cout << endl;
  cout << "     |     |     " << endl;
  cout << "  " << array[0] << "  |  " << array[1] << "  |  " << array[2]
       << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << array[3] << "  |  " << array[4] << "  |  " << array[5]
       << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << array[6] << "  |  " << array[7] << "  |  " << array[8]
       << endl;
  cout << "     |     |     " << endl << endl;
}

// this function checks the current board to see whether win or tie,
// if values on one of the following situations are the same, return 1 for
// wining:
// 0,1,2 or 3,4,5 or 6,7,8 or 1,3,6 or 2,4,7 or 3,5,8 or 0,4,8 or 2,4,6
// if all the positions have values, return 2 for tie
// otherwose, return 3
// output:
//     1 -- win
//     2 -- tie
//     3 -- continue
int board::check_win() {
  for (int i = 0; i < 7; i += 3) {
    if (array[i] != 32 && array[i] == array[i + 1] &&
        array[i + 1] == array[i + 2])
      return 1;
  }
  for (int i = 0; i < 3; ++i) {
    if (array[i] != 32 && array[i] == array[i + 3] &&
        array[i + 3] == array[i + 6])
      return 1;
  }
  if (array[0] != 32 && array[0] == array[4] && array[4] == array[8])
    return 1;
  if (array[2] != 32 && array[2] == array[4] && array[4] == array[6])
    return 1;
  if (array[0] != 32 && array[1] != 32 && array[2] != 32 && array[3] != 32 &&
      array[4] != 32 && array[5] != 32 && array[6] != 32 && array[7] != 32 &&
      array[8] != 32)
    return 2;
  else
    return 3;
}
