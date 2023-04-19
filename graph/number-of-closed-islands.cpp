// https://leetcode.com/problems/number-of-closed-islands/description/
// dfs + expand on 4 directions

class Solution {
public:
  void dfs(int i, int j, vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // when to return:
    // if out of boundary OR is not island(0)
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1)
      return;

    // mark this island as visited
    grid[i][j] = 1;
    // continue to check its neighbors, as they are connected to the current
    // island they should also be marked as visited as an entire one
    dfs(i - 1, j, grid);
    dfs(i + 1, j, grid);
    dfs(i, j - 1, grid);
    dfs(i, j + 1, grid);
  }

  int closedIsland(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // deal with left & right boundary to except open islands
    for (int i = 0; i < m; i++) {
      dfs(i, 0, grid);
      dfs(i, n - 1, grid);
    }

    // deal with top & bottom boundary to except open islands
    for (int j = 0; j < n; j++) {
      dfs(0, j, grid);
      dfs(m - 1, j, grid);
    }

    // start to count
    int ans = 0;
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        // find a closed island
        if (grid[i][j] == 0) {
          ans++;
          // mark it and other islands connected with it as visited
          dfs(i, j, grid);
        }
      }
    }

    return ans;
  }
}
