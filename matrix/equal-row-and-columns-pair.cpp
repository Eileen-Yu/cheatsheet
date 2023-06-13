// https://leetcode.com/problems/equal-row-and-column-pairs/description/
// matrix (transpose matrix) + hash map to count frequency
class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    int n = grid.size();
    // transpose matrix
    vector<vector<int>> grid2(n, vector<int>(n));

    // hash map to record the count number of each row in original grid
    map<vector<int>, int> mp;

    for (int i = 0; i < n; i++) {
      // count ++
      mp[grid[i]]++;
      // generate the transpose matrix
      for (int j = 0; j < n; j++) {
        grid2[j][i] = grid[i][j];
      }
    }

    int ans = 0;

    // loop each column in grid2
    for (int i = 0; i < n; i++) {
      // if the same row exists
      if (mp.find(grid2[i]) != mp.end())
        ans += mp[grid2[i]];
    }

    return ans;
  }
};
