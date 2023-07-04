// https://leetcode.com/problems/single-number/description/
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
