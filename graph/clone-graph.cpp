// https://leetcode.com/problems/clone-graph/description/
//
// map + DFS / BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  // old node : new node
  // map to check if a node is already copied
  unordered_map<Node *, Node *> mp;

  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;
    // if the node has not been copied yet
    if (mp.find(node) == mp.end()) {
      // copy the node itself
      Node *copy = new Node(node->val, {});
      mp[node] = copy;
      // copy the node's neighbors
      for (auto neighbor : node->neighbors) {
        // recursion to implement DFS
        mp[node]->neighbors.push_back(cloneGraph(neighbor));
      }
    }

    // return the first node of the copied graph
    return mp[node];
  }
};
