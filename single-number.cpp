// https://leetcode.com/problems/single-number/description/
// 1. bit manipulation: XOR(^)
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    // ^: XOR
    // principle 1:
    // A^A^...^A = 0(even time)
    // A^A^...^A = A(odd time)
    // principle 2:
    // (A^A^B) = (B^A^A) = (A^B^A) = B, shows that position doesn't matter
    for (auto i : nums) {
      ans ^= i;
    }

    return ans;
  }
};

// 2. use map for recording frequency, not satisfy the requirement
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    map<int, int> mp;
    for (auto i : nums) {
      mp[i]++;
    }

    for (auto i : mp) {
      if (i.second == 1)
        return i.first;
    }

    return -1;
  }
};
