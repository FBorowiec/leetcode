#ifndef CPP_0130_SURROUNDED_REGIONS_HPP
#define CPP_0130_SURROUNDED_REGIONS_HPP

#include <vector>

namespace surrounded_regions {

class Solution {
 public:
  /**
   * Given a 2D board containing 'X' and 'O' (the letter O),
   * capture all regions surrounded by 'X'.
   * A region is captured by flipping all 'O's into 'X's in that surrounded region.
   *
   * Surrounded regions shouldn’t be on the border, which means that any 'O' on the border
   * of the board are not flipped to 'X'. Any 'O' that is not on the border
   * and it is not connected to an 'O' on the border will be flipped to 'X'.
   * Two cells are connected if they are adjacent cells connected horizontally or vertically.
   */
  void DepthFirstSearch(int i, int j, std::vector<std::vector<char>>& board) {
    if (i < 0 || i > r - 1 || j < 0 || j > c - 1) return;

    if (board[i][j] == 'O') {
      board[i][j] = 'V';
      DepthFirstSearch(i - 1, j, board);
      DepthFirstSearch(i + 1, j, board);
      DepthFirstSearch(i, j - 1, board);
      DepthFirstSearch(i, j + 1, board);
    }
  }

  void solve(std::vector<std::vector<char>>& board) {
    r = board.size();
    if (r == 0) return;
    c = board[0].size();
    if (c == 0) return;

    for (int i = 0; i < r; i++) {
      DepthFirstSearch(i, 0, board);
      DepthFirstSearch(i, c - 1, board);
    }

    for (int j = 1; j < c - 1; j++) {
      DepthFirstSearch(0, j, board);
      DepthFirstSearch(r - 1, j, board);
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == 'V') board[i][j] = 'O';
      }
    }
  }

 private:
  int r{0}, c{0};
};

}  // namespace surrounded_regions

#endif  // CPP_0130_SURROUNDED_REGIONS_HPP
