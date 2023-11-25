// https://leetcode.com/problems/range-module
// 1. manage adding / removing the intervals by vector<pair<int,int>>,
// search by binary search
// be careful about [left, right) !!
class RangeModule {
public:
  // store each tracked intervals
  vector<pair<int, int>> intervals;

  RangeModule() {}

  void addRange(int left, int right) {
    // generate the new pair vector after inserting the range
    vector<pair<int, int>> tmp;
    int n = intervals.size();

    // loop each existing intervals
    for (int i = 0; i <= n; i++) {
      // if the new range is:
      // 1. the largest (already looped all existing ranges, so i <= n)
      // 2. exacly between 2 existing ranges
      if (i == n || intervals[i].first > right) {
        // 1. insert the new range
        tmp.push_back({left, right});
        // 2. append the right remaining old ranges to the tmp
        while (i < n)
          tmp.push_back(intervals[i++]);
      }

      // append the left remaining old ranges to the tmp
      else if (intervals[i].second < left) {
        tmp.push_back(intervals[i]);
      }

      // else if there's overlap,
      // e.g: [15, 17), [17, 20) --> [15, 20)
      else {
        // generate the new interval
        left = min(left, intervals[i].first);
        right = max(right, intervals[i].second);
      }
    }

    // update the intervals with the new tmp
    swap(intervals, tmp);
  }

  bool queryRange(int left, int right) {
    int n = intervals.size();
    // binary search
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      // 1. needs to make mid smaller (right cannot be reached, so >= right)
      if (intervals[mid].first >= right)
        r = mid - 1;
      // 2. needs to make mid bigger (left can be reached, so < left)
      else if (intervals[mid].second < left)
        l = mid + 1;
      // 3. the queryRange may be in the current mid interval
      else
        return intervals[mid].first <= left && intervals[mid].second >= right;
    }

    // no such existing range
    return false;
  }

  void removeRange(int left, int right) {
    // generate the new pair vector after removing the range
    vector<pair<int, int>> tmp;
    int n = intervals.size();

    // loop each existing intervals
    for (int i = 0; i < n; i++) {
      // if there's non-overlap, namely:
      // 1. if this current interval's end < target (second cannot be reached,
      // so <= left)
      // 2. OR if current intervals'start > target  (right cannot be reached, so
      // >= right)
      if (intervals[i].second <= left || intervals[i].first >= right)
        tmp.push_back(intervals[i]);

      // else if there's overlap
      else {
        // left is unreachable after removing
        if (intervals[i].first < left)
          tmp.push_back({intervals[i].first, left});
        // right is reachable after removing
        if (intervals[i].second > right)
          tmp.push_back({right, intervals[i].second});
      }
    }

    // update the intervals with the new tmp
    swap(intervals, tmp);
  }
};

// 2. direct way: use hash table to mark if a num is tracked
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
