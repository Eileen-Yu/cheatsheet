// https://leetcode.com/problems/majority-element-ii/description/
// 1. hash map to record frequency of each element
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {

    // element, frequency
    unordered_map<int, int> mp;
    for (auto i : nums)
      mp[i]++;

    vector<int> ans;
    for (auto i : mp) {
      if (i.second > nums.size() / 3)
        ans.push_back(i.first);
    }

    return ans;
  }
};
