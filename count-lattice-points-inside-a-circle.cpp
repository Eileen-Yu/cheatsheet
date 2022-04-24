// https://leetcode.com/problems/count-lattice-points-inside-a-circle/
//
class Solution {
public:
  int countLatticePoints(vector<vector<int>> &circles) {
    set<pair<int, int>> st;
    for (int i = 0; i < circles.size(); i++) {
      int x = circles[i][0];
      int y = circles[i][1];
      int r = circles[i][2];

      for (int a = -r; a <= r; a++) { // for a circumscribed square
        for (int b = -r; b <= r; b++) {
          if (a * a + b * b <= r * r) {
            st.insert({x + a, y + b});
          }
        }
      }
    }
    return st.size();
  }
};
