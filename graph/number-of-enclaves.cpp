// https://leetcode.com/problems/number-of-enclaves/description/
// DFS + matrix (4 directions)

class Solution {
public:
  void dfs(int i, int j, vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // when to return
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
      return;

    // else mark this as visited
    grid[i][j] = 0;
    // continue to check adjacent neighbors as they can also walk off
    // so mark them as visited as well
    dfs(i - 1, j, grid);
    dfs(i + 1, j, grid);
    dfs(i, j - 1, grid);
    dfs(i, j + 1, grid);
  }

  int numEnclaves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    // deal with elements on left & right boundaries
    for (int i = 0; i < m; i++) {
      dfs(i, 0, grid);
      dfs(i, n - 1, grid);
    }

    // deal with elements on top & boottom boundaries
    for (int j = 0; j < n; j++) {
      dfs(0, j, grid);
      dfs(m - 1, j, grid);
    }

    // any element has been visited should be counted
    int ans = 0;
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (grid[i][j] == 1)
          ans++;
      }
    }

    return ans;
  }
};
