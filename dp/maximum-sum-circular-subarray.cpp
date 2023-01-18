// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
//
class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int sum = nums[0];
    int maxTillHere = nums[0];
    int maxOfAll = nums[0];
    int minTillHere = nums[0];
    int minOfAll = nums[0];

    // start from the second element
    for (int i = 1; i < nums.size(); i++) {
      // Kadane's algorithm
      // if to drop the previous subarray and start from this one
      maxTillHere = max(nums[i], maxTillHere + nums[i]);
      // global maximum value
      maxOfAll = max(maxOfAll, maxTillHere);
      minTillHere = min(nums[i], minTillHere + nums[i]);
      // global minimum value, for circular subarray
      minOfAll = min(minOfAll, minTillHere);
      sum += nums[i];
    }

    // if all elements are < 0
    if (maxOfAll < 0)
      return maxOfAll;
    // if all element are > 0 / positive and negative numbers combined
    // sum - minOfAll exists when subarray is circular
    return max(maxOfAll, sum - minOfAll);
  }
};
