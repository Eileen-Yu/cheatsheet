// https://leetcode.com/problems/validate-binary-tree-nodes
// find root + DFS
// 1. record parent-child relationship
// 2. find the only root (no root / >=1 root are invalid)
// 3. check cycles in the tree (no node can be visited twice)
// 4. check completeness (no isolated node)
class Solution {
public:
  bool dfs(int idx, vector<bool> &visited, int n, vector<int> &leftChild,
           vector<int> &rightChild) {
    // when to return
    // 1. no child
    if (idx == -1)
      return true;
    // 2. already looped all nodes
    if (idx >= n)
      return true;

    // otherwise
    // 1. if this node already been visited
    if (visited[idx])
      return false;

    // 2. else
    // mark this node as visited
    visited[idx] = true;

    // check its children
    return dfs(leftChild[idx], visited, n, leftChild, rightChild) &&
           dfs(rightChild[idx], visited, n, leftChild, rightChild);
  }

  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    // mark if a node has been visited
    vector<bool> visited(n, false);
    // record the parent of each node
    vector<int> parent(n, -1);

    // loop each node
    for (int i = 0; i < n; i++) {
      if (leftChild[i] != -1) {
        // the leftchild have more than 1 parent
        if (parent[leftChild[i]] != -1)
          return false;
        else
          parent[leftChild[i]] = i;
      }

      if (rightChild[i] != -1) {
        // the rightchild have more than 1 parent
        if (parent[rightChild[i]] != -1)
          return false;
        else
          parent[rightChild[i]] = i;
      }
    }

    int root = -1;
    // find the root: the only node without the parent
    for (int i = 0; i < n; i++) {
      if (parent[i] == -1) {
        // if there are more than 1 root
        if (root != -1)
          return false;

        else
          root = i;
      }
    }

    // no root
    if (root == -1)
      return false;

    // check if there's cycle
    bool check = dfs(root, visited, n, leftChild, rightChild);
    if (!check)
      return false;

    // check if there is isolated node
    for (auto i : visited) {
      if (!i)
        return false;
    }

    return true;
  }
};
