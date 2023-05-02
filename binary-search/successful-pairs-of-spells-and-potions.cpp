// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

// binary search to avoid n^2
class Solution {
public:
  // use binary search to find number of potions cannot meet the success
  // criteria return count = l
  int binarySearch(int l, int r, long spell, vector<int> &potions,
                   long long target) {
    while (l <= r) {
      int mid = l + (r - l) / 2;
      long long tmp = potions[mid] * spell;
      if (tmp >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }

    return l;
  }

  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    long long n = spells.size(), m = potions.size();
    // sort first to apply binarySearch
    sort(potions.begin(), potions.end());
    vector<int> ans;

    for (auto i : spells) {
      int countNotMeet = binarySearch(0, m - 1, i, potions, success);
      ans.push_back(m - countNotMeet);
    }

    return ans;
  }
};
