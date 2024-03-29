// https://leetcode.com/problems/roman-to-integer/description/
// 1. hash map to record each roman represents what integer
class Solution {
public:
  int romanToInt(string s) {
    // record each roman represents which integer
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;
    int n = s.length();
    // loop each char in the string
    for (int i = 0; i < n; i++) {
      // usually roman numerals are from largest to smallest from left to right
      // except for special cases, which needs to substract this int
      if (i + 1 < n && mp[s[i]] < mp[s[i + 1]])
        ans -= mp[s[i]];

      // else, generally needs to add this int
      else
        ans += mp[s[i]];
    }

    return ans;
  }
};

// 2. most direct: else if to consider the special cases
class Solution {
public:
  int romanToInt(string s) {
    int ans = 0;
    int n = s.length();

    // loop each char in the string
    for (int i = 0; i < n; i++) {
      if (s[i] == 'I') {
        if (i + 1 < n && s[i + 1] == 'V') {
          ans += 4;
          // skip the next char
          i++;
        }

        else if (i + 1 < n && s[i + 1] == 'X') {
          ans += 9;
          i++;
        }

        else
          ans += 1;
      }

      else if (s[i] == 'V')
        ans += 5;
      else if (s[i] == 'X') {
        if (i + 1 < n && s[i + 1] == 'L') {
          ans += 40;
          // skip the next char
          i++;
        }

        else if (i + 1 < n && s[i + 1] == 'C') {
          ans += 90;
          i++;
        }

        else
          ans += 10;
      }

      else if (s[i] == 'L')
        ans += 50;
      else if (s[i] == 'C') {
        if (i + 1 < n && s[i + 1] == 'D') {
          ans += 400;
          // skip the next char
          i++;
        }

        else if (i + 1 < n && s[i + 1] == 'M') {
          ans += 900;
          i++;
        }

        else
          ans += 100;
      }

      else if (s[i] == 'D')
        ans += 500;
      else if (s[i] == 'M')
        ans += 1000;
    }

    return ans;
  }
};
