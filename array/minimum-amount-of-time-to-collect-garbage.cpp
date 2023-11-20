// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
// 1. 3 pointers to record the position of each truck
class Solution {
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    // idx to record the position of each truck
    int g = 0, p = 0, m = 0;
    int ans = 0;

    // loop each house
    for (int i = 0; i < garbage.size(); i++) {
      // each unit take 1 min
      ans += garbage[i].length();

      // loop each type of this house
      for (auto j : garbage[i]) {
        // calculate the distance for each truck to reach this house
        if (j == 'G') {
          for (g; g < i; g++)
            ans += travel[g];
        }

        else if (j == 'P') {
          for (p; p < i; p++)
            ans += travel[p];
        }

        else if (j == 'M') {
          for (m; m < i; m++)
            ans += travel[m];
        }
      }
    }

    return ans;
  }
};
