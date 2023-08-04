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
