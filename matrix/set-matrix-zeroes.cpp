// https://leetcode.com/problems/set-matrix-zeroes/
//
// matrix: use first row & column as the marker to indicate if the cells in a
// specific row / column needs to be set to 0
// this can implement it in-place

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // mark if the first column needs to be set to 0
    // this is aditionally needed becase we'll update first column as the marker
    // but still needs to store the original status
    int col0 = 1;

    // 1. first pass, use first row & col as marker
    // loop each row
    for (int i = 0; i < m; i++) {
      // if any row's first element is 0, then col0 needs to be set to 0
      if (matrix[i][0] == 0)
        col0 = 0;

      // loop each column from the second element in this row
      for (int j = 1; j < n; j++) {
        // if the current cell is 0
        if (matrix[i][j] == 0) {
          // use the first row & column as marker to mark that i & j row needs
          // to be set to 0
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    // 2. second pass, loop each cell to set 0's inplace
    // loop from bottom because we need to preserve the markers (first row &
    // first column)
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 1; j--) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;
      }

      // if col0 = 0, set the first cell of this row to 0
      if (col0 == 0)
        matrix[i][0] = 0;
    }
  }
};
