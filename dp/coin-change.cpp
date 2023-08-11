// https://leetcode.com/problems/coin-change/
// 1. dp, tabulation
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // dp[i] represents the minimum number of coins to make up the amount i
    // init to an impossible ans: INT_MAX
    vector<int> dp(amount + 1, INT_MAX);
    // base case
    dp[0] = 0;

    // if we pick this coin
    for (auto coin : coins) {
      // only can make up the amount  >= coin
      for (int i = coin; i <= amount; i++) {
        // only when i - coin has been filled up
        if (dp[i - coin] != INT_MAX)
          dp[i] = min(dp[i], 1 + dp[i - coin]);
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

// 2. backtracking, TLE in some cases
class Solution {
public:
  int ans = INT_MAX;
  void recursion(vector<int> &coins, int amount, int tmp) {
    // when to return
    if (amount == 0) {
      // update the ans if necessary
      ans = min(ans, tmp);
    }

    // else if amount != 0
    for (int i = 0; i < coins.size(); i++) {
      if (coins[i] > amount)
        break;

      // 1. if pick this coins[i]
      recursion(coins, amount - coins[i], tmp + 1);
      // 2. if not pick this coins[i], then automatically into the next loop
    }
  }

  int coinChange(vector<int> &coins, int amount) {
    recursion(coins, amount, 0);
    if (ans == INT_MAX)
      ans = -1;
    return ans;
  }
};
