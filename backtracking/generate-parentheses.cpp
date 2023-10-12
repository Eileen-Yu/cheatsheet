// https://leetcode.com/problems/generate-parentheses/description/
// backtracking to generate all valid parentheses
// 2 restrictions:
// 1. # of ( <= n
// 2. # of ) <= ) always

class Solution {
public:
  void backtracking(int open, int close, int n, string tmp,
                    vector<string> &ans) {
    // when to return
    if (tmp.length() == n * 2) {
      ans.push_back(tmp);
      return;
    }

    // everytime we have 2 choices:
    // 1. try to add a '('
    if (open < n)
      backtracking(open + 1, close, n, tmp + "(", ans);
    // 2. try to add a ')'
    if (close < open)
      backtracking(open, close + 1, n, tmp + ")", ans);
  }

  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtracking(0, 0, n, "", ans);

    return ans;
  }
};
