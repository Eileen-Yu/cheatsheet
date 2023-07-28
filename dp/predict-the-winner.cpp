// https://leetcode.com/problems/predict-the-winner/description/
// 1. recursion
class Solution {
public:
  // return how much more score player A can get than player B
  int recursion(int i, int j, vector<int> &nums, bool turn) {
    // when to return
    if (i > j || i == nums.size() || j == -1)
      return 0;

    // if it's player A's turn, let A try to get maximum score
    if (turn == true) {
      // if pick the first element / last element
      return max(nums[i] + recursion(i + 1, j, nums, false),
                 nums[j] + recursion(i, j - 1, nums, false));
    } else { // if it's player B's turn, B also play optimally, so need to
             // return the minimum
      // if pick the first element / last element
      return min(-nums[i] + recursion(i + 1, j, nums, true),
                 -nums[j] + recursion(i, j - 1, nums, true));
    }
  }

  bool PredictTheWinner(vector<int> &nums) {
    int n = nums.size();

    int score = recursion(0, n - 1, nums, true);
    return score >= 0;
  }
};

// 2. dp: tabulation
// record the max difference of current player's socre - opponent's score
// don't need to care about the turn
class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    int n = nums.size();
    // dp[i][j] represents the maximum difference of the current player's score
    // minus the opponent's score that the current player can obtain when it's
    // his turn to pick a number from the subarray from i to j regardless of
    // whose turn it is
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // fill in the base case: if there is only 1 element, only 1 player can take
    // the score
    for (int i = 0; i < n; i++) {
      dp[i][i] = nums[i];
    }

    // try each lenghth of the subarray to fill in the dp table
    for (int len = 2; len <= n; len++) {
      // the starting idx (i)'s range is [0, n-len]
      for (int i = 0; i <= n - len; i++) {
        // the ending idx(j)'s range
        int j = i + len - 1;
        // either pick nums[i] / nums[j]
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }

    return dp[0][n - 1] >= 0;
  }
};
