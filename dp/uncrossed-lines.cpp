// https://leetcode.com/problems/uncrossed-lines/description/
// DP + memoization (record)
class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    // dp[i][j] represents the number of uncrosses lines between
    // first i elements of nums1 and first j elements of nums2
    // so i's range: 0 ~ m, j's range: 0~n
    int dp[m + 1][n + 1];
    // init the dp
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // if these two match, then both nums1[i] and nums2[j] should be
        // included; if not match, then we check if nums2[j] can be used to
        // match with the previous elements in nums1 based on this to decide if
        // we take nums2[j]
        dp[i][j] = nums1[i - 1] == nums2[j - 1]
                       ? dp[i - 1][j - 1] + 1
                       : max(dp[i][j - 1], dp[i - 1][j]);
      }
    }

    return dp[m][n];
  }
};

// 2. backtracking, would TLE in some cases
class Solution {
public:
  // find the next pair after pair{idx1. idx2}
  pair<int, int> helper(int idx1, int idx2, vector<int> &nums1,
                        vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    for (int i = idx1 + 1; i < m; i++) {
      for (int j = idx2 + 1; j < n; j++) {
        if (nums1[i] == nums2[j])
          return {i, j};
      }
    }
    // if no matching pair
    return {-1, -1};
  }

  // backtracking: take / not take
  void recursion(int &tmp, int &ans, int idx1, int idx2, vector<int> &nums1,
                 vector<int> &nums2) {
    auto [i, j] = helper(idx1, idx2, nums1, nums2);
    // if no matching pair
    if (i == -1 && j == -1)
      return;

    // if there is matching pair
    // 1. we take this pair
    tmp += 1;
    ans = max(ans, tmp);
    recursion(tmp, ans, i, j, nums1, nums2);

    // 2. we don't take this pair
    tmp -= 1;
    // we would skip nums1[i] and start from nums2[idx2], this can avoid take
    // {i,j}
    recursion(tmp, ans, i, idx2, nums1, nums2);
  }

  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    int ans = 0;
    int tmp = 0;

    recursion(tmp, ans, -1, -1, nums1, nums2);

    return ans;
  }
};
