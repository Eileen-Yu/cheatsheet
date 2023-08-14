// https://leetcode.com/problems/unique-paths/description/
// 1. tabulation, Time Complexity: O(m*n)
// Space Complexity: O(m*n)
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

// 2. memoization(recursion)
// Time Complexity: O(m*n), since ans for each cell would be stored
// if pure recursion without memoization: O(2^(m*n))

// Space Complexity: O((m-1) + (n-1)) + O(m*n)
// if pure recursion without memoization: O((m-1) + (n-1))
class Solution {
public:
  int recursion(int i, int j, vector<vector<int>> &dp) {
    // when to return
    // 1. base case
    if (i == 0 && j == 0)
      return dp[i][j] = 1;

    // 2. if out of boundary
    if (i < 0 || j < 0)
      return 0;

    // 3. if already filled up: memoization
    if (dp[i][j] != -1)
      return dp[i][j];

    // the ans of this cell = top + left
    return dp[i][j] = recursion(i - 1, j, dp) + recursion(i, j - 1, dp);
  }

  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return recursion(m - 1, n - 1, dp);
  }
};
