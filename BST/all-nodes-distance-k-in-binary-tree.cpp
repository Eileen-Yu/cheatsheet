// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
// implement 2 times of BFS:
// 1. the first one is to record the child-parent relationship by a map
// 2. the second one is to find the nodes that are K distant (k steps) from the
// target

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    // for BFS
    queue<TreeNode *> q;
    q.push(root);
    // {node, parent}
    unordered_map<TreeNode *, TreeNode *> mp;
    // the first BFS is to update the mp to record the parent-child relationship
    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();

      if (cur->left) {
        mp[cur->left] = cur;
        q.push(cur->left);
      }

      if (cur->right) {
        mp[cur->right] = cur;
        q.push(cur->right);
      }
    }

    // reset the queue for the second BFS
    // to find the nodes that have a distance K from the target
    q = queue<TreeNode *>();
    // hash table to record if the node with value i has been visited
    vector<bool> visited(501, false);
    // start from the target, each step put its children & parent to the queue
    q.push(target);

    // BFS
    while (!q.empty() && k--) {
      int size = q.size();
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();
        // mark this node as visited
        visited[cur->val] = true;

        // check this node's children
        if (cur->left && !visited[cur->left->val])
          q.push(cur->left);
        if (cur->right && !visited[cur->right->val])
          q.push(cur->right);
        // check this node's parent
        if (mp[cur] && !visited[mp[cur]->val])
          q.push(mp[cur]);
      }
    }

    vector<int> ans;
    while (!q.empty()) {
      ans.push_back(q.front()->val);
      q.pop();
    }

    return ans;
  }
};
