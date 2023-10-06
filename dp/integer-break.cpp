// https://leetcode.com/problems/integer-break/description
// tabulation: fill up dp[i] represents the maximum product when we try to split
// i into >= 2 parts
class Solution {
public:
  int integerBreak(int n) {
    // dp[i] represents the maximum product when we try to break i
    // though i's range: [1, n], since it's a vector, still needs to be 0-based
    // so init to n+1
    vector<int> dp(n + 1);
    // base case
    dp[1] = 1;

    // loop from 2 to n
    for (int i = 2; i <= n; i++) {
      // split 1 part from i
      for (int j = 1; j < i; j++) {
        // dp[i] is the biggest one among:
        // 1. recorded dp[i]
        // 2. if split to 2 parts, --> (i-j) * j
        // we need this because dp[i] doesn't include itself, e.g dp[3] would
        // only be 2(2*1)
        // 3. if split to multiple parts, namely continue to split i-j, -->
        // dp[i-j] * j we don't explicity compare with dp[j]*(i-j) because j is
        // ranged [1, i-1], already covered
        dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});
      }
    }

    return dp[n];
  }
};
