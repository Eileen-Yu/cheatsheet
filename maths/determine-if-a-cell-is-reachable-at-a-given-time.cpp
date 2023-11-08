// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time
// maths!! instead of BFS expansion
// because we can move diagonally & revisit each cell
class Solution {
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int xDist = abs(sx - fx);
    int yDist = abs(sy - fy);

    // edge case: when the start & end cell is not the same, then it won't
    // succeed if t == 1 (beacause each time must move to an adjancent cell)
    if (xDist == 0 && yDist == 0) {
      if (t != 1)
        return true;
      return false;
    }

    // because we can move diagonally and revisit
    // if t is big, just move around the target until t == 1
    return xDist <= t && yDist <= t;
  }
};
