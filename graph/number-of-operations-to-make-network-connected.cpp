// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// 1. DFS
class Solution {
public:
  void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (auto i : adj[node]) {
      if (!visited[i]) {
        dfs(i, adj, visited);
      }
    }
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    // to connect n nodes, at least need n-1 cables
    int cables = connections.size();
    if (cables < n - 1)
      return -1;

    vector<vector<int>> adj(n);
    for (auto i : connections) {
      int com1 = i[0];
      int com2 = i[1];
      adj[com1].push_back(com2);
      adj[com2].push_back(com1);
    }

    vector<bool> visited(n, false);

    // record the number of clusters
    // one cluster contains several connected nodes
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, adj, visited);
        count++;
      }
    }

    return count - 1;
  }
};

// 2. BFS
class Solution {
public:
  void bfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int tmp = q.front();
        q.pop();

        for (auto i : adj[tmp]) {
          if (!visited[i]) {
            q.push(i);
            visited[i] = true;
          }
        }
      }
    }
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    // to connect n nodes, at least need n-1 cables
    int cables = connections.size();
    if (cables < n - 1)
      return -1;

    vector<vector<int>> adj(n);
    for (auto i : connections) {
      int com1 = i[0];
      int com2 = i[1];
      adj[com1].push_back(com2);
      adj[com2].push_back(com1);
    }

    vector<bool> visited(n, false);

    // record the number of clusters
    // one cluster contains several connected nodes
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        bfs(i, adj, visited);
        count++;
      }
    }

    return count - 1;
  }
};

// 3. union find to group clusters with the same root
class Solution {
public:
  vector<int> root;
  vector<int> rank;
  // find the root of node x
  int find(int x) {
    if (x == root[x])
      return root[x];
    return root[x] = find(root[x]);
  }

  // cluster nodes that have the same root
  void createUnion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return;
    if (rank[rootX] < rank[rootY])
      root[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
      root[rootY] = rootX;
    else {
      root[rootY] = rootX;
      rank[rootX]++;
    }
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    // need at least n-1 cables to connect n nodes
    if (connections.size() < n - 1)
      return -1;

    root.resize(n);
    rank.resize(n);
    // initialize root and rank
    for (int i = 0; i < n; i++) {
      root[i] = i;
      rank[i] = 0;
    }
    // update the root[]
    for (auto i : connections) {
      createUnion(i[0], i[1]);
    }

    // record the root of each cluster
    // some nodes may have the same root, so use set
    set<int> clusterRoot;
    for (int i = 0; i < n; i++) {
      // find the root of each node based on the updated root[]
      int root = find(i);
      clusterRoot.insert(root);
    }

    // for n clusters need n-1 cables to connect them
    return clusterRoot.size() - 1;
  }
};
