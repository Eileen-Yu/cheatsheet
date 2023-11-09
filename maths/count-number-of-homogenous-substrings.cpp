// https://leetcode.com/problems/count-number-of-homogenous-substrings
// maths: the number of hemogenous substring in a string, like "aaa" is n *
// (n+1) / 2 = 6 each time add an additional element, it would add `count`
// number e.g : For "a" : 1 For "aa": 3 (1 + 2) For "aaa": 6 (1 + 2 + 3)

// 1. each time add a new element, it will add `count` substrings
class Solution {
public:
  int countHomogenous(string s) {
    int mod = 1e9 + 7;
    // previous char
    char prev = s[0];
    int count = 0;
    int ans = 0;

    // loop each char in the string
    for (auto i : s) {
      // if the current char is the same with the previous char, count + 1
      // else, count = 1
      count = i == prev ? count + 1 : 1;
      // when a new char append the a homogenous string, will add `count` number
      // of homogenous substrings
      ans = (ans + count) % mod;
      // update prev char
      prev = i;
    }

    return ans;
  }
};

// 1. record the number of same chars in a substring
class Solution {
public:
  int countHomogenous(string s) {
    int mod = 1e9 + 7;
    int ans = 0;
    // record the number of consecutive same element
    long long count = 0;
    char last = s[0];

    for (auto i : s) {
      // if this element is the same with the last
      if (i == last) {
        count++;
        continue;
      }

      // else, if it's a new start
      // 1. add the previous part to the ans
      ans = (ans + (count * (count + 1)) / 2) % mod;
      // 2. update count
      count = 1;
      // 3. update last
      last = i;
    }

    // add the final part to the ans
    ans = (ans + (count * (count + 1)) / 2) % mod;

    return ans;
  }
};
