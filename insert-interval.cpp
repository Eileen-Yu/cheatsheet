class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> ans;

    for (auto i : intervals) {
      // i comes before newInterval, no effect
      if (i[1] < newInterval[0])
        ans.push_back(i);

      // i comes after newInterval, then add newInterval and compare i with the
      // next
      else if (i[0] > newInterval[1]) {
        ans.push_back(newInterval);
        newInterval = i;
      }

      // newInterval has overlapping with i, then make the range maximum
      else {
        newInterval[0] = min(i[0], newInterval[0]);
        newInterval[1] = max(i[1], newInterval[1]);
      }
    }

    ans.push_back(newInterval);

    return ans;
  }
};
