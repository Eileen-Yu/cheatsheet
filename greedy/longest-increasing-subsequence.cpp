// https://leetcode.com/problems/longest-increasing-subsequence
// 1. tabulation
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    // dp[i] represents the length of the longest increasing subsequence till
    // the i-th element
    vector<int> dp(n, 1);
    int ans = 1;

    // loop from the second element
    for (int i = 1; i < n; i++) {
      // compare it with the previous elements
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          // pick the longest till now
          dp[i] = max(dp[i], dp[j] + 1);
          // record the longest length during the process
          ans = max(ans, dp[i]);
        }
      }
    }

    return ans;
  }
};

// 2. greedy + binary search
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    // tmp array to record the current optimized longest increasing subsequence
    vector<int> tmp;

    // loop each item in nums
    for (auto i : nums) {
      // if tmp is empty OR current item > the biggest item in tmp, directly add
      // it to tmp
      if (tmp.empty() || i > tmp.back())
        tmp.push_back(i);

      else {
        // find the idx of the first element >= i in tmp
        // in this way we try to add more elements in the tmp without changing
        // the order here we use lower_bound, may replace it with binary search
        auto it = lower_bound(tmp.begin(), tmp.end(), i);
        // replace the element with i
        *it = i;
      }
    }

    return tmp.size();
  }
};
