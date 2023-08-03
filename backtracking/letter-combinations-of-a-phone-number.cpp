// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// backtracking to try various chars on each position + map to store & loop
// possibilities
class Solution {
public:
  // backtracking
  void recursion(unordered_map<char, vector<char>> &mp, string &digits, int idx,
                 string &tmp, vector<string> &ans) {
    // when to return
    if (idx == digits.length()) {
      ans.push_back(tmp);
      return;
    }

    // try to fill this position with various chars that matches with this digit
    char digit = digits[idx];
    for (auto i : mp[digit]) {
      // 1. if pick this char
      tmp.push_back(i);
      recursion(mp, digits, idx + 1, tmp, ans);

      // 2. if not pick this char, would try another char in the next loop
      tmp.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    // map between digit & chars
    // e.g 2: a,b,c
    unordered_map<char, vector<char>> mp;
    // fill in the map
    mp['2'] = {'a', 'b', 'c'};
    mp['3'] = {'d', 'e', 'f'};
    mp['4'] = {'g', 'h', 'i'};
    mp['5'] = {'j', 'k', 'l'};
    mp['6'] = {'m', 'n', 'o'};
    mp['7'] = {'p', 'q', 'r', 's'};
    mp['8'] = {'t', 'u', 'v'};
    mp['9'] = {'w', 'x', 'y', 'z'};

    int n = digits.length();
    // special case
    if (n == 0)
      return {};

    // one possible combination
    string tmp = "";
    vector<string> ans;

    recursion(mp, digits, 0, tmp, ans);
    return ans;
  }
};
