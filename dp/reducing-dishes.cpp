// https://leetcode.com/problems/reducing-dishes/description/
// dp: take / not take (backtracking?)

class Solution {
public:
  int recursion(int idx, int len, vector<int> &satisfaction, int time,
                vector<vector<int>> &dp) {
    // when to return: our of range
    if (idx == len)
      return 0;

    // already have the maximum k for this dish of this time point
    if (dp[idx][time] != -1)
      return dp[idx][time];

    // if we take this dish, need to perform satisfaction[i] * time +
    // recursion(idx+1, len, satisfaction, time+1, dp) if we don't take this
    // dish, need to perform recursion(idx+1, len, satisfaction, time, dp) we
    // pick the max one in these two situations everytime would return the
    // maximum k
    return dp[idx][time] =
               max(satisfaction[idx] * time +
                       recursion(idx + 1, len, satisfaction, time + 1, dp),
                   recursion(idx + 1, len, satisfaction, time, dp));
  }

  int maxSatisfaction(vector<int> &satisfaction) {
    int n = satisfaction.size();
    // dp[i][time]
    // record the maximum k of each dish taken on each time point
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    sort(satisfaction.begin(), satisfaction.end());

    return recursion(0, n, satisfaction, 1, dp);
  }
};
