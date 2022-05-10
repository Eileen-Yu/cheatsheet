// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> rslt;
    getSum(ans, rslt, k, n, 1);
    return ans;
  }

  void getSum(vector<vector<int>> &ans, vector<int> &rslt, int k, int n,
              int num) {
    if (k == 0) {
      if (n == 0)
        ans.push_back(rslt);
      return;
    }
    if (num > 9)
      return;

    rslt.push_back(num);
    getSum(ans, rslt, k - 1, n - num, num + 1);
    rslt.pop_back(); // the last element in the array is not qualified
    getSum(ans, rslt, k, n, num + 1); // try next one
  }
};
