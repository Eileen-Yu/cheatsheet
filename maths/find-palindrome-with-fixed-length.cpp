// https://leetcode.com/problems/find-palindrome-with-fixed-length/

class Solution {
public:
  // to get the second half
  // skip is decided by if it's odd / even
  long long reverse(long long n, bool skip) {
    long long res = 0;
    for (n = skip ? n / 10 : n; n > 0; n /= 10) {
      res = res * 10 + n % 10;
    }
    return res;
  }

  vector<long long> kthPalindrome(vector<int> &queries, int intLength) {
    vector<long long> ans;

    // only need the first n/2 digits, the other half can be got by reversing
    // the first half

    // can reach this start, e.g: 101, intLength = 3, start = 10
    long long start = pow(10, (intLength + 1) / 2 - 1);
    // cannot reach this end, e.g: 101, intLength = 3, end = 100
    long long end = pow(10, (intLength + 1) / 2);
    // need to move the first half `mul` left to leave space for the second half
    long long mul = pow(10, intLength / 2);

    for (int q : queries)
      ans.push_back(start + q > end
                        ? -1
                        : (start + q - 1) * mul +
                              reverse(start + q - 1, intLength % 2));
    return ans;
  }
};
