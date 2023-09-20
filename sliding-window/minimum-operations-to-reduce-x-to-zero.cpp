// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/
// min to cut from leftmost / rightmost == find the longest subarray
// use sliding window to get the subarrays who have the same sum
class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size();

    // the total sum of the whole array
    int sum = 0;
    for (auto i : nums)
      sum += i;

    // the sum of the consecutive subarray we want to find
    int target = sum - x;

    // special case: the whole sum < x, not possible to reduce x to 0
    if (target < 0)
      return -1;

    // else, we try to find the longest subarray
    // left end of the sliding window
    int l = 0;
    // tmp sum of the subarray within the window
    int tmp = 0;
    // record the max length of the possible subarrays
    int len = -1;

    // slide the window
    for (int r = 0; r < n; r++) {
      tmp += nums[r];

      // if exceed the target, shorten the window
      while (tmp > target) {
        tmp -= nums[l];
        l++;
      }

      // if we find one of the subarray, update the max length if necessary
      if (tmp == target)
        len = max(len, r - l + 1);
    }

    // if len always = -1, means not possible
    return len == -1 ? -1 : n - len;
  }
};
