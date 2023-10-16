// https://leetcode.com/problems/pascals-triangle-ii/description/
// 1. record the whole triangle
// as each row is not the same length, need to fill in row by row
// key formula: row[i] = prevRow[i-1] + prevRow[i]
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> triangle;
    // the first row
    triangle.push_back({1});

    // the i-th row
    for (int i = 1; i <= rowIndex; i++) {
      // there are i+1 elements in the i-th row
      vector<int> row(i + 1);
      // the first and last must be 1
      row[0] = 1;
      row[i] = 1;

      // fill other middle cells in this row
      for (int j = 1; j < i; j++) {
        row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }

      // put this row into the triangle
      triangle.push_back(row);
    }

    return triangle[rowIndex];
  }
};
