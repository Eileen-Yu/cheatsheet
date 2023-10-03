// https://leetcode.com/problems/number-of-good-pairs/description
// hash map to count frequency
class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    // {num : frequency}
    unordered_map<int, int> mp;

    int ans = 0;
    for (auto i : nums) {
      if (mp.find(i) != mp.end())
        ans += mp[i];
      // put this element into mp
      mp[i]++;
    }

    return ans;
  }
};
