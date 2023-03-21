// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
// key: the number of subarray is N*(N+1) / 2,
// where N is the number of elements
class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long countZero = 0;
    long long ans = 0;

    for (auto i : nums) {
      if (i == 0)
        countZero++;
      else {
        // calculate the subarray of consecutive 0's till here
        ans += (countZero * (countZero + 1)) / 2;
        // init to restart
        countZero = 0;
      }
    }

    // if there is left 0's not ended by non-0
    // e.g: [0,0,0,2,0,0]
    ans += (countZero * (countZero + 1)) / 2;

    return ans;
  }
};
