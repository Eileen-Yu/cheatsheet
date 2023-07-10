// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
//
/*
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
// 1. advanced recursion
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    // need to add the current node itself
    return max(maxLeft, maxRight) + 1;
  }
};

// 2. plain recursion
class Solution {
public:
  void recursion(TreeNode *root, int tmp, int &ans) {
    // when to return: already to the end of the path
    if (!root) {
      ans = max(ans, tmp);
      return;
    }

    // this +1 is for the current level, not for root->left / root->right
    recursion(root->left, tmp + 1, ans);
    recursion(root->right, tmp + 1, ans);
  }

  int maxDepth(TreeNode *root) {
    int tmp = 0;
    int ans = INT_MIN;
    recursion(root, tmp, ans);

    return ans;
  }
};
