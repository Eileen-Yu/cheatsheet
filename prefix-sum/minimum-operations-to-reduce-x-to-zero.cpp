// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero
// sum of consecutive leftmost / rightmost --> use prefix + suffix
// another way to solve this problem is to use the sliding window
// (-->to find the longest subarray of a certain sum)
class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size();
    // prefix[i] records the sum when there are i elements from the start
    vector<int> prefix;
    // base of the prefix sum
    prefix.push_back(0);
    // calculate the prefix sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      prefix.push_back(sum);
    }

    // special cases:
    // 1. whole sum still < x
    if (sum < x)
      return -1;
    // 2. whole sum exactly = x
    if (sum == x)
      return n;

    // sunfix sum, map for easier search
    // {suffix sum from the i-th element, idx}
    unordered_map<int, int> suffix;

    // calculate the suffix
    for (int i = 0; i < n; i++) {
      suffix[sum] = i;
      sum -= nums[i];
    }
    // the last base case, similar to prefix[0]
    suffix[0] = n;

    // main logic
    int ans = INT_MAX;
    // loop each prefix sum
    for (int i = 0; i <= n; i++) {
      if (prefix[i] > x)
        break;

      // needed suffix
      int target = x - prefix[i];
      // if there is the corresponding suffix, update the ans if necessary
      if (suffix.find(target) != suffix.end())
        ans = min(ans, i + n - suffix[target]);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
