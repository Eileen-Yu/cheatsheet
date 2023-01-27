// https://leetcode.com/problems/palindrome-partitioning/description/
//
class Solution {
public:
  // check if it's a palindrome
  bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] == s[s.size() - 1 - i]) {
        continue;
      }
      return false;
    }
    return true;
  }

  void recursion(vector<string> &tmp, vector<vector<string>> &ans, string s) {
    // when to return: no more letter left
    if (s.size() == 0) {
      ans.push_back(tmp);
      return;
    }

    for (int i = 0; i < s.size(); i++) {
      string check = s.substr(0, i + 1);
      if (isPalindrome(check)) {
        // take this check as a individual element
        tmp.push_back(check);
        recursion(tmp, ans, s.substr(i + 1));
        // don't take this check as individual, hope to make another palindrome
        // with latter letter
        tmp.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> tmp;
    recursion(tmp, ans, s);
    return ans;
  }
};
