// https://leetcode.com/problems/minimum-size-subarray-sum
// sliding window: once the sum of the elements within the window reached the
// requirement,
// 1. update the ans
// 2. shorten the window

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    // special case:
    if (accumulate(nums.begin(), nums.end(), 0) < target)
      return 0;

    // left side of the sliding window
    int l = 0;
    // sum of all the elements within the window range
    int sum = 0;
    int ans = INT_MAX;
    // expand the window
    for (int r = 0; r < n; r++) {
      sum += nums[r];
      // if the window reached the requirement
      while (sum >= target) {
        // 1. update the ans
        ans = min(ans, r - l + 1);
        // 2. shorten the window
        sum -= nums[l];
        l++;
      }
    }

    return ans;
  }
};
