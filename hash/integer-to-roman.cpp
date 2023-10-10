// https://leetcode.com/problems/integer-to-roman/description/
// hash map to record & search representation {int, string}
// loop the map from big to small, each time try to match the biggest
// representation
class Solution {
public:
  string intToRoman(int num) {
    // integer, roman representation
    map<int, string> mp;
    mp[1] = "I";
    mp[4] = "IV";
    mp[5] = "V";
    mp[9] = "IX";
    mp[10] = "X";
    mp[40] = "XL";
    mp[50] = "L";
    mp[90] = "XC";
    mp[100] = "C";
    mp[400] = "CD";
    mp[500] = "D";
    mp[900] = "CM";
    mp[1000] = "M";

    string ans = "";

    // while there are remains to be represented
    while (num) {
      // loop the map in the reverse order(from big to small)
      // to avoid wrong cases like "IIIIIIIIII...."
      for (auto i = mp.rbegin(); i != mp.rend(); i++) {
        // if the remaining can be represents by this roman symbol
        if (num >= i->first) {
          ans += i->second;
          // update the remaining
          num -= i->first;
          break;
        }
      }
    }

    return ans;
  }
};
