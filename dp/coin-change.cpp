// https://leetcode.com/problems/coin-change/
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
