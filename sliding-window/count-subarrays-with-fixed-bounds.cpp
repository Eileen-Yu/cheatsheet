// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
//
// sliding window + two pointers
class Solution {
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    // record the most recent idx outside the range [minK, maxK]
    int leftBound = -1;
    // idx of the last minK
    int lastMin = -1;
    // idx of the last maxK
    int lastMax = -1;
    long long ans = 0;

    for (int i = 0; i < nums.size(); i++) {
      // if falls into the range
      if (nums[i] >= minK && nums[i] <= maxK) {
        // update the lastMin / lastMax if necessary
        if (nums[i] == minK)
          lastMin = i;
        if (nums[i] == maxK)
          lastMax = i;
        // whether to add 0 or 1,
        // bacause the next of leftBound must be lastMin / lastMax
        // only when both lastMax && lastMin exists, should count
        ans += max(0, min(lastMin, lastMax) - leftBound);
      } else { // if falls outside the range
        leftBound = i;
        // reset the vars, untils find the next subarray
        lastMin = -1;
        lastMax = -1;
      }
    }

    return ans;
  }
};
