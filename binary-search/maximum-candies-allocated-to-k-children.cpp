// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
// binary search
class Solution {
public:
  // return the number of piles after split as we assume each pile at least
  // contain x candies
  long long getPiles(int x, vector<int> &candies) {
    long long piles = 0;
    for (auto i : candies) {
      piles += i / x;
    }

    return piles;
  }

  int maximumCandies(vector<int> &candies, long long k) {
    int ans = 0;

    // binary search, try the mid as the number of candies in one pile
    int l = 1, r = 1e7;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      long long piles = getPiles(mid, candies);

      // ensure one child can get one pile
      if (piles >= k) {
        // update ans
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }

    return ans;
  }
};
