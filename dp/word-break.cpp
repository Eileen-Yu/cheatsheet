// https://leetcode.com/problems/word-break/
// 1. plain recursion: would TLE in some cases
class Solution {
public:
  bool flag = false;

  void recursion(string s, map<string, int> &mp) {
    // when to return
    // if there is one possible segmentation
    if (flag == true)
      return;
    // if all words successfully be segmented
    if (s.empty()) {
      flag = true;
      return;
    }

    for (int i = 0; i < s.length(); i++) {
      string subString = s.substr(0, i + 1);
      // if this subword is in the dictionary
      if (mp.find(subString) != mp.end()) {
        recursion(s.substr(i + 1), mp);
      }
      // if not, the loop would automatically try the next subword
    }
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.length();
    // for easier word search
    map<string, int> mp;
    for (auto i : wordDict) {
      mp[i]++;
    }

    recursion(s, mp);

    return flag;
  }
};

// 2. memoization: record if a certain string is legal / illegal
class Solution {
public:
  bool recursion(string s, map<string, int> &mp, map<string, bool> &dp) {
    // memoization: if the string has been already checked
    if (dp.find(s) != dp.end())
      return dp[s];

    // when to return: if all subwords have been checked
    if (s.empty())
      return true;

    // try to form various subwords in this string
    for (int i = 0; i < s.length(); i++) {
      string subString = s.substr(0, i + 1);
      // if this subword is in the dictionary
      if (mp.find(subString) != mp.end()) {
        // continue to check the rest of the string
        // if the rest is also legal, mark this string as legal
        if (recursion(s.substr(i + 1), mp, dp))
          return dp[s] = true;
      }
    }
    // else, mark this string as illegal
    return dp[s] = false;
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.length();
    // for easier word search
    map<string, int> mp;
    for (auto i : wordDict) {
      mp[i]++;
    }
    // dp[string] represents if the word 'string' is in the dictionary
    map<string, bool> dp;

    return recursion(s, mp, dp);
  }
};
