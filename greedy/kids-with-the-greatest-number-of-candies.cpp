// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
//
// greedy
class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    // find the maximum in the original array
    // alternatively may use sort, but this seems more elegant
    int mx = INT_MIN;
    for (auto i : candies) {
      mx = max(mx, i);
    }

    vector<bool> ans;

    for (auto i : candies) {
      if (i + extraCandies >= mx) {
        ans.push_back(true);
      } else
        ans.push_back(false);
    }

    return ans;
  }
};
