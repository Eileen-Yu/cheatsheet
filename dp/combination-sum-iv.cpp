// https://leetcode.com/problems/combination-sum-iv/description/
// tabulation: loop the nums, dp[i] += dp[i-num]
class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    // dp[i] represents the number of combinations adding up to i
    // unsigned int to avoid overflow
    vector<unsigned int> dp(target + 1, 0);
    // base case, ensure dp[i] = 1 at least if i is in the nums
    dp[0] = 1;

    // loop from 1 ~ target
    for (int i = 1; i <= target; i++) {
      // if we take num this time, then dp[i] = dp[i-num] + dp[i]
      for (auto num : nums) {
        if (num <= i)
          dp[i] += dp[i - num];
      }
    }

    return dp[target];
  }
};
