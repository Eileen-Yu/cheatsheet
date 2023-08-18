// https://leetcode.com/problems/01-matrix/
// 1. multi-source BFS: try to update each cell to be the distance from the
// nearest 0 we update the ans of that cell each time to be a smaller one
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
    // 4 directions
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // BFS
    queue<pair<int, int>> q;
    // put all 0 cell into the queue
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
          // mark as a 0 cell, to avoid later comparison
          ans[i][j] = 0;
        }
      }
    }

    while (!q.empty()) {
      int a = q.front().first;
      int b = q.front().second;
      q.pop();

      // loop 4 dirs
      for (auto dir : dirs) {
        int x = a + dir[0];
        int y = b + dir[1];

        // out of boundary / already record a smaller distance from a nearer 0
        if (x < 0 || x >= m || y < 0 || y >= n || ans[x][y] <= ans[a][b] + 1)
          continue;
        // else, need to update the ans of this cell with the smaller distance
        ans[x][y] = ans[a][b] + 1;
        // push this cell into the queue for further calculation based on the
        // new ans
        q.push({x, y});
      }
    }

    return ans;
  }
};

// 2. find the nearest cell = BFS(queue), for each cell
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
