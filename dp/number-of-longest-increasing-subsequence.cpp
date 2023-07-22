// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
// dp: tabulation (loop), bottom-up
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    // dp[i] represents the length of the longest increasing subsequence(LIS)
    // ending at index i
    vector<int> dp(n, 1);
    // count[i] represents the number of LIS of length dp[i] ending at index i
    vector<int> count(n, 1);
    // record the longest length
    int maxLength = 1;

    for (int i = 1; i < n; i++) {
      // to check each combination includes the current (i-th) element
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          // 1. if this combination have a longer length
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            // update the count as this has been updated with a new combination
            count[i] = count[j];
          } else if (dp[i] == dp[j] + 1) { // 2. if it's just a different
                                           // combination with the same length
            // update the multiple ways to form the LIS with the same length
            count[i] += count[j];
          }
        }
      }

      // update the max length of LIS
      maxLength = max(maxLength, dp[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] == maxLength)
        ans += count[i];
    }

    return ans;
  }
};
