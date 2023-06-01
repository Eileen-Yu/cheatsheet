// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// BFS to traverse level by level + mark as visited
// specially suitable to find shortest path in matrix
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    // special cases
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;
    if (n == 1)
      return 1;

    // for BFS
    queue<vector<int>> q;
    // put the starting point into it
    q.push({0, 0});
    // mark as visited
    grid[0][0] = 1;

    int ans = 0;

    // 8 directions
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    while (!q.empty()) {
      int size = q.size();
      // a new level
      ans++;
      // traverse level by level
      while (size--) {
        auto tmp = q.front();
        q.pop();

        int x = tmp[0];
        int y = tmp[1];

        // try each of the 8 directions
        for (auto d : dir) {
          int i = x + d[0];
          int j = y + d[1];

          // we can reach the end point along the path
          if (i == n - 1 && j == n - 1)
            return ans + 1;

          // out of boundary
          if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 1)
            continue;

          // not reach the end yet, but meet a '0'
          else if (grid[i][j] == 0) {
            // mark as visited
            grid[i][j] = 1;
            q.push({i, j});
          }
        }
      }
    }
    // we can not reach tne end point along the path
    return -1;
  }
};
