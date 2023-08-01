// https://leetcode.com/problems/non-decreasing-subsequences/description/

class Solution {
public:
  void recursion(vector<int> &nums, int idx, vector<int> &tmp,
                 set<vector<int>> &ans) {
    // when to return:
    // loop over the whole array
    if (idx >= nums.size()) {
      // if to put candidate array into ans:
      // it should contain at least 2 elements
      if (tmp.size() > 1) {
        ans.insert(tmp);
      }
      return;
    }

    // how to deal with current element
    if (tmp.empty() || nums[idx] >= tmp.back()) {
      // 1. take it, and check the next element by recursion
      tmp.push_back(nums[idx]);
      recursion(nums, idx + 1, tmp, ans);
      // 2. don't take it, directly check the next element
      tmp.pop_back();
    }
    recursion(nums, idx + 1, tmp, ans);
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    // unique, ordered array
    set<vector<int>> ans;
    // the candidate subarray
    vector<int> tmp;
    recursion(nums, 0, tmp, ans);
    // change set to vector
    return vector(ans.begin(), ans.end());
  }
};
