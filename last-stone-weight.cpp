// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    int weight = 0;
    make_heap(stones.begin(), stones.end());
    int m1, m2;

    while (stones.size() >= 2) {
      m1 = stones.front();
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();

      m2 = stones.front();
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();

      if (m1 != m2) {
        int gap = m1 - m2;
        stones.push_back(gap);
        push_heap(stones.begin(), stones.end());
      }
    }

    if (stones.empty())
      return 0;
    return stones[0];
  }
};
