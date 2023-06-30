// https://leetcode.com/problems/last-day-where-you-can-still-cross/description/
// Binary search (try each day) + BFS (if we can reach the bottom)
// be careful about the boundary in this problem
class Solution {
public:
  // BFS to check if it's possible to cross the grid on the certain day
  bool isPossible(int r, int c, int day, vector<vector<int>> &cells) {
    // init an empty grid
    // 0 means can pass
    // 1 means block / visited
    // because row's range: 1..m, col's range: 1..n, for convenience
    // we pick [0,m] & [0,n]
    vector<vector<int>> grid(r + 1, vector<int>(c + 1, 0));

    // mark cells before this day as blocked
    // day is 0-based
    for (int i = 0; i < day; i++) {
      int row = cells[i][0], col = cells[i][1];
      grid[row][col] = 1;
    }

    // for BFS
    // pair: {row, col}
    queue<pair<int, int>> q;
    // try each empty cell on the first row as the start
    // start from 1 because grid is 1-based
    for (int i = 1; i <= c; i++) {
      if (grid[1][i] == 0) {
        // mark as visited
        grid[1][i] = 1;
        q.push({1, i});
      }
    }

    // 4 directions for loop
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int row = p.first, col = p.second;

      for (auto d : directions) {
        int x = row + d.first;
        int y = col + d.second;
        // check if out of boundary
        if (x <= 0 || x > r || y <= 0 || y > c)
          continue;
        // check if it's blocked / visited
        if (grid[x][y] == 1)
          continue;
        // check if already reached the bottom
        if (x == r)
          return true;
        // else, continue to search
        // 1. mark as visited
        grid[x][y] = 1;
        // 2. push to the queue
        q.push({x, y});
      }
    }

    return false;
  }

  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    // left is the earliest day, right is last day
    int l = 0, r = row * col;
    int ans = 0;
    // binary search
    while (l <= r) {
      int mid = l + (r - l) / 2;
      // check if it's possible to cross the grid on `mid` day
      if (isPossible(row, col, mid, cells)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }

    return ans;
  }
};
