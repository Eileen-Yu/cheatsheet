// https://leetcode.com/problems/interleaving-string/description/
// dp + tabulation: fill in base case + row & column (starting ones) + other
// cells
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.length(), n = s2.length();

    // special case
    if (s3.length() != m + n)
      return false;

    // dp[i] represents if s1[:i], s2[:j] can form a valid string s3[:i+j], i &
    // j are length
    // i, j's range: [0,m], [0,n], including the base case
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    // base case: 2 empty strings s1, s2 can form an empty string s3
    dp[0][0] = true;

    // fill up the row & column
    // 1. if s3 = s1, j = 0
    for (int i = 1; i <= m; i++) {
      // dp[i][0] is valid when current char(s[i-1]) are the same && the
      // previous check are true,
      // since i is len, so i-1 is the actual idx
      dp[i][0] = s3[i - 1] == s1[i - 1] && dp[i - 1][0] == true;
    }
    // 2. if s3 = s2, i = 0
    for (int j = 1; j <= n; j++) {
      dp[0][j] = s3[j - 1] == s2[j - 1] && dp[0][j - 1] == true;
    }

    // fill up the other cells
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // dp[i][j] is valid only if:
        // 1. current element in s3 = the one in s1 && dp[i-1][j] is valid
        // 2. current element in s3 = the one in s2 && dp[i][j-1] is valid
        dp[i][j] = (s3[i + j - 1] == s1[i - 1] && dp[i - 1][j]) ||
                   (s3[i + j - 1] == s2[j - 1] && dp[i][j - 1]);
      }
    }

    return dp[m][n];
  }
};
