// https://leetcode.com/problems/jump-game-iv/description/
// BFS
// We don't care how to reach
// but just need the minimum steps
class Solution {
public:
  int minJumps(vector<int> &arr) {
    int n = arr.size();
    if (n == 1)
      return 0;

    // record the element : indexes
    // e.g: 100: [0,4]
    //      -23: [1,2]
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      mp[arr[i]].push_back(i);
    }

    // record if a specific idx has been visited
    vector<bool> visited(n, false);
    // for BFS
    queue<int> q;

    // start from idx 0
    q.push(0);
    visited[0] = true;
    // the step needed to reach the end
    int step = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int curIdx = q.front();
        q.pop();

        // if already reach the end
        if (curIdx == n - 1)
          return step;

        // get all possible next idx
        // 1. arr[i] == arr[j] && i != j
        vector<int> &jumpNextIdx = mp[arr[curIdx]];
        // 2. i+1
        jumpNextIdx.push_back(curIdx + 1);
        // 3. i-1
        jumpNextIdx.push_back(curIdx - 1);

        for (auto i : jumpNextIdx) {
          // ensure not exceed the boundary && not visited
          if (i >= 0 && i < n && visited[i] == false) {
            q.push(i);
            // mark as visited
            visited[i] = true;
          }
        }

        // clear the data of curIdx, prepare for the next Idx
        jumpNextIdx.clear();
      }
      // for every level
      step++;
    }

    // cannot jump to reach the end
    return -1;
  }
};
