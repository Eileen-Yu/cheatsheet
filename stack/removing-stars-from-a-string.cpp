// https://leetcode.com/problems/removing-stars-from-a-string/description/
// stack to play HAPPY ELIMINATING game
// same for check parentheses / palindrome

class Solution {
public:
  string removeStars(string s) {
    // if there is no *, return the original string
    if (s.find('*') == string::npos)
      return s;

    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '*')
        st.push(s[i]);
      else {
        if (!st.empty())
          st.pop();
      }
    }

    // if all chars have been removed
    if (st.empty())
      return "";

    // if there is char left, compose the ans in the correct order
    string ans = "";
    while (!st.empty()) {
      ans = st.top() + ans;
      st.pop();
    }

    return ans;
  }
};
