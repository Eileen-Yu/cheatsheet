// https://leetcode.com/problems/stone-game/description/
// DP (tabulation) to fill in all
// main idea: try each distance, find the max diff, same as stone-game-ii

class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    // total turns
    int n = piles.size();
    // dp[i][j] represents the biggest number of stones sb can get more than
    // opponent picking piles in piles[i]~piles[j] i&j's range: 0 ~ n-1
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case
    for (int i = 0; i < n; i++)
      dp[i][i] = piles[i];

    // try each dist between [1,n)
    for (int dist = 1; dist < n; dist++) {
      // try each starting point between [i, n-d)
      for (int i = 0; i < n - dist; i++) {
        // 1. pick piles[i], dp[i][i+d] = piles[i] - dp[i+1][i+d];
        // OR 2. pick piles[i+d], dp[i][i+d] = piles[i+d] - dp[i][i+d-1]
        dp[i][i + dist] = max(piles[i] - dp[i + 1][i + dist],
                              piles[i + dist] - dp[i][i + dist - 1]);
      }
    }

    // Alice go first, between [0, n-1]
    // if the diff is positive, then Alice wins
    // otherwise bob wins
    return dp[0][n - 1] > 0;
  }
};
