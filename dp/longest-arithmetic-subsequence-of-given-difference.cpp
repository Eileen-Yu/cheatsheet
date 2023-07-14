// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
// dp / hash map to record the longest subsequence ending at element i
class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    // element: longest subsequence ending at this element
    unordered_map<int, int> mp;
    int ans = INT_MIN;
    for (auto i : arr) {
      // find the last element, add 1
      mp[i] = mp[i - difference] + 1;
      ans = max(ans, mp[i]);
    }

    return ans;
  }
};
