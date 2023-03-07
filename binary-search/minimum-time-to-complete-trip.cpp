// https://leetcode.com/problems/minimum-time-to-complete-trips/
// 1. binary search
class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    // the minimum and maximum of possible time needed
    long long low = 1;
    long long high = 1e14;
    long long mid;

    while (low <= high) {
      mid = low + (high - low) / 2;
      long long tmp = 0;
      for (auto i : time) {
        tmp += mid / i;
      }

      // given time is too much
      // notice the boundary!!!
      if (tmp >= totalTrips)
        high = mid - 1;

      else
        low = mid + 1;
    }
    // notice what binary search would return
    return low;
  }
}
// 2. plain solution, would TLE
class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    long long n = time.size();
    // record tmp total trip
    long long tmp = 0;
    // record how many times it tak
    long long t = 1;
    // record the trip completed by each bus at each time point
    vector<long long> record(n, 0);

    while (tmp < totalTrips) {
      tmp = 0;
      for (long long i = 0; i < n; i++) {
        record[i] = t / time[i];
        tmp += record[i];
      }

      t++;
    }

    return t - 1;
  }
};
