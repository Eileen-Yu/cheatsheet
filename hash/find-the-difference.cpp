// https://leetcode.com/problems/find-the-difference
// 1. frequency --> hash table
class Solution {
public:
  char findTheDifference(string s, string t) {
    // char in string t, frequency
    unordered_map<int, int> mp;
    for (auto i : t) {
      mp[i]++;
    }

    for (auto i : s) {
      mp[i]--;
    }

    for (auto i : mp) {
      if (i.second == 1)
        return i.first;
    }

    return '.';
  }
};
