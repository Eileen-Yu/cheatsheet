// https://leetcode.com/problems/unique-paths/description/
// 1. tabulation
class Solution {
public:
  int uniquePaths(int m, int n) {
    // dp[i][j] represents the number of unique path to reach this cell
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // base case
    dp[0][0] = 1;

    // fill in dp[i][j]
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // if there is a top cell
        if (j - 1 >= 0)
          dp[i][j] += dp[i][j - 1];
        // if there is a left cell
        if (i - 1 >= 0)
          dp[i][j] += dp[i - 1][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};
