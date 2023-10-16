// https://leetcode.com/problems/permutations-ii
//  1. use set to avoid duplication
//  need to convert set to vector at the end
class Solution {
public:
  void backtracking(vector<int> &nums, set<vector<int>> &ans,
                    vector<bool> &visited, vector<int> tmp) {
    // when to return
    if (tmp.size() == nums.size()) {
      ans.insert(tmp);
      return;
    }

    // try to fill in this position
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i])
        continue;

      // else if the current num have not been used
      // 1. pick this num
      tmp.push_back(nums[i]);
      visited[i] = true;
      backtracking(nums, ans, visited, tmp);

      // 2. not pick this num, a new num would be automatically picked in the
      // next loop
      tmp.pop_back();
      visited[i] = false;
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    set<vector<int>> ans;
    vector<bool> visited(nums.size(), false);
    vector<int> tmp;

    backtracking(nums, ans, visited, tmp);

    // convert the set to vector
    vector<vector<int>> finalAns(ans.begin(), ans.end());

    return finalAns;
  }
};
