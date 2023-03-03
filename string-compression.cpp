// https://leetcode.com/problems/string-compression/description/
//
class Solution {
public:
  int compress(vector<char> &chars) {
    int n = chars.size();
    if (n == 1)
      return 1;

    // two pointers
    int i = 0, j = 0;
    int count;

    while (i < n) {
      // every time meet the new element
      count = 1;
      while (i < n - 1 && chars[i] == chars[i + 1]) {
        count++;
        i++;
      } // when the loop ends, i points to the last consequent element

      // make the start
      chars[j] = chars[i];
      j++;
      // ready for the next consequecy
      i++;

      if (count > 1) {
        // convert count to string
        string countStr = to_string(count);

        // for every `digit`
        for (char c : countStr) {
          chars[j] = c;
          j++;
        }
      }
    }
    // actually point to j-1
    return j;
  }
};
