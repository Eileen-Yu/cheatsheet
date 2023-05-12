// https://leetcode.com/problems/longest-common-subsequence/description/
// dp, memoization
// very similar idea to
// https://leetcode.com/problems/uncrossed-lines/description/

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    // memoization, dp[i][j] represents the longest common subsequence for
    // text1[0,i) and text2[0,j) i's range: 0 ~ m, j's range : 0 ~ n
    int dp[m + 1][n + 1];
    // init the dp
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = text1[i - 1] == text2[j - 1]
                       ? dp[i - 1][j - 1] + 1
                       : max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[m][n];
  }
};
