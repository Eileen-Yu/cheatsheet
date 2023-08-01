// https://leetcode.com/problems/combinations/description/
// Time Complexity: O(k * C(n,k)): updating an element in the tmp vector, and
// then copying the tmp vector into the ans vector once we have a valid
// combination

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
      // in this way we can always update the correct position based on the idx
      // calculation
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

// 2. backtracking: pick / not pick, they are different recursion paths
class Solution {
public:
  void backtracking(int n, int k, int start, vector<int> &tmp,
                    vector<vector<int>> &ans) {
    // when to return: already get one possible combination
    if (tmp.size() == k) {
      ans.push_back(tmp);
      return;
    }

    // range of each layer [start, n]
    for (int i = start; i <= n; i++) {
      // 1. pick this i
      tmp.push_back(i);
      backtracking(n, k, i + 1, tmp, ans);
      // 2. not pick this i
      tmp.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> tmp;

    // start from 1
    backtracking(n, k, 1, tmp, ans);
    return ans;
  }
};
