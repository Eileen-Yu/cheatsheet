// https://leetcode.com/problems/single-number-ii/description/
// bit manipulation:
// e.g: [1,1,1,2,2,2,5]
//     1
//     1
//     1
//    10
//    10
//    10
// + 101
// --------
//   134
// %   3
// -----------
//   101   --> ans
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;

    // loop 32 bits, from least significant bit (LSB) to most significant
    // bit(MSB)
    for (int i = 0; i < 32; i++) {
      // add up all 1's at this bit position
      int sum = 0;

      for (auto n : nums) {
        // n >> i  moves the bit at position i to the least significant bit
        // position. n >> i & 1 extracts the digit(0/1) on the corresponding
        // position
        sum += n >> i & 1;
      }

      // if the sum can be divided by 3, means the single number doesn't
      // contribute to this position, so it would be 0 else, it would left 1,
      // which is part of the bits of the single number
      sum %= 3;
      // sum << i to move the bit back to its original position
      // OR operation to set the corresponding position in ans to 1/0
      // OR: as long as there is 1, set it to 1
      ans |= sum << i;
    }

    return ans;
  }
};
