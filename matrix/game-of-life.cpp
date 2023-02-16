// https://leetcode.com/problems/game-of-life/
//
class Solution {
public:
  int rslt(int it, int c) {
    int ans = it;

    if (it == 1) {
      if (c == 2 || c == 3)
        ans = 1;
      else if (c < 2 || c > 3)
        ans = 0;
    } else if (it == 0) {
      if (c == 3)
        ans = 1;
    }
    return ans;
  }

  void gameOfLife(vector<vector<int>> &board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    vector<vector<int>> nb(
        m + 2, vector<int>(n + 2, 2)); // deal with corner, all initialize to 2

    for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        nb[i][j] = board[i - 1][j - 1];
      }
    }

    int c = 0;
    for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (nb[i][j - 1] == 1)
          c += 1;

        if (nb[i][j + 1] == 1)
          c += 1;

        if (nb[i + 1][j] == 1)
          c += 1;

        if (nb[i + 1][j - 1] == 1)
          c += 1;

        if (nb[i + 1][j + 1] == 1)
          c += 1;

        if (nb[i - 1][j] == 1)
          c += 1;

        if (nb[i - 1][j - 1] == 1)
          c += 1;

        if (nb[i - 1][j + 1] == 1)
          c += 1;

        ans[i - 1][j - 1] = rslt(nb[i][j], c);
        c = 0;
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        board[i][j] = ans[i][j];
      }
    }
  }
};
