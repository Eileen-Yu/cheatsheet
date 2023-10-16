// https://leetcode.com/problems/rotate-image/submissions/
// fix steps to rotate a matrix:
// 1. transpose the matrix
// 2. reverse the columns
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // 1. transpose the matrix
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // 2. reverse the columns
    for (int i = 0; i < n; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};
