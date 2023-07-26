// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/
// binary search: try every speed each time to find the minimum one
// be careful of the double division:
// casting either operand of the division to a floating-point type before the
// division operation is performed
class Solution {
public:
  int minSpeedOnTime(vector<int> &dist, double hour) {
    int n = dist.size();
    // n-1 is the least full hour needed
    if (n - 1 >= hour)
      return -1;

    int l = 1, r = 1e7;
    int ans = INT_MAX;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      double time = 0;

      for (int i = 0; i < n; i++) {
        // round up
        // int / int would always return int, so need to transfer
        // at least one of the operands of the division operation to be of
        // floating-point type
        if (i != n - 1)
          time += ceil((double)dist[i] / (double)mid);
        // we don't need to wait for extra time for the last dist
        else if (i == n - 1)
          time += (double)dist[i] / mid;
      }

      if (time <= hour) {
        ans = min(ans, mid);
        // the speed can be slower
        r = mid - 1;
      }
      // speed needs to be faster
      else if (time > hour)
        l = mid + 1;
    }

    return ans;
  }
};
