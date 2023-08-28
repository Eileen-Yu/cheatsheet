// https://leetcode.com/problems/maximum-length-of-pair-chain/description/
// use greedy to opitimize in one pass
// similar to:
// https://leetcode.com/problems/non-overlapping-intervals/description/
// *how to sort the original array is important in this greedy

// 1. recommend: greedy
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

// 2. use back-tracking(recursion), but would TLE, need optimization(such as
// memoization)
class Solution {
public:
  // the first pair must be one
  int ans = 1;

  void recursion(vector<vector<int>> &pairs, int idx, int end, int tmp) {
    int n = pairs.size();
    // when to return
    if (idx >= n) {
      // update the ans
      ans = max(ans, tmp);
      return;
    }

    // 1. if the current pair can extend the chain
    if (pairs[idx][0] > end) {
      // update the end & tmp length
      recursion(pairs, idx + 1, pairs[idx][1], tmp + 1);
    }

    // 2. else if there is overlaping
    else {
      // 2.1 if take this pair as the new start,
      // update length(tmp) to 1
      recursion(pairs, idx + 1, pairs[idx][1], 1);
      //
      // 2.2 if not take this pair, the end & tmp remains
      recursion(pairs, idx + 1, end, tmp);
    }
  }

  int findLongestChain(vector<vector<int>> &pairs) {
    // sort all the pairs by the start from small to big
    sort(
        pairs.begin(), pairs.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    // record the last ending, start from pairs[0][1];
    int end = pairs[0][1];

    // start from the second one
    recursion(pairs, 1, end, 1);

    return ans;
  }
};
