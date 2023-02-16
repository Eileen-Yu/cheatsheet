// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int beg = 0, end = n - 1, p = 0, k = 1; // p:tempPtr, k: 0~n-1
    while (beg < end) {
      // left to right
      p = beg;
      while (p < end) { // the corner is to be dealt in the next loop
        ans[beg][p++] = k++;
      }

      // top to bottom
      p = beg;
      while (p < end) {
        ans[p++][end] = k++;
      }

      // right to left
      p = end;
      while (p > beg) {
        ans[end][p--] = k++;
      }

      // bottom to top
      p = end;
      while (p > beg) {
        ans[p--][beg] = k++;
      }

      beg++;
      end--;
    }

    // the middle one
    if (beg == end)
      ans[beg][end] = k;
    return ans;
  }
};
