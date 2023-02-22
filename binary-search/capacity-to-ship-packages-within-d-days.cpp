// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// binary search:
// 1. get lowest & highest point
// 2. while loop(i < j / i <= j based on various cases)
// 3. get mid and do logic
class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int i = -1, j = 0;
    // get the lowest point (i) and highest point(j)
    for (auto weight : weights) {
      // lowest point is the maximum one of all weights
      i = max(i, weight);
      // highest point is the sum of all weights
      j += weight;
    }

    // binary search
    while (i < j) {
      // get the mid between i and j
      // mid is the attempt ans
      int mid = (i + j) / 2;
      // curWeight is the accumulated weight for 1 day
      int needDays = 1, curWeight = 0;

      // calculate the days needed in such case
      for (auto weight : weights) {
        // if overweight, need another day
        if (curWeight + weight > mid) {
          needDays++;
          curWeight = 0;
        }
        // if not, this item can be shipped in the same day
        curWeight += weight;
      }

      // need to add the weight limit of each shipment
      if (needDays > days)
        i = mid + 1;
      // may try less weight of 1 day
      else
        j = mid;
    }

    return i;
  }
};
