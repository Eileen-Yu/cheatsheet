// https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode *a = new TreeNode(val);
    TreeNode *p = root;

    if (root == nullptr) {
      return a;
    }

    while (p != nullptr) {
      if (val < p->val) {
        if (p->left == nullptr) {
          p->left = a;
          break;
        }
        p = p->left;
      }

      else {
        if (p->right == nullptr) {
          p->right = a;
          break;
        }
        p = p->right;
      }
    }

    return root;
  }
};
