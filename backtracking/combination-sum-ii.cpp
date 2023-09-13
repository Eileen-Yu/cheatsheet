// https://leetcode.com/problems/combination-sum-ii/description/
// avoid duplication: avoid same elements on the certain position
class Solution {
public:
  void backtracking(vector<int> tmp, vector<vector<int>> &ans,
                    vector<int> &candidates, int remain, int idx) {
    // when to return:
    // 1. remain too small that no candidate can fill it
    // 2. remain too big and we already used up all candidates
    if (candidates[0] > remain || idx >= candidates.size()) {
      if (remain == 0)
        ans.push_back(tmp);
      return;
    }

    // try each candidate from small to big
    for (int i = idx; i < candidates.size(); i++) {
      // skip the same elements on this certain position to avoid duplications
      if (i > idx && candidates[i] == candidates[i - 1])
        continue;

      // always keep remain >= 0
      if (candidates[i] <= remain) {
        // 1. take this candidate
        tmp.push_back(candidates[i]);
        backtracking(tmp, ans, candidates, remain - candidates[i], i + 1);

        // 2. not take this candidate, it would try the next candidate in the
        // next loop automatically
        tmp.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    // 1 possible combination
    vector<int> tmp;
    vector<vector<int>> ans;

    backtracking(tmp, ans, candidates, target, 0);

    return ans;
  }
};
