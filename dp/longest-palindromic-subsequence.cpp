// https://leetcode.com/problems/longest-palindromic-subsequence/
// dp
class Solution {
public:
  // initialize a dp to record if string between idx i and j is a palindrome
  vector<vector<int>> dp;

  int longestPalindromeSubseq(string s) {
    int n = s.length();
    // init the dp table
    dp.resize(n + 1, vector<int>(n + 1, -1));
    return helper(0, n - 1, s);
  }

  int helper(int i, int j, string &s) {
    if (i > j)
      return 0;

    // if point to the same element
    if (i == j)
      return 1;

    // if already filled
    if (dp[i][j] != -1)
      return dp[i][j];

    // these two should be included in the fianl palindrome
    if (s[i] == s[j])
      dp[i][j] = 2 + helper(i + 1, j - 1, s);
    else // try to find new palindrome, either cut left / right
      dp[i][j] = max(helper(i + 1, j, s), helper(i, j - 1, s));

    // each time only return ans of this level
    return dp[i][j];
  }
};
