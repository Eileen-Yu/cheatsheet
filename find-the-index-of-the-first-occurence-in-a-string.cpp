// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
//

// 1. sliding window
// continue compare until mismatch
// rollback to the next of last starting char
class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();

    // idx for loop haystack and needle
    int i = 0, j = 0;
    while (i < n) {
      if (haystack[i] == needle[j]) {
        // the next for loop would compare the next i and j
        i++;
        j++;
      } else { // reset i and j
        // start from the next idx of the prvious first match char
        i = i - j + 1;
        j = 0;
      }
      // if needle is looped over
      if (j == m)
        return i - j;
    }

    return -1;
  }
};

// 2. find all the position of all chars
// that the same with the first of needle
// as candidate,
// then try one by one
class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    // needle cannot be part of haystack
    if (n < m)
      return -1;

    vector<int> candidate;

    for (int i = 0; i < n; i++) {
      if (haystack[i] == needle[0])
        // possible starting point
        candidate.push_back(i);
    }

    for (auto elem : candidate) {
      // idx to loop haystack
      int i = elem;
      // idx to loop needle
      int j = 0;
      // start to match every char of needle
      while (haystack[i] == needle[j] && j < m) {
        i++;
        j++;
      }

      // if needle is looped over
      if (j == m)
        return elem;
      // else, try the next candidate
    }

    return -1;
  }
};
