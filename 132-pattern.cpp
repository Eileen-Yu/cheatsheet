// https://leetcode.com/problems/132-pattern/
//
//
class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    stack<int> s;         // for the largest element
    int second = INT_MIN; // for the middle element

    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < second)
        return true; // find the smallest one

      while (!s.empty() && nums[i] > s.top()) {
        second = s.top(); // from the largest to the second
        s.pop();
      }

      s.push(nums[i]);
    }

    return false;
  }
};
