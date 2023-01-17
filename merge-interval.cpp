class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;

    // sort based on the start
    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
      // if intervals comes after ans[i], no effect
      if (intervals[i][0] > ans.back()[1])
        ans.push_back(intervals[i]);

      // deal with overlapping
      else {
        ans.back()[0] = min(ans.back()[0], intervals[i][0]);
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }

    return ans;
  }
};
