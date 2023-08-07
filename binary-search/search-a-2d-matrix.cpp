// https://leetcode.com/problems/search-a-2d-matrix
// 1. use 2 binary search, first to navigate to corresponding row, then search
// in that specific row
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int l = 0, r = m - 1;
    // check which row the target may be in
    int row = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int k = matrix[mid][0];

      if (k == target)
        return true;
      else if (k < target) {
        row = mid;
        l = mid + 1;
      } else if (k > target)
        r = mid - 1;
    }

    // check that row to see if the target exists in the matrix
    l = 0, r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int k = matrix[row][mid];

      if (k == target)
        return true;
      else if (k < target)
        l = mid + 1;
      else if (k > target)
        r = mid - 1;
    }

    return false;
  }
};

// 2. directly apply the binary search to the whole matrix by using idx, and
// calculating its position([row][col]) to get the exact digit
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    // binary search
    // start is the idx of the first cell, end is the idx of the last cell
    int l = 0, r = m * n - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      // calculate the position of the mid cell
      int row = mid / n;
      int col = mid % n;
      int k = matrix[row][col];
      // all cells can be reached, so return only when we found the target
      if (k == target)
        return true;
      else if (k < target)
        l = mid + 1;
      else if (k > target)
        r = mid - 1;
    }

    return false;
  }
};
