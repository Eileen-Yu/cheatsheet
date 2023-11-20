// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// converts to the sliding window problem: find the longest subarray of
// identical elements after at most k operations (only increment)
class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    // sort from small to big
    // this ensures each time we try to reach a greater target
    // by adjust all the elements < that target
    sort(nums.begin(), nums.end());

    // left side of the window
    int i = 0;
    // sum of all elements within the window
    long sum = 0;
    int ans = INT_MIN;

    // move right side of the window
    // each time want to make all the nums within the window = nums[j]
    // this knows maximum possible frequency of this num[j]
    for (int j = 0; j < nums.size(); j++) {
      sum += nums[j];

      // shorten the window if necessary
      // the formula means k cannot make each num within the window identical
      while (sum + k < (long)nums[j] * (j - i + 1)) {
        sum -= nums[i];
        i++;
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
