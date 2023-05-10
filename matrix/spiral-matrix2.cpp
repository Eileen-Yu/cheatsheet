// https://leetcode.com/problems/spiral-matrix-ii/
// narrow the rowBegin, rowEnd, colBegin, colEnd
// same mathod to spiral-matrix-i

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int rowBegin = 0, rowEnd = n - 1;
    int colBegin = 0, colEnd = n - 1;
    // element from 1 to n^2
    int x = 1;

    while (rowBegin <= rowEnd && colBegin <= colEnd) {
      // left to right
      for (int j = colBegin; j <= colEnd && x <= n * n; j++) {
        ans[rowBegin][j] = x++;
      }
      rowBegin++;

      // top to bottom
      for (int i = rowBegin; i <= rowEnd && x <= n * n; i++) {
        ans[i][colEnd] = x++;
      }
      colEnd--;

      // right to left
      // need to ensure -> and <- are in different rows
      if (rowBegin <= rowEnd) {
        for (int j = colEnd; j >= colBegin && x <= n * n; j--) {
          ans[rowEnd][j] = x++;
        }
        rowEnd--;
      }

      // bottom to top
      // need to ensure down and up are in various columns
      if (colBegin <= colEnd) {
        for (int i = rowEnd; i >= rowBegin && x <= n * n; i--) {
          ans[i][colBegin] = x++;
        }
        colBegin++;
      }
    }

    return ans;
  }
};
