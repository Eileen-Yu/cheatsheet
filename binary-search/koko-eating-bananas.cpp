// https://leetcode.com/problems/koko-eating-bananas/description/?page=4&languageTags=cpp
//
// Binary Search
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      // sort(piles.begin(), piles.end());
      // int n = piles.size();
      int low = 1;
      int high = INT_MAX;

      while (low <= high) {
        int mid = low + (high - low) / 2;
        int tmp = 0;
        for (auto i : piles) {
          // round up the needed time
          // cannot directly + 1!!
          // because in such case there would be problem : 30 / 30 + 1
          tmp += (i + mid - 1) / mid;
        }
        // means we may be slower
        if (tmp <= h) 
          high = mid - 1;
        // need to be faster
        else if (tmp > h)
          low = mid + 1;
      }

      return low;
    }
};
