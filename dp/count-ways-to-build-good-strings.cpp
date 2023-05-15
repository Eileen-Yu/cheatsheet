// https://leetcode.com/problems/count-ways-to-build-good-strings/description/
//
// 1. recursion + memoization
class Solution {
public:
  int mod = 1e9 + 7;
  long long recursion(long long low, long long high, long long len, int zero,
                      int one, vector<long long> &dp) {
    // when to return
    if (len > high)
      return 0;

    // advantage of memoization: record, avoid duplicated calculation
    if (dp[len] != -1)
      return dp[len];

    long long ans = 0;

    // if current case meet the requirement, ans +1
    if (len >= low && len <= high)
      ans += 1;

    // we will do the recursion anyway
    // dp[len] = dp[len + zero] + dp[len + one]
    ans = (ans % mod + recursion(low, high, len + zero, zero, one, dp) % mod) %
          mod;
    ans = (ans % mod + recursion(low, high, len + one, zero, one, dp) % mod) %
          mod;

    return dp[len] = ans;
  }

  int countGoodStrings(int low, int high, int zero, int one) {
    // dp[i] represents the maximum good string we can have when the string
    // length is i
    vector<long long> dp(high + 1, -1);

    return recursion(low, high, 0, zero, one, dp);
  }
};
