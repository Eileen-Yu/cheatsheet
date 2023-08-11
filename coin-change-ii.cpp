// https://leetcode.com/problems/coin-change-ii/
// 1. back tracking + set to avoid duplications
// would TLE in some cases:
class Solution {
public:
  set<vector<int>> ans;

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
