// https://leetcode.com/problems/sign-of-the-product-of-an-array/description/
// math
class Solution {
public:
  int arraySign(vector<int> &nums) {
    // count number of negative elements
    int count = 0;
    for (auto i : nums) {
      if (i == 0)
        return 0;
      if (i < 0)
        count++;
    }

    if (count % 2 == 1)
      return -1;
    return 1;
  }
};
