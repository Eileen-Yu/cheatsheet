// https://leetcode.com/problems/is-graph-bipartite/
// 1. DFS(recursion) + color algorithm to check if neighbors are in the same set
// if yes, return false
//
class Solution {
public:
  bool dfs(vector<vector<int>> &adj, vector<int> &visited, int node) {
    // current node's set
    int set = visited[node];
    // another set
    int op;
    if (set == 1)
      op = 2;
    else if (set == 2)
      op = 1;

    // the neighbor of this node should be in another set
    for (auto neighbor : adj[node]) {
      // if the neighbor already visited, and in the same set as this node
      if (visited[neighbor] != 0 && visited[neighbor] == visited[node])
        return false;
      // not visited yet, mark it as in the other set, continue to check for its
      // neighbors
      else if (visited[neighbor] == 0) {
        visited[neighbor] = op;
        // once there is false, we ruturn,
        // otherwise we continue to check
        // *here cannot return directly, otherwise it would miss to check the
        // other neighbors of this node
        if (dfs(adj, visited, neighbor) == false)
          return false;
      }
    }

    return true;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    // number of nodes
    int n = graph.size();
    // color algorithm:
    // 0: not visited
    // 1: visited, mark as set1
    // 2: visited, mark as set2
    // init all nodes as not visited
    vector<int> visited(n, 0);

    // check each node as the starter
    for (int i = 0; i < n; i++) {
      // because the graph is not connected, so it may be another sets of
      // connected nodes
      if (visited[i] == 0) {
        visited[i] = 1;
        if (dfs(graph, visited, i) == false)
          return false;
      }
    }

    return true;
  }
};

// 2. BFS + color algorithm
class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    // number of nodes
    int n = graph.size();
    // color algorithm:
    // -1: not visited
    // 0: set 1
    // 1: set 2
    vector<int> visited(n, -1);
    // BFS
    queue<int> q;

    // check each node
    for (int i = 0; i < n; i++) {
      // if this node hasn't been visited and checked
      if (visited[i] == -1) {
        // assume this node is in a set
        visited[i] = 0;
        q.push(i);

        while (!q.empty()) {
          int size = q.size();

          while (size--) {
            int tmp = q.front();
            q.pop();

            int status = visited[tmp];
            int op;
            if (status == 0)
              op = 1;
            else if (status == 1)
              op = 0;

            // check its neighbors
            for (auto neighbor : graph[tmp]) {
              // if the neighbor already visited, and marked in the same set
              // with this node
              if (visited[neighbor] != -1 && visited[neighbor] == status)
                return false;
              // if the neighbor has never been visited
              else if (visited[neighbor] == -1) {
                // mark it as in the other set
                visited[neighbor] = op;
                // put it into the queue to check its neighbor
                q.push(neighbor);
              }
            }
          }
        }
      }
    }

    return true;
  }
};
