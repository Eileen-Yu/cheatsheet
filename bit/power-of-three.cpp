// https://leetcode.com/problems/power-of-three/description/
// loop / recursion is ok, here use bit manupulation
bool isPowerOfThree(int n) {
  // bit representation
  long tmp = 1;

  // 9 = 1 + 10+ 110
  while (n > 1 && tmp < n) {
    tmp += tmp << 1;
  }

  return tmp == n;
}
