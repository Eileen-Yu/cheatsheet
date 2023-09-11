// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
  void backtracking(vector<vector<int>> &ans, vector<int> tmp,
                    vector<int> &candidates, int remain, int idx) {
    // when to return: no possible candidate can be picked any more
    if (remain < candidates[0]) {
      if (remain == 0)
        ans.push_back(tmp);
      return;
    }

    // try each candidate from the last idx, to avoid duplications
    for (int i = idx; i < candidates.size(); i++) {
      if (candidates[i] <= remain) {
        // 1. if take this candidate
        tmp.push_back(candidates[i]);
        backtracking(ans, tmp, candidates, remain - candidates[i], i);

        // 2. if not take this candidate, automatically try the next candidate
        // in the next loop
        tmp.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    // need to sort candidates from small to big
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    // 1 possible combination
    vector<int> tmp;

    backtracking(ans, tmp, candidates, target, 0);
    return ans;
  }
};
