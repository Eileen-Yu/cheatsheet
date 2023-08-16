// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
// 1. 1D dp + tabulation
class Solution {
public:
  // check if the subarray is valid
  bool isValid(vector<int> &nums, int start, int end) {
    int n = end - start + 1;
    // the size can only be 2 / 3
    if (n != 2 && n != 3)
      return false;

    // 1. subarray consists of exactly 2 equal elements
    if (n == 2 && nums[start] == nums[end])
      return true;
    // 2. subarray consists of 3 elements
    if (n == 3) {
      // 2.1 exactly the same
      if (nums[start] == nums[start + 1] && nums[start + 1] == nums[end])
        return true;
      // 2.2 consecutive increasing
      if (nums[start] + 1 == nums[start + 1] &&
          nums[start + 1] == nums[end] - 1)
        return true;
    }

    return false;
  }

  bool validPartition(vector<int> &nums) {
    int n = nums.size();
    // dp[i] represents if the subarray [0,i] is valid
    vector<bool> dp(n, false);

    for (int i = 1; i < n; i++) {
      // 1. [0, i-2] & [i-1, i] is valid
      // if i < 2 (i = 1) then mark[0,1] = true
      if (isValid(nums, i - 1, i))
        dp[i] = i >= 2 ? dp[i - 2] : true;

      // 2. only when the above check fail, continue to check if [0, i-3] &
      // [i-2, i] is valid otherwise the above rslt would be overwritten if 2 <=
      // i < 3 (i = 2) then mark[0,2] = true
      if (!dp[i] && i >= 2 && isValid(nums, i - 2, i))
        dp[i] = i >= 3 ? dp[i - 3] : true;
    }

    return dp[n - 1];
  }
};

// 2. 2D dp + tabulation, would MLE
class Solution {
public:
  // check if the subarray is valid
  bool isValid(vector<int> &nums) {
    int n = nums.size();
    // the size can only be 2 / 3
    if (n != 2 && n != 3)
      return false;

    // 1. subarray consists of exactly 2 equal elements
    if (n == 2 && nums[0] == nums[1])
      return true;
    // 2. subarray consists of 3 elements
    if (n == 3) {
      // 2.1 exactly the same
      if (nums[0] == nums[1] && nums[1] == nums[2])
        return true;
      // 2.2 consecutive increasing
      for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] != 1)
          return false;
      }
      return true;
    }

    return false;
  }

  bool validPartition(vector<int> &nums) {
    int n = nums.size();
    // dp[i][j] represents if the subarray [i,j] is valid
    // 0 = invalid, 1 = valid
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // the left idx range: [0, n-1], as the subarray minimum length can be 2
    for (int i = 0; i < n - 1; i++) {
      // the right idx range: [i+1, min(i+2, n-1)], as the maximum length can be
      // 3 the min() is for avoiding out of range
      for (int j = i + 1; j <= min(n - 1, i + 2); j++) {
        // subarray from [i, j]
        vector<int> sub(nums.begin() + i, nums.begin() + j + 1);
        if (isValid(sub)) {
          // mark this subarray as valid
          dp[i][j] = 1;
          // check if the previous subarray are also valid
          if (i >= 1 && dp[0][i - 1] == 1)
            dp[0][j] = 1;
        }
      }
    }

    return dp[0][n - 1];
  }
};
