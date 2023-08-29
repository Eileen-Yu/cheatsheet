// https://leetcode.com/problems/minimum-penalty-for-a-shop/
// 1. plain version, O(n^2), would TLE
class Solution {
public:
  int bestClosingTime(string customers) {
    int n = customers.size();
    int penalty = INT_MAX, ans = INT_MAX;

    // try to close the shop at 0th ~ nth hour
    for (int i = 0; i <= n; i++) {
      // penalty if close at i-th hour
      int tmp = 0;

      // loop each hour's customer
      for (int j = 0; j < n; j++) {
        // if open but no customer
        if (customers[j] == 'N' && j < i)
          tmp++;
        // if close but customer show
        else if (customers[j] == 'Y' && j >= i)
          tmp++;
      }

      if (tmp < penalty) {
        // record the minimum penalty until now
        penalty = tmp;
        // record the corresponding hour
        ans = i;
      }
    }

    return ans;
  }
};
