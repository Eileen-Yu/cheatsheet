// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
// similar idea to prefix sum
// the reverse of ^ is still ^ (A ^ B = C, C ^ B = A)

// 1. use prev to store all previous accumulation result
class Solution {
public:
  vector<int> findArray(vector<int> &pref) {
    // the accumulation of the previous elements: pref[0] ^ pref[1] ^ pref[2]...
    int prev = pref[0];

    // loop from the second element
    for (int i = 1; i < pref.size(); i++) {
      // directly change on the original vector
      pref[i] = prev ^ pref[i];
      prev = prev ^ pref[i];
    }

    return pref;
  }
};

// 2. arr[i] = pref[i] ^ pref[i-1]
class Solution {
public:
  vector<int> findArray(vector<int> &pref) {
    // the first one don't need change
    for (int i = pref.size() - 1; i > 0; i--) {
      // directly change on pref vector
      pref[i] = pref[i] ^ pref[i - 1];
    }

    return pref;
  }
};
