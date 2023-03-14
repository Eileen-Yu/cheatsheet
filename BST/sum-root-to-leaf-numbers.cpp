// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
//
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
  void recursion(TreeNode *root, int &sum, int sumTillCur) {
    if (!root)
      return;

    sumTillCur = sumTillCur * 10 + root->val;

    // if current node is a leaf node
    if (!root->left && !root->right) {
      sum += sumTillCur;
    }

    recursion(root->left, sum, sumTillCur);
    recursion(root->right, sum, sumTillCur);
  }

  int sumNumbers(TreeNode *root) {
    int sum = 0;
    recursion(root, sum, 0);
    return sum;
  }
};
