// https://leetcode.com/problems/uncrossed-lines/description/
// DP + memoization (record)
class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    // dp[i][j] represents the number of uncrosses lines between
    // first i elements of nums1 and first j elements of nums2
    // so i's range: 0 ~ m, j's range: 0~n
    int dp[m + 1][n + 1];
    // init the dp
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // if these two match, then both nums1[i] and nums2[j] should be
        // included; if not match, then we check if nums2[j] can be used to
        // match with the previous elements in nums1 based on this to decide if
        // we take nums2[j]
        dp[i][j] = nums1[i - 1] == nums2[j - 1]
                       ? dp[i - 1][j - 1] + 1
                       : max(dp[i][j - 1], dp[i - 1][j]);
      }
    }

    return dp[m][n];
  }
};
