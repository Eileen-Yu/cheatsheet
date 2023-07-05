// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
// sliding window: control the content in the window:
// at most only 1 0's
class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    // left side of the sliding window
    int l = 0;
    // count of 0's
    int zeros = 0;
    int ans = INT_MIN;
    // move the right side of the window
    for (int r = 0; r < n; r++) {
      if (nums[r] == 0)
        zeros++;
      // check the number of 0's in the window
      // at most one 0 can appear in our window
      // so the left side need to move to maintain only one 0 in the window
      while (zeros > 1) {
        if (nums[l] == 0)
          zeros--;
        l++;
      }

      // update the ans
      ans = max(ans, r - l + 1 - zeros);
    }

    // special case: [1,1,1]
    // must delete 1 element though there's no 0's
    if (ans == n)
      ans -= 1;
    return ans;
  }
};
