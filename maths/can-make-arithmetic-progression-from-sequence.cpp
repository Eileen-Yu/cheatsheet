// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/
// sort first
class Solution {
public:
  bool canMakeArithmeticProgression(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n - 2; i++) {
      if (arr[i + 1] - arr[i] != arr[i + 2] - arr[i + 1])
        return false;
    }

    return true;
  }
};
