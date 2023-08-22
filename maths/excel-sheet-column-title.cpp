// https://leetcode.com/problems/excel-sheet-column-title/description/
// 1. very similar to carry in 10-based system.
// each time we got the remainder as the one in the least position
// and continue to the loop by n/10
// only difference is this one is 1-based, so each time need -1
class Solution {
public:
  string convertToTitle(int columnNumber) {
    string ans = "";

    while (columnNumber) {
      // because it's 1-based
      columnNumber--;
      // get the char of this position
      char c = 'A' + columnNumber % 26;
      // fill up from least to most
      ans = c + ans;
      columnNumber /= 26;
    }

    return ans;
  }
};
