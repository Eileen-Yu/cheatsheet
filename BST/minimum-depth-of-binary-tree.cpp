// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
// in-order travsersal
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
  // in-Order traverse
  void recursion(TreeNode *root, int tmp, int &ans) {
    // when to return
    // 1. if no such node, directly return
    if (!root)
      return;

    // 2. if this is a leaf node (no children)
    if (!root->left && !root->right) {
      // update the ans
      ans = min(ans, tmp);
      return;
    }

    // recursion
    if (root->left)
      recursion(root->left, tmp + 1, ans);
    if (root->right)
      recursion(root->right, tmp + 1, ans);
  }

  int minDepth(TreeNode *root) {
    // special case:
    if (!root)
      return 0;

    int ans = INT_MAX;
    int tmp = 1;
    recursion(root, tmp, ans);
    return ans;
  }
};
