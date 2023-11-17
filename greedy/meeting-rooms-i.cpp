// Given an array of meeting time intervals consisting of start and end
// times[[s1,e1],[s2,e2],...](si < ei), determine if a person could attend all
// meetings.
// Example1:
// Input: intervals = [[0,30],[5,10],[15,20]], output: false
// Example2:
// Input: intervals = [[7,10],[2,4]], output: true
// Output : false
class Solution {
public:
  bool canAttendMeetings(vector<vector<int>> meetings) {
    // sort by the start time from small to big
    sort(meetings.begin(), meetings.end(),
         [](const vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

    // loop from the second meeting
    for (int i = 1; i < meetings.size(); i++) {
      // if the current start time < last end time, there is conflict
      if (meetings[i][0] < meetings[i - 1][1])
        return false;
    }

    return true;
  }
}
