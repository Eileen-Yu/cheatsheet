// https://leetcode.com/problems/subsets/description/
// pick / not pick the current element, each time 2 branches
// simialr to: https://leetcode.com/problems/generate-parentheses/description/
// use set to avoid duplications
class Solution {
public:
  void backtracking(vector<int> &nums, set<vector<int>> &st, int idx,
                    vector<int> tmp) {
    // when to return:
    // idx reach the end of nums
    if (idx == nums.size()) {
      st.insert(tmp);
      return;
    }

    // each time 2 possible branches:
    // 1. pick the current element
    tmp.push_back(nums[idx]);
    backtracking(nums, st, idx + 1, tmp);

    // 2. don't pick the current element
    tmp.pop_back();
    backtracking(nums, st, idx + 1, tmp);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    // set to avoid duplications
    set<vector<int>> st;
    // 1 possible combination
    vector<int> tmp;
    backtracking(nums, st, 0, tmp);

    // convert set to vector
    return vector<vector<int>>(st.begin(), st.end());
  }
};
