// https://leetcode.com/problems/spiral-matrix/description/
// matrix simulation
// every time we loop a row / column, narrow the range through rowBegin, rowEnd,
// colBegin, colEnd

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int rowBegin = 0, rowEnd = m - 1;
    int colBegin = 0, colEnd = n - 1;
    vector<int> ans;

    // every time after a loop, we narrow the begin / end
    // the center of the matrix's postion must be (rowBegin = rowEnd, colBegin =
    // colEnd)
    while (rowBegin <= rowEnd && colBegin <= colEnd) {
      // left to right

      for (int j = colBegin; j <= colEnd; j++) {
        ans.push_back(matrix[rowBegin][j]);
      }
      // already loop this row, update the boundary
      rowBegin++;

      // top to bottom
      for (int i = rowBegin; i <= rowEnd; i++) {
        ans.push_back(matrix[i][colEnd]);
      }
      colEnd--;

      // right to left
      // only when there ramains various rows, do this right to left
      if (rowBegin <= rowEnd) {
        for (int j = colEnd; j >= colBegin; j--) {
          ans.push_back(matrix[rowEnd][j]);
        }
        rowEnd--;
      }

      // bottom to top
      // only when there remains various columns, do this bottom to top
      if (colBegin <= colEnd) {
        for (int i = rowEnd; i >= rowBegin; i--) {
          ans.push_back(matrix[i][colBegin]);
        }
        colBegin++;
      }
    }

    return ans;
  }
};
