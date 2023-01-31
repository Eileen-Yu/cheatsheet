// https://leetcode.com/problems/n-th-tribonacci-number/description/
//
//
// 1. loop
class Solution {
public:
  int tribonacci(int n) {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);

    for (int i = 3; i < n + 1; i++) {
      nums.push_back(nums[i - 3] + nums[i - 2] + nums[i - 1]);
    }

    return nums[n];
  }
}

// 2. recursion
class Solution {
public:
  vector<int> ans;

  void recursion(int n) {
    // the real len is n+1
    if (ans.size() <= n) {
      recursion(n - 3);
      recursion(n - 2);
      recursion(n - 1);
      ans.push_back(ans[n - 3] + ans[n - 2] + ans[n - 1]);
    }
  }

  int tribonacci(int n) {
    ans.push_back(0);
    ans.push_back(1);
    ans.push_back(1);

    recursion(n);
    return ans[n];
  }
};
