// https://leetcode.com/problems/symmetric-tree/description/
//
// DFS / recursion
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
  bool symmetric(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr)
      return true;
    if (left == nullptr || right == nullptr)
      return false;
    if (left->val != right->val)
      return false;
    // for every level
    return symmetric(left->left, right->right) &&
           symmetric(left->right, right->left);
  }
  bool isSymmetric(TreeNode *root) {
    return symmetric(root->left, root->right);
  }
};
