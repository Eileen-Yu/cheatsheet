// https://leetcode.com/problems/arithmetic-subarrays/
// construct the subarray + sort to check if an array can be rearranged to be
// arithmetic
class Solution {
public:
  // check if an arr is arithmetic after rearrange
  bool isArithmetic(vector<int> arr) {
    sort(arr.begin(), arr.end());

    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i])
        return false;
    }

    return true;
  }

  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
    int n = l.size();
    vector<bool> ans;

    // loop each subrange
    for (int i = 0; i < n; i++) {
      // construct the subarray
      vector<int> tmp =
          vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
      ans.push_back(isArithmetic(tmp));
    }

    return ans;
  }
};
