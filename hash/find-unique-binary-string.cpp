// https://leetcode.com/problems/find-unique-binary-string/description/?
// 1. as the length of the binary representation is fixed, so the range is fixed
// to [0, 2^n - 1] convert those binary to decimal, and use hash table to record
// if one exists
class Solution {
public:
  int binaryToDecimal(string n) {
    int ans = 0;
    // 2 ^ 0
    int base = 1;

    for (int i = n.length() - 1; i >= 0; i--) {
      // if the current position is '1'
      if (n[i] == '1')
        ans += base;
      // update base
      base *= 2;
    }

    return ans;
  }

  string findDifferentBinaryString(vector<string> &nums) {
    // length of each binary representation
    int n = nums[0].length();

    // decimal range should be [0, 2^n - 1]
    // idx: decimal representation, value: exist or not
    vector<bool> exist(pow(2, n), false);

    // loop each binary representation, convert them to decimal
    for (int i = 0; i < nums.size(); i++) {
      // mark this decimal as exist
      exist[binaryToDecimal(nums[i])] = true;
    }

    int ans;
    // find 1 num that's not exist
    for (int i = 0; i < exist.size(); i++) {
      if (exist[i] == false) {
        ans = i;
        break;
      }
    }

    // return it's binary representation
    // this would convert the decimal to its binary representation of 32 digits
    string tmp = bitset<32>(ans).to_string();
    // return exacly n digits
    return tmp.substr(32 - n);
  }
};
