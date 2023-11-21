// https://leetcode.com/problems/count-nice-pairs-in-an-array/?
// 1. direct way based on problem description, would TLE in some cases
class Solution {
public:
  int reverse(int n) {
    int ans = 0;
    while (n) {
      // digit of this position
      int cur = n % 10;
      ans = ans * 10 + cur;
      // update n to deal with the next position
      n /= 10;
    }

    return ans;
  }

  int countNicePairs(vector<int> &nums) {
    int mod = 1e9 + 7;
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] + reverse(nums[j]) == nums[j] + reverse(nums[i]))
          ans = (ans + 1) % mod;
      }
    }

    return ans;
  }
};
