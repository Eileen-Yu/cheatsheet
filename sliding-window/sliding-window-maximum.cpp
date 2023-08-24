// https://leetcode.com/problems/sliding-window-maximum/
// 1. plain version: apply the sliding window, use built-in max_element to find
// the maximum element in the subarray
// would TLE in some cases
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();

    vector<int> ans;

    // left side of the window
    int l = 0;
    // sliding the right side of the window
    for (int r = l + k - 1; r < n; r++) {
      // if exceeds the window, shorten it
      while (r - l + 1 > k)
        l++;

      // get the maximum element in this subarray
      int maxItem = *max_element(nums.begin() + l, nums.begin() + r + 1);
      ans.push_back(maxItem);
    }

    return ans;
  }
};
