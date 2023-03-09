// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
// required.
// example 1:
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// example 2:
// Input: [[7,10],[2,4]]
// Output: 1
//

// Greedy
class Solution {
public:
  int minimumMeetingRoom(vector<vector<int>> &meetings) {
    // record all time point
    // use bool to record if it's start or end
    vector<pair<int, bool>> record;
    for (auto i : meetings) {
      for (int j = 0; j < 2; j++) {
        if (j == 0) {
          record.push_back({j, true});
        } else {
          record.push_back({j, false});
        }
      }
    }

    // sort all the time point
    sort(record.begin(), record.end());

    int ans = 0, tmp = 0;
    for (auto [time, type] : record) {
      // if the time is start
      if (type == true)
        tmp++;
      else
        tmp--;
      // ans is the maximum
      ans = max(ans, tmp);
    }

    return ans;
  }
};
