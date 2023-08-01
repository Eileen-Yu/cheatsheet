// https://leetcode.com/problems/restore-ip-addresses/description/
//
//
class Solution {
public:
  // check if the string is valid
  bool valid(string s) {
    if (s.length() > 3 || s.length() == 0)
      return false;
    // 01.02...is not valid
    if (s.length() > 1 && s[0] == '0')
      return false;
    // range must be 0-255
    if (stoi(s) > 255)
      return false;

    return true;
  }

  void recursion(string &s, string tmp, int idx, vector<string> &ans, int dot) {
    // when to return
    // there's already 3 dots
    // the left (4th) subaddress is valid
    if (dot == 3 && valid(s.substr(idx))) {
      ans.push_back(tmp + s.substr(idx));
      return;
    }

    int sz = s.size();
    // every subaddress length must be 1-3
    for (int i = idx; i < min(idx + 3, sz); i++) {
      if (valid((s.substr(idx, i - idx + 1)))) {
        // put dot after this digit
        tmp.push_back(s[i]);
        tmp.push_back('.');
        recursion(s, tmp, i + 1, ans, dot + 1);
        // don't put dot after this digit, then i++
        tmp.pop_back();
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    string tmp;
    recursion(s, tmp, 0, ans, 0);
    return ans;
  }
};
