// https://leetcode.com/problems/coin-change-ii/
// 1. dp: tabulation
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    // dp[i] represents the number of combination to get the total amount = i
    // i's range: [0, amount], 0 is the basis
    vector<int> dp(amount + 1);
    // fill in the base case
    // e.g, for [1,2,5] amount = 5
    // if the amount is 0 then there is one possible combination:
    // 0*1 + 0*2 + 0*5
    dp[0] = 1;

    // if we pick each coin
    for (auto coin : coins) {
      // fill in the dp[amount], amount is within[coin, amount] since we pick
      // the coin
      for (int i = coin; i <= amount; i++) {
        // a new combination should be added
        // since this combination of the amount includes coin, we can ensure
        // it's a new combination
        dp[i] += dp[i - coin];
      }
    }

    return dp[amount];
  }
};

// 2. back tracking + set to avoid duplications
// would TLE in some cases:
class Solution {
public:
  set<vector<int>> ans;

  // backtracking
  void recursion(int amount, vector<int> &coins, vector<int> tmp) {
    // when to return
    if (amount == 0) {
      sort(tmp.begin(), tmp.end());
      ans.insert(tmp);
      return;
    }

    // else if amount != 0, continue to make up the combination
    for (int i = 0; i < coins.size(); i++) {
      if (amount < coins[i])
        break;
      // else
      // 1. if pick this coin
      tmp.push_back(coins[i]);
      recursion(amount - coins[i], coins, tmp);
      // 2. if not pick this coin, the loop would automatically pick the next
      // one
      tmp.pop_back();
    }
  }

  int change(int amount, vector<int> &coins) {
    sort(coins.begin(), coins.end());
    // special cases
    if (amount == 0)
      return 1;
    if (amount < coins[0])
      return 0;

    vector<int> tmp;

    recursion(amount, coins, tmp);
    return ans.size();
  }
};
