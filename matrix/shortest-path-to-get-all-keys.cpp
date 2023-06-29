// https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
// shortest path + matrix = BFS
// To record the lock-key pair, and the key we collected: bit manipulation
class Solution {
public:
  int shortestPathAllKeys(vector<string> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    // assign a unique bit value to each key, as a position mark
    // key: key, value: bit
    // use 1 << mp[pos] to uniquely represent a key in bit form
    unordered_map<char, int> mp;
    // the total number of bits needed to represent all keys
    int bits = 0;

    // {i, j, keystate}
    vector<int> start;
    // fill in the mp(record the key positions) and start
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // if it's a lowercase, means it's a key
        // each time bits++ would be a unique one
        if (islower(grid[i][j]))
          mp[grid[i][j]] = bits++;
        // if it's the starting point
        if (grid[i][j] == '@')
          // 0 means no key state
          start = {i, j, 0};
      }
    }

    // bit manipulation: left shift
    // represent all keys have already been collected(11..1)
    int maskend = (1 << bits) - 1;
    // record if the position and key combination has been visited
    vector<vector<vector<bool>>> memo(
        m, vector<vector<bool>>(n, vector<bool>(maskend, false)));

    // for BFS
    queue<vector<int>> q;
    q.push(start);

    int ans = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int row = q.front()[0];
        int col = q.front()[1];
        // record the keys we already collected
        int keystate = q.front()[2];
        q.pop();

        // check if out of bounds
        if (row < 0 || row >= m || col < 0 || col >= n)
          continue;

        // if this position and key combination has been visited
        if (memo[row][col][keystate])
          continue;
        // else, mark it as visited
        memo[row][col][keystate] = true;
        char cur = grid[row][col];

        // check if it's a wall
        if (cur == '#')
          continue;

        // check if it's a lock but we don't have a key
        if (isupper(cur)) {
          // bit manipulation: mask
          // if bitwse & == 0, means we don't have corresponding key now
          if ((keystate & (1 << mp[tolower(cur)])) == 0)
            continue;
        }

        // check if it's a key, we need to collect it and add it to keystate
        // 1 << mp[cur] creates a binary number with a 1 at the position
        // representing the key and 0s everywhere else. bitwise OR: If the key
        // is not already in keystate, it adds it. If the key is already in
        // form, form stays the same.
        if (islower(cur))
          keystate = keystate | (1 << mp[cur]);

        // if all keys have been collected, return the ans
        if (keystate == maskend)
          return ans;

        // add the next 4 positions to the queue
        q.push({row + 1, col, keystate});
        q.push({row - 1, col, keystate});
        q.push({row, col + 1, keystate});
        q.push({row, col - 1, keystate});
      }
      // add up the step
      ans++;
    }

    return -1;
  }
};
