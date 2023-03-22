// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
//
// Because no matter how we travse,
// there must be a path from start(1) to end(n)
// so we can either choose BFS / DFS
// both approaches would visit all nodes connected with the start
//
// 1. BFS
class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    // adjacency matrix
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>({}));
    for (auto i : roads) {
      int start = i[0];
      int end = i[1];
      int dis = i[2];
      adj[start].push_back({end, dis});
      adj[end].push_back({start, dis});
    }
    // BFS
    queue<int> q;
    // start from node 1
    q.push(1);
    // record if the node has been visited to avoid loop
    // because no matter how we traverse,
    // we still can reach the destination
    set<int> visited;
    // mark the first node as visited
    visited.insert(1);

    int ans = INT_MAX;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int tmp = q.front();
        q.pop();

        for (auto [dst, dis] : adj[tmp]) {
          ans = min(ans, dis);
          if (visited.find(dst) == visited.end()) {
            q.push(dst);
            visited.insert(dst);
          }
        }
      }
    }

    return ans;
  }
}

// 2. BFS plain verision, would TLE
class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    // adjacency matrix
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>({}));
    for (auto i : roads) {
      int start = i[0];
      int end = i[1];
      int dis = i[2];
      adj[start].push_back({end, dis});
      adj[end].push_back({start, dis});
    }
    // BFS
    queue<int> q;
    // start from node 1
    q.push(1);
    // record directional path that has been visited to avoid loop
    set<pair<int, int>> visited;
    int ans = INT_MAX;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int tmp = q.front();
        q.pop();

        for (auto [dst, dis] : adj[tmp]) {
          if (visited.find({tmp, dst}) == visited.end()) {
            q.push(dst);
            visited.insert({tmp, dst});
            ans = min(ans, dis);
          }
        }
      }
    }

    return ans;
  }
};

// 3. DFS
class Solution {
public:
  void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited,
           int &ans) {
    visited[node] = true;

    for (auto [dst, dis] : adj[node]) {
      ans = min(ans, dis);
      if (!visited[dst]) {
        dfs(dst, adj, visited, ans);
      }
    }
  }

  int minScore(int n, vector<vector<int>> &roads) {
    // adjacency matrix
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>({}));
    for (auto i : roads) {
      int start = i[0];
      int end = i[1];
      int dis = i[2];
      adj[start].push_back({end, dis});
      adj[end].push_back({start, dis});
    }

    vector<int> visited(n + 1, false);

    int ans = INT_MAX;
    dfs(1, adj, visited, ans);

    return ans;
  }
};

// 4. Union set
// to find those node connected, remove isolated nodes
class Solution {
public:
  // root record the root of each node root[i]
  // rank record the rank of each node rank[i]
  vector<int> root, rank;

  // recursively find the root of node x
  int find(int x) {
    // check if current vertex is the root
    if (x == root[x])
      return root[x];
    // else update its parent to be the root of the set that contains current
    // parent
    return root[x] = find(root[x]);
  }

  void createUnion(int x, int y) {
    // find the root of node x and y
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return;
    // merge the sets
    if (rank[rootX] < rank[rootY])
      root[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
      root[rootY] = rootX;
    else { // if ranks are the same
      root[rootY] = rootX;
      rank[rootX]++;
    }
  }

  int minScore(int n, vector<vector<int>> &roads) {
    root.resize(n + 1);
    rank.resize(n + 1);
    // initialize root and rank
    for (int i = 0; i < n + 1; i++) {
      root[i] = i;
      rank[i] = 0;
    }

    int ans = INT_MAX;
    // merge the union sets, update the root[]
    for (auto i : roads) {
      createUnion(i[0], i[1]);
    }

    // start is always node 1
    int root1 = find(1);
    for (auto i : roads) {
      int rootX = find(i[0]);
      int rootY = find(i[1]);
      // if node x,y can all be connected with node 1
      if (rootX == root1 && rootY == root1) {
        // means we can pick the score in this road
        ans = min(ans, i[2]);
      }
    }

    return ans;
  }
};
