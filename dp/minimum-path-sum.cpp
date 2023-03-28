// https://leetcode.com/problems/minimum-path-sum/description/
// DP : To calculate the minimum path sum to reach a cell (i, j),
// we can take the minimum of the minimum path sum to reach the cell above (i-1,
// j) and the cell to the left (i, j-1), and add it to the value of the current
// cell.
//

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();    // row
    int n = grid[0].size(); // column
    // first deal with digits on the edge
    // for digits in the first column, they min sum can only be from the top one
    for (int i = 1; i < m; i++) {
      grid[i][0] += grid[i - 1][0];
    }

    // for digits in the first row, they min sum can only be from the left one
    for (int j = 1; j < n; j++) {
      grid[0][j] += grid[0][j - 1];
    }

    // for digits in the middle, take the minimum between top / left
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
      }
    }

    // the last element would be the minimum sum
    return grid[m - 1][n - 1];
  }
};
