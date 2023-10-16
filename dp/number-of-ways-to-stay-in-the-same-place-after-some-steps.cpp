// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
// hard tabulation: 2D dp to record the status after each action
class Solution {
public:
  int numWays(int steps, int arrLen) {
    int m = steps;
    // the maximum idx we can reach
    int n = min(steps / 2 + 1, arrLen);
    // dp[i][j] represents the number of ways to reach j-th position after take
    // i steps i's range: [0, m] j's range: [0, n)
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    // base case
    dp[0][0] = 1;

    int mod = 1000000007;

    // tabulation
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < n; j++) {
        // 1. if stay at the same position
        dp[i][j] = dp[i - 1][j];

        // 2. if move from left
        if (j > 0)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;

        // 3, if move from right
        if (j < n - 1)
          dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
      }
    }

    return dp[steps][0];
  }
};
