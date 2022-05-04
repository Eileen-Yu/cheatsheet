// https://leetcode.com/problems/max-number-of-k-sum-pairs/
//
//
class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int ans = 0;

    for (auto q : nums) {
      if (mp[k - q] > 0) {
        ans++;
        mp[k - q]--;
      } else
        mp[q]++;
    }

    return ans;
  }
};
