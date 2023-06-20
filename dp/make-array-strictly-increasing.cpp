// https://leetcode.com/problems/make-array-strictly-increasing/description/
// dp: memoization(recursion)
// for each element: try to replace / not replace it, then recurse for each
// and pick the smaller one for this position
// *use vector<unordered_map<int,int>> instead of vector<vector<int>> to
// implement the 2D array so as to find the key easily

class Solution {
public:
  // recursion for memoization
  int recursion(int cur, int left, vector<int> &arr1, vector<int> &arr2,
                vector<unordered_map<int, int>> &dp) {
    // when to return: already finish to check all the elements in arr1
    if (cur == arr1.size())
      return 0;

    // already filled up
    if (dp[cur].find(left) != dp[cur].end())
      return dp[cur][left];

    // exclude stores the # of ways for making array strictly
    // increasing when not replacing the current element

    // include stores the # of ways for making the array strictly
    // increasing after replacing the current element
    int exclude, include;
    // 1. if we exclude this cur element
    // really don't need to replace the current element
    if (arr1[cur] > left)
      // continue to check the next element in arr1
      exclude = recursion(cur + 1, arr1[cur], arr1, arr2, dp);
    else
      exclude =
          INT_MAX; // cannot really exclude, still need to replace cur element

    // 2. if we replace this cur element
    // find the idx of the first element in arr2 that is greater than the `left`
    int idx = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();
    // if not found such element
    if (idx == arr2.size())
      include = INT_MAX;
    // else, continue to check the next element in arr1 with the replaced new
    // element
    else
      include = recursion(cur + 1, arr2[idx], arr1, arr2, dp);

    // pick include / exclude for the cur element
    // 1. if not found a suitable one in arr2, can only accpet the `exclude`
    // case
    if (include == INT_MAX)
      dp[cur][left] = exclude;
    // 2. else, pick the smaller one
    else
      dp[cur][left] = min(exclude, include + 1);

    return dp[cur][left];
  }

  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    sort(arr2.begin(), arr2.end());
    // dp[i][j] represents the min operations to > `j` at idx `i` so as to make
    // the subarray arr1[0...i] strictly increasing i's range: 0 ~ 2000 use map
    // for find the key(j) easily
    vector<unordered_map<int, int>> dp(2001);
    int ans = recursion(0, INT_MIN, arr1, arr2, dp);

    // if no way to make it
    if (ans == INT_MAX)
      return -1;

    return ans;
  }
};
