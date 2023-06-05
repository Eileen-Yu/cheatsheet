// https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
// maths: y = kx+b
// k = (y2-y1) / (x2-x1);
// b = y1 - k*x1
class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &co) {
    int n = co.size();
    // check if all points satisfy x = a
    int i;
    for (i = 0; i < n - 1; i++) {
      if (co[i + 1][0] != co[i][0])
        break;
    }
    // if all points satisfy x = a
    if (i == n - 1)
      return true;

    int y2 = co[1][1], y1 = co[0][1];
    int x2 = co[1][0], x1 = co[0][0];
    // slope k
    double k;
    // can ensure x2-x1 != 0
    if (x2 - x1 != 0)
      k = (double)(y2 - y1) / (x2 - x1);
    double b = y1 - k * x1;

    // check if all points satisfy y = kx+b
    for (int j = 1; j < n; j++) {
      int x = co[j][0], y = co[j][1];
      if (y != k * x + b)
        return false;
    }

    return true;
  }
};
