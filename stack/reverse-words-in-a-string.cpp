// https://leetcode.com/problems/reverse-words-in-a-string/description/
// stringstream to split the sentence + stack to reverse the words
class Solution {
public:
  string reverseWords(string s) {
    // store the reversed words
    stack<string> st;
    // stringstream to help seperate words from the sentence
    stringstream ss(s);
    // a single word
    string tmp;

    while (ss >> tmp) {
      st.push(tmp);
    }

    string ans = "";
    while (!st.empty()) {
      // needs to split by space
      ans += st.top() + ' ';
      st.pop();
    }

    // drop the space at the end
    return ans.substr(0, ans.length() - 1);
  }
};
