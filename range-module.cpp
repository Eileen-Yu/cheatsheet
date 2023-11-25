// https://leetcode.com/problems/range-module
// 1. direct way: use hash table to mark if a num is tracked
// would TLE in some cases
class RangeModule {
public:
  // hash table:
  // idx: num, range [1, 10^9], 0 is base
  // value: true means tracked, false means untracked
  vector<bool> hash;

  RangeModule() {
    // init the hash table
    hash = vector<bool>(1e9 + 1, false);
  }

  void addRange(int left, int right) {
    for (int i = left; i < right; i++) {
      hash[i] = true;
    }
  }

  bool queryRange(int left, int right) {
    for (int i = left; i < right; i++) {
      // once there's any untracked num in the range [left, right)
      if (!hash[i])
        return false;
    }

    return true;
  }

  void removeRange(int left, int right) {
    for (int i = left; i < right; i++) {
      hash[i] = false;
    }
  }
};
