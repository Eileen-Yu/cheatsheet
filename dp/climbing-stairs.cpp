// https://leetcode.com/problems/climbing-stairs
// climb stairs --> simple tabulation
class Solution {
public:
  int climbStairs(int n) {
    // dp[i] represents # of ways to reach the i-th stair
    // i's range: 0 ~ n
    vector<int> dp(n + 1, 0);
    // base case:
    dp[0] = 1;
    dp[1] = 1;

    // loop each stair
    for (int i = 2; i <= n; i++) {
      // # of ways to reach this stair = # to each 1 step before + # to reach 2
      // steps before
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};
