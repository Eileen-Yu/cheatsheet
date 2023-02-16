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
  void recurse(TreeNode *node, int &count, int &ans) {
    // when to return
    if (!node) {
      // this path comes to the end
      ans = max(ans, count);
      return;
    }
    // if node exists
    count++;
    // record the depth of current node
    int tmp = count;
    recurse(node->left, count, ans);
    count = tmp;
    recurse(node->right, count, ans);
  }

  int maxDepth(TreeNode *root) {
    int count = 0;
    int ans = 0;
    recurse(root, count, ans);

    return ans;
  }
};
