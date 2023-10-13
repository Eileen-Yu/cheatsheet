// https://leetcode.com/problems/multiply-strings/description/
// simulate the vertical multiplication with % and carry
class Solution {
public:
  string multiply(string num1, string num2) {
    // special case
    if (num1 == "0" || num2 == "0")
      return "0";

    int m = num1.length(), n = num2.length();
    // store the digits of each position in the multiplication result
    // len(m) * len(n), the result can at most have (m+n) positions
    // there may be leading 0's in the result digits
    vector<int> digits(m + n, 0);

    // main simulation part
    // multiply each position from the least significant to most significant
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        // the corresponding position in the result
        digits[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        // carry
        digits[i + j] += digits[i + j + 1] / 10;
        // the actual digit on the corresponding position
        digits[i + j + 1] %= 10;
      }
    }

    // generate the ans string from the recorded digits
    string ans = "";

    int i = 0;
    // skip the leading 0's in the result
    while (digits[i] == 0)
      i++;

    // convert the other digits to int
    for (i; i < digits.size(); i++) {
      ans += to_string(digits[i]);
    }

    return ans;
  }
};
