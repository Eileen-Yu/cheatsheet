// https://leetcode.com/problems/calculate-digit-sum-of-a-string/
//
//
class Solution {
public:
  string digitSum(string s, int k) {
    while (s.size() > k) {
      string ns = "";
      for (int i = 0; i < s.size();) {
        int sum = 0, j = i;
        for (; j < i + k && j < s.size(); j++) {
          sum += (s[j] - '0');
        }
        ns += to_string(sum);
        i = j;
      }
      s = ns;
    }
    return s;
  }
};
