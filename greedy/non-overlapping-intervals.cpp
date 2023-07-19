// https://leetcode.com/problems/non-overlapping-intervals/description/
// sort by the end time, and compare each start time with the last valid end
// time
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // sort based on the end time in ascending order
    // [] means the third param is a lambda function
    // use reference(&) & const to avoid modifying the compared elements([start,
    // end] themselves)
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    // count the number of non-overlapping intervals;
    // the first must be one, so init to 1
    int count = 1;
    // track the idx of the last processed interval
    int prev = 0;
    int n = intervals.size();
    // from the second interval to compare
    for (int i = 1; i < n; i++) {
      // if the next start is bigger than the last end
      // it means there is no overlap
      if (intervals[i][0] >= intervals[prev][1]) {
        count++;
        // need to update prev for the next comparison
        prev = i;
      }
    }

    return n - count;
  }
};
