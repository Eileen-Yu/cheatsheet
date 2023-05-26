// https://leetcode.com/problems/stone-game-ii/description/
// dp + math
class Solution {
public:
  // dp[i][j] represents the maximum diff when starting at idx i with M = j
  // i's range: 0 ~ 100
  // j's range: 1~202(1 <= X <= 2M)
  vector<vector<int>> dp;

  int stoneGameII(vector<int> &piles) {
    int n = piles.size();
    dp.resize(101, vector<int>(202));
    // Alice would get most stones --> maximize the diff of A-B
    // max stones get by Alice: (A+B)(stable) + (A-B)(max) / 2, namely (sum +
    // diff)/2
    int sum = accumulate(piles.begin(), piles.end(), 0);

    // start at idx 0, M = 1
    int diff = helper(piles, 0, 1);

    return (sum + diff) / 2;
  }

  int helper(vector<int> &piles, int i, int M) {
    // when to return
    if (i >= piles.size())
      return 0;

    // memoization
    if (dp[i][M] != 0)
      return dp[i][M];

    // total stones got by Alice so far
    int sum = 0;
    // max diff of A-B
    int ans = INT_MIN;

    // try each step, 1 <= x <= 2M
    // since the first is pile[0], so the range is [0,2M-1]
    for (int j = 0; j < 2 * M; j++) {
      // here we come to stand at the end of Alice's idx: i+j
      if (i + j < piles.size())
        sum += piles[i + j];
      // recursion, the begin of Bob's idx: i+j+1
      ans = max(ans, sum - helper(piles, i + j + 1, max(M, j + 1)));
    }

    return dp[i][M] = ans;
  }
};
