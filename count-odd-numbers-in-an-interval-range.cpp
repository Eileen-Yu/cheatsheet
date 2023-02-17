// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
// 1. math
class Solution {
public:
  int countOdds(int low, int high) {
    int ans;
    ans = (high - low) / 2;
    // either high / low is odd number
    if (high % 2 == 1 || low % 2 == 1)
      ans++;

    return ans;
  }
};

// 2. ugly one
class Solution {
public:
  int countOdds(int low, int high) {
    if (low == high && low % 2 == 1)
      return 1;
    if (low == high && low % 2 == 0)
      return 0;

    int ans = 0;
    int tmp = 0;

    // start from the first odd number
    // if low is odd number
    if (low % 2 == 1)
      tmp = low;
    // if low is even number
    if (low % 2 == 0)
      tmp = low + 1;

    // as we already have 1 odd number
    ans++;

    // in case high is also odd, avoid the latter +1
    if (tmp == high)
      return ans;

    while (tmp + 2 < high) {
      tmp += 2;
      ans++;
    }

    if (high % 2 == 1)
      ans++;

    return ans;
  }
};
