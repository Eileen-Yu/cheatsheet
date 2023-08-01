// https://leetcode.com/problems/combinations/description/
// 1. recursion, use k-- to control the recursion depth & update corresponding
// idx to update the digit in each recursion level
class Solution {
public:
  void recursion(int n, int k, int start, vector<int> &tmp,
                 vector<vector<int>> &ans) {
    // when to return: already get one possible combination
    if (k == 0) {
      ans.push_back(tmp);
      return;
    }

    // range of each layer [start, n]
    for (int i = start; i <= n; i++) {
      // update current position in this recursion level
      tmp[tmp.size() - k] = i;
      recursion(n, k - 1, i + 1, tmp, ans);
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    // one possible combination
    vector<int> tmp(k);

    // start from 1
    recursion(n, k, 1, tmp, ans);
    return ans;
  }
};
