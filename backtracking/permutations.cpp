// https://leetcode.com/problems/permutations/
// backtracking to try each element to fill on a certain position

// 1. use additional vector<bool> visited to mark, and copy the tmp each time to
// push it to the ans
class Solution {
public:
  void recursion(vector<int> &nums, vector<bool> &visited, vector<int> &tmp,
                 vector<vector<int>> &ans) {
    // when to return
    if (tmp.size() == nums.size()) {
      ans.push_back(tmp);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        // 1. if pick this nums[i]
        tmp.push_back(nums[i]);
        // mark this element as used, avoid duplication
        visited[i] = true;
        // continue to fill in the next position
        recursion(nums, visited, tmp, ans);

        // 2. if not pick this nums[i], the for loop would automatically try to
        // fill in this position with another element
        tmp.pop_back();
        visited[i] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    // one possible permutation
    vector<int> tmp;
    int n = nums.size();
    // mark if an element has been tried on a certain position
    vector<bool> visited(n, false);

    recursion(nums, visited, tmp, ans);

    return ans;
  }
};

// 2. inplace, use swap
class Solution {
public:
  void recursion(vector<int> &nums, int idx, vector<vector<int>> &ans) {
    // when to return
    if (idx == nums.size()) {
      ans.push_back(nums);
      return;
    }

    for (int i = idx; i < nums.size(); i++) {
      // inplace, try different elements as the first one
      swap(nums[idx], nums[i]);
      recursion(nums, idx + 1, ans);
      // backtracking, undo this swap, instead try the next element in the next
      // loop
      swap(nums[i], nums[idx]);
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;

    recursion(nums, 0, ans);

    return ans;
  }
};
