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

// 1.2 user STL upper_bound()
class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++) {
      // use upper_bound to find the first negative number in that row
      // as upper_bound() returns an iterator, need to substract begin idx to
      // get the idx of that first negative number
      int idx = upper_bound(grid[i].begin(), grid[i].end(), 0, greater<int>()) -
                grid[i].begin();
      ans += n - idx;
    }

    return ans;
  }
};

// 2. linear traversal in the matrix, time complexity: O(m+n)
// if we know the index of the first negative element of any row
// then the next row's first negative element will be present on the left side
// So we traverse from right to left in each row
class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    int i = 0, j = n - 1;
    // from top right to bottom left
    while (i < m && j >= 0) {
      if (grid[i][j] < 0) {
        // the rest elements in this column must all be negative
        ans += m - i;
        // continue to check the previous columns
        j--;
      } else
        i++; // if grid[i][j] > 0, check the next row
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
