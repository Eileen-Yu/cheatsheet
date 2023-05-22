// https://leetcode.com/problems/evaluate-division/
// 1. dfs + global variable to store the ans + refresh visited on each level
class Solution {
public:
  double queryRslt;

  bool dfs(string node,
           unordered_map<string, vector<pair<string, double>>> &adj,
           double &product, string to, unordered_map<string, bool> &visited) {
    // if this node is exactly the dst
    // except for special cases: query [x,x] but not in the original equations
    // so this means the dst must be in the original equations
    if (node == to && adj.find(node) != adj.end()) {
      queryRslt = product;
      return true;
    }

    // if this node is the end of the path but not the target dst
    if (adj.find(node) == adj.end()) {
      return false;
    }

    // if we need to traverse along the path
    // mark this one as visited to avoid loop
    visited[node] = true;
    // record if there is a path to the dst on this level
    bool tmpAns = false;

    for (auto [neighbor, val] : adj[node]) {
      if (!visited[neighbor]) {
        double newProduct = product * val;
        tmpAns = dfs(neighbor, adj, newProduct, to, visited);
        // only when we find the dst in one path, we break the search
        if (tmpAns)
          break;
      }
    }

    // refresh the visited of the node of each layer for later queries
    visited[node] = false;

    // default is false, means checked all path and no one is qualified
    return tmpAns;
  }

  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    // key: from, value: [{to1, value1}, {to2, value2}...]
    // as the node is represent as 'string', should use map
    unordered_map<string, vector<pair<string, double>>> adj;
    // key: node, value: t/f
    unordered_map<string, bool> visited;
    int n = values.size();
    // fill in the adjacency matrix
    for (int i = 0; i < n; i++) {
      string from = equations[i][0];
      string to = equations[i][1];
      double val = values[i];

      // directed graph
      adj[from].push_back({to, val});
      adj[to].push_back({from, 1 / val});
      // init the visited
      visited[from] = false;
      visited[to] = false;
    }

    vector<double> rslt;

    // check for each query
    for (auto i : queries) {
      string from = i[0];
      string to = i[1];

      // refresh the base each time
      double base = 1;
      // refresh the queryRslt for each query
      queryRslt = 0;

      if (dfs(from, adj, base, to, visited))
        rslt.push_back(queryRslt);
      else
        rslt.push_back(-1);
    }

    return rslt;
  }
};

// 2.
class Solution {
private:
  double find(unordered_map<string, vector<pair<string, double>>> &grf,
              unordered_set<string> &visited, string start, string end) {
    if (grf.find(start) == grf.end() || grf.find(end) == grf.end())
      return -1.0; // return -1 if start and end not exist in adj. list

    if (start == end)
      return 1.0; // if we are at end

    visited.insert(start); // mark as visited

    for (auto next : grf[start]) {
      if (visited.count(next.first) == 0) {
        double res = find(grf, visited, next.first, end); //  dfs recurse

        if (res != -1.0) {
          return res * next.second;
        }
      }
    }
    return -1.0;
  }

public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    unordered_map<string, vector<pair<string, double>>> grf;

    for (int i = 0; i < equations.size();
         i++) { // making adj. list for each edge
      grf[equations[i][0]].push_back({equations[i][1], values[i]});
      grf[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
    }

    vector<double> ans;

    for (auto q : queries) {
      unordered_set<string> visited; // track previous visited nodes  in order
                                     // to avoid infinite loop
      double res = find(grf, visited, q[0], q[1]); // go for current query
      ans.push_back(res);
    }
    return ans;
  }
};
