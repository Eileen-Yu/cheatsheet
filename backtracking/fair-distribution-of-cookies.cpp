// https://leetcode.com/problems/fair-distribution-of-cookies/description/
// dp: backtracking(recursion)
// try to add each bag to each pile at one time, and continue to recurse
class Solution {
public:
  int ans = INT_MAX;
  // backtracking: recursion
  void recursion(int idx, vector<int> &cookies, int k, vector<int> &piles) {
    int n = cookies.size();

    // if already distributed all cookies, need to return the recursion
    // need to check and update the ans
    if (idx == n) {
      // to get the max among the piles
      int comp = INT_MIN;
      for (auto i : piles) {
        comp = max(comp, i);
      }
      // update the ans
      ans = min(ans, comp);
      return;
    }

    // else, try to add this big to each pile (back tracking)
    for (int i = 0; i < k; i++) {
      // 1. if add to this pile
      piles[i] += cookies[idx];
      recursion(idx + 1, cookies, k, piles);
      // 2. if skip and add it to the next pile
      piles[i] -= cookies[idx];
    }
  }

  int distributeCookies(vector<int> &cookies, int k) {
    // record the number of cookies in each pile
    vector<int> piles(k, 0);
    recursion(0, cookies, k, piles);
    return ans;
  }
};
