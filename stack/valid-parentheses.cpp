// https://leetcode.com/problems/valid-parentheses/description/
//
// use stack to solve problems like palindrome / symmetry

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;

    for (auto i : s) {
      if (st.empty())
        st.push(i);
      else {
        char tmp = st.top();
        if (tmp == '(' && i == ')' || tmp == '[' && i == ']' ||
            tmp == '{' && i == '}') {
          st.pop();
          continue;
        } else {
          st.push(i);
        }
      }
    }
    // if empty, means all char has its matching pair
    if (st.empty())
      return true;
    return false;
  }
};
