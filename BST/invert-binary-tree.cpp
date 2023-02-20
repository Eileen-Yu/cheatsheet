// https://leetcode.com/problems/invert-binary-tree/description/

// post-Order / Pre-Order both work
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;

    // post-order traverse
    invertTree(root->left);
    invertTree(root->right);
    // swap left and right
    swap(root->left, root->right);
    /*
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    */
    return root;
  }
};
