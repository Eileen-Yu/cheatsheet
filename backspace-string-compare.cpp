// https://leetcode.com/problems/backspace-string-compare/
// 1. directly generate new string with pop_back & push_back
class Solution {
public:
  bool backspaceCompare(string s, string t) {
    string s1, s2;

    // generate s1 after backspace
    for (auto i : s) {
      if (s1 != "" && i == '#')
        s1.pop_back();

      else if (i != '#')
        s1.push_back(i);
    }

    // generate s2 after backspace
    for (auto i : t) {
      if (s2 != "" && i == '#')
        s2.pop_back();

      else if (i != '#')
        s2.push_back(i);
    }

    return s1 == s2;
  }
};

// similar idea use vector
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

    return ns == nt;
  }
};

// 2. stack (little bit complex)
class Solution {
public:
  bool backspaceCompare(string s, string t) {
    stack<char> s1, s2;
    // put string s char into s1
    for (auto i : s) {
      if (!s1.empty() && i == '#')
        s1.pop();

      else if (i != '#')
        s1.push(i);
    }

    // put string t char into s2
    for (auto i : t) {
      if (!s2.empty() && i == '#')
        s2.pop();

      else if (i != '#')
        s2.push(i);
    }

    // compare each char in s1 and s2
    while (!s1.empty() && !s2.empty()) {
      if (s1.top() != s2.top())
        return false;

      // else, continue to compare the next char
      s1.pop();
      s2.pop();
    }

    // if any of the stack is empty while the other is not empty
    if ((s1.empty() && !s2.empty()) || (!s1.empty() && s2.empty()))
      return false;

    return true;
  }
};
