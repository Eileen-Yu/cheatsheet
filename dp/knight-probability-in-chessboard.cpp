// https://leetcode.com/problems/knight-probability-in-chessboard/
// 1. plain recursion, would TLE in some cases due to duplicated calculation
class Solution {
public:
  // count the number of case that the chess can remain on the board
  double count = 0;
  // 8 possible directions
  vector<pair<int, int>> dir = {{1, -2}, {2, -1}, {2, 1},   {1, 2},
                                {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

  void recursion(int i, int j, int n, int k, int step) {
    // if out of boundary
    if (i < 0 || j < 0 || i >= n || j >= n)
      return;
    // if reach valid step number and still inside the board
    if (step == k) {
      count++;
      return;
    }

    for (auto d : dir) {
      recursion(i + d.first, j + d.second, n, k, step + 1);
    }
  }

  double knightProbability(int n, int k, int row, int column) {
    if (k == 0)
      return 1;

    recursion(row, column, n, k, 0);
    return count / pow(8, k);
  }
};
