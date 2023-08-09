// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
// binary search to try on each ans +
// sort & greedy to make local optimum --> global optimuim
class Solution {
public:
  // check if there is enough pairs with the difference <= diff
  bool canFormPair(vector<int> &nums, int p, int diff) {
    // record the number of valid pairs with the difference <= diff
    int count = 0;
    for (int i = 0; i < nums.size() - 1;) {
      if (nums[i + 1] - nums[i] <= diff) {
        count++;
        // skip the nums[i+1] as it's already used in a pair
        i += 2;
      } else
        i++; // else start to try on nums[i+1], nums[i+2]...
    }

    // as long as there's enough valid pairs
    return count >= p;
  }

  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // binary search
    // range is [0, max possible difference]
    int l = 0, r = nums[n - 1] - nums[0];
    int ans = 0;

    while (l <= r) {
      // try the ans
      int mid = l + (r - l) / 2;
      // we may continue to decrease the possible difference
      if (canFormPair(nums, p, mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1; // else the current trial is too small, need to increase it
    }

    return ans;
  }
};

// 2. dp + memoization(recursion), would MLE
class Solution {
public:
  int recursion(vector<int> &nums, int p, int i, vector<vector<int>> &dp) {
    // when to return
    // 1. if already found enough pairs
    if (p == 0)
      return 0;
    // 2. if i is out of range, since we need nums[i+1], so i <= n-1
    // return 1e9 to ensure it won't be selected in the final result
    if (i >= nums.size() - 1)
      return 1e9;

    // memoization
    if (dp[i][p] != -1)
      return dp[i][p];

    // 1. pick nums[i] and numd[i+1], continue to check on nums[i+2]...
    // 2. don't pick nums[i], continue to check oon nums[i+1]...
    return dp[i][p] = min(
               max(nums[i + 1] - nums[i], recursion(nums, p - 1, i + 2, dp)),
               recursion(nums, p, i + 1, dp));
  }

  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // dp[i][p] represents the minimum when the idx is i and we found p pairs
    vector<vector<int>> dp(n, vector<int>(p + 1, -1));
    return recursion(nums, p, 0, dp);
  }
};
