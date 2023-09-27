// https://leetcode.com/problems/decoded-string-at-index/
// 1. try to generate the string, most direct but MLE
class Solution {
public:
  string decodeAtIndex(string s, int k) {
    // record the tmp substring
    stack<char> st;
    string ans = "";

    for (auto i : s) {
      // if it's a letter
      if (isalpha(i)) {
        st.push(i);
        continue;
      }

      // else if it's a digit
      // 1. put all chars in the stack to the ans
      // the substring in the stack
      string tmp;
      while (!st.empty()) {
        tmp = st.top() + tmp;
        st.pop();
      }
      // append this substring to the ans
      ans += tmp;

      // 2. repeat it
      string s = ans;
      int repeat = int(i) - 1;
      while (repeat--)
        ans += s;
    }

    return string(1, ans[k - 1]);
  }
};
