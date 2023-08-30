// https://leetcode.com/problems/frog-jump/description/
// hard dp: tabulation
class Solution {
public:
  bool canCross(vector<int> &stones) {
    int n = stones.size();
    // dp[i][j] represents if can reach stone[i] with a jump of length j
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

    // base case as stated in the condition
    dp[0][1] = true;

    // loop each stone, and the first has already been marked
    for (int i = 1; i < n; i++) {
      // loop all previous stones
      for (int j = 0; j < i; j++) {
        // the distance between the current and provious stone
        int jump = stones[i] - stones[j];

        // the maximum jump you can make is proportional to the index j
        // because you can jump j, j + 1, or j - 1 units
        // This checks if the distance jump to go from stone j to stone i is
        // plausible based on the number of stones we've encountered.
        if (jump <= j + 1) {
          // dp[i][jump] is set to true if it's possible to make this jump
          // (jump) to reach the i-th stone from any earlier stone (j)
          // Specifically, it checks whether a jump of jump-1, jump, or jump+1
          // could have been made to reach the j-th stone
          dp[i][jump] = dp[j][jump - 1] || dp[j][jump] || dp[j][jump + 1];

          // if we already reached the destination, and it's true
          if (i == n - 1 && dp[i][jump] == true)
            return true;
        }
      }
    }

    return false;
  }
};
