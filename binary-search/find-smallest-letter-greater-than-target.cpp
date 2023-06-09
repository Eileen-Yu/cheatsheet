// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int n = letters.size();
    // binary search
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (letters[mid] - 'a' <= target - 'a')
        l = mid + 1;
      else
        r = mid;
    }

    if (l == r && letters[l] - 'a' > target - 'a')
      return letters[l];

    return letters[0];
  }
};
