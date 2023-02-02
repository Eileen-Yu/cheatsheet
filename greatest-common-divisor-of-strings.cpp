// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
//
//
class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    // if str1 and str2 have gcd, then must have:
    // str1 + str2 == str2 + str1
    // proof: str1 = mGCD, str2 = nGCD
    // str1 + str2 =(m+n)GCD= str2 + str1
    // gcd(): compute the greatest common devisor of 2 integers
    return str1 + str2 == str2 + str1
               ? str1.substr(0, gcd(str1.length(), str2.length()))
               : "";
  }
};
