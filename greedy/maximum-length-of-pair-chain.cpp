// https://leetcode.com/problems/maximum-length-of-pair-chain/description/
// use greedy to opitimize in one pass
// similar to:
// https://leetcode.com/problems/non-overlapping-intervals/description/
// *how to sort the original array is important in this greedy

class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    // sort all the pairs by the second elementfrom small to big
    // this is because each time we want to extend with a smaller end, as as to
    // get more pairs
    sort(
        pairs.begin(), pairs.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    // at least the first pair can be the ans (as n >= 1 is confirmed)
    int ans = 1;

    // record the last end, start from the first pair end
    int end = pairs[0][1];
    int n = pairs.size();

    // start from the second pair
    for (int i = 1; i < n; i++) {
      // if this start > last end, we can safely append this pair
      // and because the pairs have been sorted by the end,
      // this ensures each time we pick a smaller end to expect for a longer
      // chain
      if (pairs[i][0] > end) {
        ans++;
        // update the end
        end = pairs[i][1];
      }
      // otherwise, we skip this pair, continue to check the next
    }

    return ans;
  }
};
