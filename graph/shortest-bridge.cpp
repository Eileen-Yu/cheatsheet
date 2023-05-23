// https://leetcode.com/problems/shortest-bridge/description/
// color algorithm to mark as visited (2) +
// DFS to find the connected 1's (1st island), push to the queue +
// BFS to expand the island level by level, level number is the step to connect
// 2 islands

class Solution {
public:
  // queue for BFS
  queue<pair<int, int>> q;
  int ans = INT_MAX;

  // dfs to find the first island
  void dfs(vector<vector<int>> &grid, int i, int j) {
    int n = grid.size();
    // out of range / not part of the first island / already visited
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0 ||
        grid[i][j] == 2)
      return;

    // only when grid[i][j] == 1
    // color algorithm:
    // mark this 1 as visited
    grid[i][j] = 2;
    // add to the queue as the first level
    q.push({i, j});

    // continue to find the next 1's by expanding on 4 directions
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }

  // expand the island level by level, until meet the next island
  void bfs(vector<vector<int>> &grid) {
    // count for level number
    int dist = 0;
    int n = grid.size();

    while (!q.empty()) {
      int size = q.size();

      // 4 directions
      vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

      while (size--) {
        auto [i, j] = q.front();
        q.pop();

        // loop the 4 directions
        for (int d = 0; d < 4; d++) {
          // the next node
          int x = i + dir[d][0];
          int y = j + dir[d][1];

          // if the next is the 2nd island, we try to update the ans
          if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
            ans = min(ans, dist);
          }

          // if the next is still water, need to add to queue and go on to the
          // next level
          else if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
            // mark as visited
            grid[x][y] = 2;
            // add to the q as component of the next level
            q.push({x, y});
          }
        }
      }

      // this level is finished, add this one
      dist++;
    }
  }

  int shortestBridge(vector<vector<int>> &grid) {
    int n = grid.size();
    // if we already found the first island
    bool flag = false;

    // 1. first, find the 1st island, add to the queue as the first level
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // find the first 1 in the grid
        if (grid[i][j] == 1 && !flag) {
          // to find the whole first island and mark it as visited
          dfs(grid, i, j);
          // mark as found the 1st island, break the loop
          flag = true;
          break;
        }
      }
      // already found the first island
      if (flag)
        break;
    }

    // 2. then, use bfs to count the number of levels that need to reach the 2nd
    // island
    bfs(grid);

    return ans;
  }
};
