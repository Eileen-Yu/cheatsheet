// https://leetcode.com/problems/01-matrix/
// 1. find the nearest cell = BFS(queue), for each cell
// but would TLE in some cases
class Solution {
public:
  // 4 directions
  vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int getNearestZero(vector<vector<int>> &mat, int i, int j) {
    // if this cell itself is 0, directly return 0
    if (mat[i][j] == 0)
      return 0;

    int m = mat.size();
    int n = mat[0].size();

    // else, if this cell is 1
    queue<pair<int, int>> q;
    q.push({i, j});
    // mark as visited
    mat[i][j] = 1;
    // count the step to the nearest 0
    int c = 0;

    while (!q.empty()) {
      c++;

      int size = q.size();
      while (size--) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (auto dir : dirs) {
          int x = a + dir[0];
          int y = b + dir[1];

          // out of boundary
          if (x < 0 || x >= m || y < 0 || y >= n)
            continue;

          if (mat[x][y] == 0)
            return c;

          // else if mat[x][y] = 1
          q.push({x, y});
        }
      }
    }

    return -1;
  }

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans[i][j] = getNearestZero(mat, i, j);
      }
    }

    return ans;
  }
};
