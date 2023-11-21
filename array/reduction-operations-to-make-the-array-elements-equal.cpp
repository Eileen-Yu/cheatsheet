// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal
// sort first,
// each time meet a new num, needs to have operations on all previous elements
// to make them equal to the new num
// other problems to operate to make (part of) elements equal but use sliding
// window: https://leetcode.com/problems/frequency-of-the-most-frequent-element
class Solution {
public:
  int reductionOperations(vector<int> &nums) {
    // sort from big to small
    sort(nums.rbegin(), nums.rend());
    // count the number of elements till now
    int freq = 0;
    int ans = 0;

    // loop all elements except the last one, as it won't need any operation for
    // sure
    for (int i = 0; i < nums.size() - 1; i++) {
      freq++;

      // we'll meet a new element at the next step
      if (nums[i] != nums[i + 1]) {
        // so needs to make operation on all the previous elements till the
        // current one
        ans += freq;
      }
    }

    return ans;
  }
};
