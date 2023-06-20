// https://leetcode.com/problems/k-radius-subarray-averages/
//
// 2. plain version (would TLE for some cases)
class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();
    // init the ans
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
      int l = i - k, r = i + k;
      if (l < 0 || r >= n)
        continue;

      // else
      // accumulate(iterator1, iterator2, start) pick [l, r), so +1
      ans[i] =
          accumulate(nums.begin() + l, nums.begin() + r + 1, 0) / (r - l + 1);
    }

    return ans;
  }
};
