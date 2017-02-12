// Jiaqi Luo, cs202, hw3, board.h
// this file contains the declaration of the board class

class board {
public:
  board();
  board(const board &source);
  ~board();
  // display the 3*3 board, and the values in the array on the corresponsed
  // positon
  // output:
  //      |   |
  //   -----------
  //      |   |
  //   -----------
  //      |   |
  void display();
  // this function checks the current board to see whether win or tie,
  // output:
  //     1 -- win
  //     2 -- tie
  //     3 -- continue
  int check_win();

protected:
  char *array; // a array of characters for marking
  int drawed;  // the count munber for drawed positions
};
