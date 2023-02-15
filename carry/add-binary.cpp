// https://leetcode.com/problems/add-binary/description/

// maths principle:
// x, y is the two digit of certain position for add
// the digit in the answer of that certain position = (x+y+carry) % 2;
// the carry = (x+y+carry) / 2
class Solution {
public:
  string addBinary(string a, string b) {
    string ans = "";
    // carry
    int carry = 0;
    // index for loop
    int i = 0;
    // length of stirng a, b
    int la = a.size(), lb = b.size();

    // if there's still digit to deal with
    while (i < la || i < lb || carry) {
      // the digit from string a
      int x = 0;
      // from the ones, tens, hundreds...
      if (i < la && a[la - i - 1] == '1')
        x = 1;
      // the digit from string b
      int y = 0;
      if (i < lb && b[lb - i - 1] == '1')
        y = 1;
      // calculate this certain digit in the ans
      // original ans is lower digits, should be put on the right
      ans = to_string((x + y + carry) % 2) + ans;
      carry = (x + y + carry) / 2;

      i++;
    }

    return ans;
  }
};
