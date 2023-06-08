// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
// 1. binary search to find the first negative number of each row
// count of negative numbers in that row = n - idx
class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++) {
      // binary search to find the first negative number in that row
      int l = 0, r = n - 1;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (grid[i][mid] >= 0)
          l = mid + 1;
        else
          r = mid;
      }
      if (l == r && grid[i][l] < 0)
        ans += n - l;
    }

    return ans;
  }
};

// 3. brute force method, using the decreasing pattern
class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    // check if we meet a negative
    bool f = false;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] < 0) {
          ans += n - j;
          // the following grid[i] are all negatives
          if (j == 0)
            f = true;
          break;
        }
      }
      if (f == true) {
        ans += n * (m - i - 1);
        break;
      }
    }

    return ans;
  }
};
