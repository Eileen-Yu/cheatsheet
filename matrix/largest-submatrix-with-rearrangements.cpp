// https://leetcode.com/problems/largest-submatrix-with-rearrangements
// key formula: area = height * width
// 1. first, loop each cell to record each cell's height
// 2. second, loop each row to sort each height from small to big
// 3. calculate the area by height * width, get the maximum
class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    // loop each cell from the second row to calculate heights for each column
    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // height + 1
        if (matrix[i][j] == 1)
          matrix[i][j] += matrix[i - 1][j];
      }
    }

    int ans = INT_MIN;
    // sort each row
    for (int i = 0; i < m; i++) {
      // sorting enables the creation of heights from right to left in
      // descending order this ensure the right side of this cell is valid (1,
      // not 0) may not start from left bottom, but doesn't matter (as we can
      // switch columns)
      sort(matrix[i].begin(), matrix[i].end());

      // loop each sorted heights
      for (int j = 0; j < n; j++) {
        int height = matrix[i][j];
        int width = n - j;

        // update ans if necessary to get the max
        ans = max(ans, height * width);
      }
    }

    return ans;
  }
};
