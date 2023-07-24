// https://leetcode.com/problems/powx-n/description/
// 1. binary exponentiation: x^(a+b) = x^a * x^b
// reduce O(n) to O(log n)
class Solution {
public:
  double myPow(double x, int n) {
    // base case for the recursion
    if (n == 0)
      return 1.0;

    double half = myPow(x, n / 2);

    // if n is even, x^n is simply (x^(n/2))^2
    if (n % 2 == 0)
      return half * half;

    // if n is odd, x^n is either (x^(n/2)^2) * x (n > 0) OR (x^(n/2)^2) / x (n
    // < 0)
    else
      return n < 0 ? half * half / x : half * half * x;
  }
};

// 2. plain version: this would TLE when n = -2147483648
class Solution {
public:
  double myPow(double x, int n) {
    if (x == 1)
      return (double)1;

    double ans = 1;

    if (n > 0) {
      while (n--) {
        ans *= x;
      }
    }

    else if (n < 0) {
      while (n++) {
        ans *= x;
      }
      ans = 1 / ans;
    }

    return ans;
  }
};
