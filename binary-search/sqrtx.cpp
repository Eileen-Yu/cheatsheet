// https://leetcode.com/problems/sqrtx/s
// binary search to try every possible ans between [1, x]
// the ans meet the requirement:
// ans * ans <= x & (ans + 1) * (ans + 1) > x
class Solution {
public:
  int mySqrt(int x) {
    // special case
    if (x == 0)
      return 0;

    // binary search to try all integers in [1, x]
    int l = 1, r = x;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      // if mid * mid > x, need to make mid smaller
      if (mid > x / mid)
        r = mid - 1;

      // else if mid * mid <= x, either mid is the ans / need to make mid bigger
      else {
        // 1. if (mid+1) * (mid+1) > x and mid * mid < x, then mid is the ans
        if (mid + 1 > x / (mid + 1))
          return mid;
        // 2. else if (mid+1) * (mid+1) < x still, needs to make mid bigger
        l = mid + 1;
      }
    }

    // should never reach this line
    return -1;
  }
};
