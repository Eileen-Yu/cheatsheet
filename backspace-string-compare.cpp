// https://leetcode.com/problems/backspace-string-compare/
//
class Solution {
public:
  bool backspaceCompare(string s, string t) {
    vector<char> ns;
    vector<char> nt;

    for (auto q : s) {
      if (ns.empty() && q == '#')
        continue;
      if (q != '#')
        ns.push_back(q);
      else
        ns.pop_back();
    }

    for (auto q : t) {
      if (nt.empty() && q == '#')
        continue;
      if (q != '#')
        nt.push_back(q);
      else
        nt.pop_back();
    }

    if (ns == nt)
      return true;
    return false;
  }
};
