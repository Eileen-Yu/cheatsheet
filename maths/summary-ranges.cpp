// https://leetcode.com/problems/summary-ranges/description/
// array
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> ans;
    int i = 0, j = 1;
    int n = nums.size();
    // special cases
    if (n == 0)
      return ans;
    if (n == 1)
      return {to_string(nums[0])};

    // this also include the case that only one number left
    while (i < n && j <= n) {
      string tmp = "";
      long long int start = nums[i];
      while (j < n && static_cast<long long>(nums[j]) -
                              static_cast<long long>(nums[j - 1]) ==
                          1) {
        j++;
      }

      // if only a single number
      if (j - 1 == i)
        tmp = to_string(nums[i]);
      // if it's a range
      else
        tmp = to_string(start) + "->" + to_string(nums[j - 1]);
      ans.push_back(tmp);

      // a new start
      i = j;
      j = i + 1;
    }

    return ans;
  }
};
