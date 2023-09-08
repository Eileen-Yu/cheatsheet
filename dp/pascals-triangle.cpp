// https://leetcode.com/problems/pascals-triangle/description/
// Pascal Triangle: dp tabulation
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    // base case: the first row
    ans.push_back({1});
    if (numRows == 1)
      return ans;

    // the other rows
    for (int i = 1; i < numRows; i++) {
      // init the row, the 1 would automatically fill in the first & last
      // element
      vector<int> row(i + 1, 1);

      // fill in the middle elements
      for (int j = 1; j < i; j++) {
        // Pascal triangle's feature: key formula
        row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }

      ans.push_back(row);
    }

    return ans;
  }
};
