// https://leetcode.com/problems/find-unique-binary-string/description/?
// 1. backtracking to generate all possible binary representation of n length
class Solution {
public:
  string ans;

  // return bool to indicate if we find the ans or not
  bool backtracking(string tmp, unordered_map<string, bool> &mp, int n) {
    // recursion, when to return
    if (tmp.length() == n) {
      // if this representation doesn't exist yet, we find the ans
      if (mp.find(tmp) == mp.end()) {
        ans = tmp;
        return true;
      }

      return false;
    }

    // main logic
    // this position can either be 0 / 1
    for (int i = 0; i <= 1; i++) {
      // 1. pick the current 0 / 1
      tmp += to_string(i);
      // if can find the ans by filling it with this current digit
      if (backtracking(tmp, mp, n))
        return true;

      // 2. don't pick 0, would automatically pick 1 in the next loop
      tmp.pop_back();
    }

    return false;
  }

  string findDifferentBinaryString(vector<string> &nums) {
    // record if a binary representation exists
    unordered_map<string, bool> mp;
    // fill in the map
    for (auto i : nums) {
      mp[i] = true;
    }

    string tmp = "";
    int n = nums[0].length();
    backtracking(tmp, mp, n);

    return ans;
  }
};

// 2. as the length of the binary representation is fixed, so the range is fixed
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
