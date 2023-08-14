// https://leetcode.com/problems/unique-paths-ii/description/
// dp: tabulation (loop)

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // special case: if the first is blocked, then no way to go
    if (grid[0][0] == 1)
      return 0;

    // dp[i][j] represents the number of unique path to reach this cell
    // i's range: [0, m-1], j's range: [0, n-1]
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // init the base case
    dp[0][0] = 1;

    // tabulation
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // if this cell is obstacled, we cannot go through this,
        // the count would be 0 as inited
        if (grid[i][j] == 1)
          continue;
        // if there is a valid top cell
        if (i - 1 >= 0)
          dp[i][j] += dp[i - 1][j];
        // if there is a valid left cell
        if (j - 1 >= 0)
          dp[i][j] += dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};
