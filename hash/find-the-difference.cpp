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

// --> a optimized way: we don't neet to loop twice
// each time just add the diff to a later postion
class Solution {
public:
  char findTheDifference(string s, string t) {
    // loop all diff chars in the two strings
    for (int i = 0; i < s.length(); i++) {
      // each time add the diff to a later char in string t
      t[i + 1] += t[i] - s[i];
    }

    // the final diff is the ASCII of the extra char
    return char(t[t.length() - 1]);
  }
};
