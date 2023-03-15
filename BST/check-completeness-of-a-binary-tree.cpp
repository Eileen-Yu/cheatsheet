// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

// travser level by level
// BFS (queue)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    // check if there is null node inside the tree
    bool hasNullNode = false;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode *tmp = q.front();
        q.pop();

        if (tmp == nullptr) {
          hasNullNode = true;
          continue;
        }
        // indicates there is null node inside the tree
        if (tmp != nullptr && hasNullNode == true)
          return false;

        q.push(tmp->left);
        q.push(tmp->right);
      }
    }

    return true;
  }
};
