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

// 2. use ASCII, the diff of sumS and sumT is the ASCII of the extra char
// in this way, we don't care the order of chars
class Solution {
public:
  char findTheDifference(string s, string t) {
    int sumS = 0;
    int sumT = 0;
    // sum up all ASCII in string s
    for (auto i : s)
      sumS += i;

    // sum up all ASCII in string t
    for (auto i : t)
      sumT += i;

    return char(sumT - sumS);
  }
};
