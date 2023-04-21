// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description
//
// DFS + DP
// stand on one node
// for every node, we compare
// 1. length till here
// 2. max length start from this node to left first
// 3. max length start from this node to right first

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
  int dfs(TreeNode *root, int length, bool shouldGoLeft) {
    // before we add 1 to length when suppose this node exists
    if (!root)
      return length - 1;

    // max length if go left from this node
    int left = 0;
    // max length if go right from this node
    int right = 0;
    // current ZigZig length till this node
    int tmp = 0;

    // if this node is the end of one possible ZigZag
    if (shouldGoLeft && !root->left) {
      tmp = length;
      length = 0;
    } else if (!shouldGoLeft && !root->right) {
      tmp = length;
      length = 0;
    }

    // if !shouldGoLeft, this node is a new start, so we set lenght = 1
    left = dfs(root->left, shouldGoLeft ? length + 1 : 1, false);
    right = dfs(root->right, shouldGoLeft ? 1 : length + 1, true);

    return max({left, right, tmp});
  }

  int longestZigZag(TreeNode *root) {
    if (!root->left && !root->right)
      return 0;

    // doesn't matter here we choose left / right
    // as we would try both in the recursion
    return dfs(root, 0, true);
  }
};
