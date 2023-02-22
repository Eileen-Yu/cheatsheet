// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
//
// Binary Search
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    // if all the element is doubled is expected,
    // if the cur position is odd,
    // then the other in the pair should be in the even position
    // vice versa

    // in case mid is the ans, so j = end - 2;
    int i = 0, j = nums.size() - 2;
    while (i <= j) {
      int mid = (i + j) / 2;
      // ^ is bit manipulation, to check the other one in the pair
      // if matched, then the `mismatch` must appear in the next.
      if (nums[mid] == nums[mid ^ 1])
        i = mid + 1;
      // if not matched, then there must have been `mismatch`
      else
        j = mid - 1;
    }

    return nums[i];
  }
};

// More about ^
// it can check the only single element among all the `couples`
//
// e.g [1,2,3,3,2,1,5]
// for (int i = 1; i < n; i++) {
//   A[0] ^= A[i];
// }
// return A[0];
