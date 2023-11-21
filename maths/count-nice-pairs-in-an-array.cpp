// https://leetcode.com/problems/count-nice-pairs-in-an-array/?
// 1. transform the original description to apply maths skills
class Solution {
public:
  // reverse a number
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
    // {num, freq}
    unordered_map<int, int> mp;
    // the original formula can be converted to:
    // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    // so we modify each num in the arr, and find equal pairs
    for (int i = 0; i < n; i++) {
      // no need to really modify the original arr, but just need to record the
      // freq of the newNum
      int newNum = nums[i] - reverse(nums[i]);
      mp[newNum]++;
    }

    // count pairs based on the freq
    // key formula to pick any 2 from n elements: i * (i-1) / 2
    for (auto i : mp) {
      long long freq = i.second;
      if (freq > 0) {
        ans = (ans + freq * (freq - 1) / 2) % mod;
      }
    }

    return ans;
  }
};

// 2. direct way based on problem description, would TLE in some cases
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
