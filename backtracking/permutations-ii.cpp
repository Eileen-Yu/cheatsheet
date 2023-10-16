// https://leetcode.com/problems/permutations-ii
// 1. use swap + copy to avoid duplication
class Solution {
public:
  void recursion(vector<int> nums, int idx, vector<vector<int>> &ans) {
    // when to return
    if (idx == nums.size()) {
      ans.push_back(nums);
      return;
    }

    // try to swap with itself / other elements with different value
    // here we don't use reference, but directly make a copy of nums
    // so it wouldn't affect other branches
    for (int i = idx; i < nums.size(); i++) {
      // skip the duplication
      if (i != idx && nums[i] == nums[idx])
        continue;

      // else
      swap(nums[i], nums[idx]);
      recursion(nums, idx + 1, ans);
      // don't neet to undo the swap, as it's a copy
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    // need to sort first to make duplications near each other
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    recursion(nums, 0, ans);

    return ans;
  }
};

//  2. use set to avoid duplication
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
