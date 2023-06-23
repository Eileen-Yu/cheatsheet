// https://leetcode.com/problems/longest-arithmetic-subsequence/description/
// dp: tabulation, bottom up
// similar to // https://leetcode.com/problems/uncrossed-lines/description/
class Solution {
public:
  // dp[i][j] represents the longest arithemetic subsequence we can get at the
  // i-th element when the dist of the subsequence is j
  vector<unordered_map<int, int>> dp;

  int longestArithSeqLength(vector<int> &nums) {
    int n = nums.size();
    // special cases
    if (n <= 2)
      return n;
    // init the dp, i's range: 0 ~ n-1
    dp.resize(n);

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int diff = nums[i] - nums[j];
        // if there already is a subsequence with the `diff`, length + 1
        // else, it's a new subsequence, initial length = 2
        dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
        // update the ans
        ans = max(ans, dp[i][diff]);
      }
    }

    return ans;
  }
};
