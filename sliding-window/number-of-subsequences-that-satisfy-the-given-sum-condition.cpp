// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
// sliding window (fix min , pick max) + maths
class Solution {
public:
  int numSubseq(vector<int> &nums, int target) {
    int M = 1000000007;
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    // sliding window
    // every time we fix the min, and have a range of max to be picked
    int l = 0, r = n - 1;

    // have a pre-calculated power table to avoid overflow
    // 0--1
    // 1--2
    // 2--4...
    vector<int> powTable(n);
    powTable[0] = 1;
    for (int i = 1; i < n; i++) {
      powTable[i] = (powTable[i - 1] * 2) % M;
    }

    while (l <= r) {
      if (nums[l] + nums[r] <= target) {
        // length of range: r-l+1
        // the min must be pick
        // other elements (total number r-l) can be picked / not pick
        ans += powTable[r - l];
        ans %= M;
        // try bigger min
        l++;
      } else
        r--; // try smaller max
    }

    return ans;
  }
};
