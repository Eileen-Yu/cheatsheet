// https://leetcode.com/problems/longest-increasing-subsequence
// 1. tabulation
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    // dp[i] represents the length of the longest increasing subsequence till
    // the i-th element
    vector<int> dp(n, 1);
    int ans = 1;

    // loop from the second element
    for (int i = 1; i < n; i++) {
      // compare it with the previous elements
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          // pick the longest till now
          dp[i] = max(dp[i], dp[j] + 1);
          // record the longest length during the process
          ans = max(ans, dp[i]);
        }
      }
    }

    return ans;
  }
};
