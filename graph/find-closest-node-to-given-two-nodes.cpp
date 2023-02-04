// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/
// DFS: mark if visited to avoid loop + recursion
// graph: care about neighbor, based on `curNode`
class Solution {
public:
  void dfs(vector<int> &edges, vector<int> &dist, int curNode,
           vector<bool> &flag) {
    // mark the current node as visited, so as to avoid loop
    flag[curNode] = true;
    int neighbor = edges[curNode];
    // if the neighbor exists and hasn't been visited
    if (neighbor != -1 && flag[neighbor] == false) {
      // update the distance from the initial node to the neighbor
      dist[neighbor] = dist[curNode] + 1;
      flag[neighbor] = true;
      dfs(edges, dist, neighbor, flag);
    }
  }

  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    // number of nodes
    int n = edges.size();
    // mark if the i-th node has been visited
    vector<bool> flag1(n, false);
    vector<bool> flag2(n, false);
    // record the distance from the initial node to the i-th node
    vector<int> dist1(n, 0);
    vector<int> dist2(n, 0);
    dfs(edges, dist1, node1, flag1);
    dfs(edges, dist2, node2, flag2);

    int minDist = INT_MAX;
    int ans = -1;
    // loop all nodes
    for (int i = 0; i < n; i++) {
      // the node can be reached from both node1 and node 2
      // && current minDist > the maximum between the distance from node1 to
      // that node, and from node2 to that node
      if (flag1[i] == true && flag2[i] == true &&
          minDist > max(dist1[i], dist2[i])) {
        minDist = max(dist1[i], dist2[i]);
        ans = i;
      }
    }

    return ans;
  }
};
