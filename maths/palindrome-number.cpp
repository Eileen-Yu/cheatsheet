// https://leetcode.com/problems/palindrome-number/description/
// 1. reverse the original integer via math skills
class Solution {
public:
  bool isPalindrome(int x) {
    // special case
    if (x < 0)
      return false;

    // record the reversed x
    long long reverse = 0;
    long long tmp = x;

    // how to reverse a integer
    while (tmp) {
      // move all to 1 left + current digit
      reverse = reverse * 10 + tmp % 10;
      tmp /= 10;
    }

    return reverse == x;
  }
};

// 2. convert to string, use idx to compare str[i] and str[n-i-1]
class Solution {
public:
  bool isPalindrome(int x) {
    // special case:
    if (x < 0)
      return false;

    // convert x to string
    string str = to_string(x);
    int n = str.length();

    // check each pair
    for (int i = 0; i < n / 2; i++) {
      if (str[i] != str[n - i - 1])
        return false;
    }

    return true;
  }
};
