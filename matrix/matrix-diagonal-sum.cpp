// https://leetcode.com/problems/matrix-diagonal-sum/description/

// matrix = 2 dimentional vector
class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int n = mat.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
      int j = i;
      sum += mat[i][j];
      sum += mat[i][n - j - 1];
    }

    if (n % 2 == 1) {
      // the mid one has been added twice
      sum -= mat[n / 2][n / 2];
    }

    return sum;
  }
};
