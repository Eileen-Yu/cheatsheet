// https://leetcode.com/problems/word-break/
// 1. tabulation: record if s[:i] is valid
// this is very similar to
// https://leetcode.com/problems/extra-characters-in-a-string/
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.length();
    // dp[i] represents if s[:i] is valid
    vector<bool> dp(n, false);
    // base case
    dp[0] = true;

    // for easier search if a substring is in the dict
    unordered_map<string, int> mp;
    for (auto word : wordDict) {
      mp[word]++;
    }

    // try to split the original s by various length
    for (int i = 1; i <= n; i++) {
      // try to use this new char to make up various substrings by various
      // length
      for (int l = 1; l <= i; l++) {
        string subStr = s.substr(i - l, l);
        // if the substring can be found in the dict && the previous substrings
        // are valid
        if (mp.find(subStr) != mp.end() && dp[i - l] == true) {
          dp[i] = true;
          // can move to the next i
          break;
        }
      }
    }

    return dp[n];
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

// 3. plain recursion: would TLE in some cases
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
