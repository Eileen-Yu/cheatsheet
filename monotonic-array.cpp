// https://leetcode.com/problems/monotonic-array/description
// 1. color algorithm: 0, 1, -1 to mark the status
class Solution {
public:
  bool isMonotonic(vector<int> &nums) {
    int n = nums.size();
    // special case
    if (n <= 2)
      return true;

    // 0 = unknown, 1 means monotone increasing, -1 means decreasing
    int flag = 0;

    // loop each item, don't need to care about a == b
    for (int i = 1; i < n; i++) {
      // decrease?
      if (nums[i] < nums[i - 1]) {
        // if unknown, mark it as decrease
        if (flag == 0)
          flag = -1;
        // if already marked as increase, return false
        else if (flag == 1)
          return false;
      } else if (nums[i] > nums[i - 1]) { // increase?
        // if known, mark it as increase
        if (flag == 0)
          flag = 1;
        // if already marked as decrease, return false
        else if (flag == -1)
          return false;
      }
    }

    return true;
  }
};
