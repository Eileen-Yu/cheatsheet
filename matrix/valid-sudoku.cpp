// https://leetcode.com/problems/valid-sudoku/description/
//
// use hashmap + set to represent whether a element is duplicated
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      // because it's a 9x9 board
      // use set to check if there is duplication
      set<char> row[9];
      set<char> col[9];
      set<char> box[9];

      for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          char ch = board[i][j];
          if (ch == '.') continue;

          // check the row
          if (row[i].count(ch) == 1) return false;
          else row[i].insert(ch);

          // check the col
          if (col[j].count(ch) == 1) return false;
          else col[j].insert(ch);

          // check the box
          // 1. calculate the box number
          int boxNum = (i/3) * 3 + j/3;
          // 2. check if there is duplication
          if (box[boxNum].count(ch) == 1) return false;
          else box[boxNum].insert(ch);
        }
      }

      return true;
    }
};
