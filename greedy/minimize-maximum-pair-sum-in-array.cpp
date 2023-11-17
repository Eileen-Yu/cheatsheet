// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// 1. always try to pair the bigger num with the smaller one to minimize the sum
// of the pair
class Solution {
public:
  int minPairSum(vector<int> &nums) {
    // sort from small to big
    sort(nums.begin(), nums.end());

    int ans = INT_MIN;
    int n = nums.size();

    // loop half of the nums
    for (int i = 0; i < n / 2; i++) {
      // sum up the smallest and the biggest
      int tmp = nums[i] + nums[n - i - 1];
      ans = max(ans, tmp);
    }

    return ans;
  }
};
