// https://leetcode.com/problems/increasing-order-search-tree/
//
//
class Solution {
public:
  void recurse(TreeNode *root, TreeNode *&ans) {
    if (root == nullptr)
      return;

    recurse(root->left, ans);
    ans->right = new TreeNode(root->val);
    ans = ans->right;
    recurse(root->right, ans);
  }

  TreeNode *increasingBST(TreeNode *root) {
    TreeNode *ans = new TreeNode;
    TreeNode *p = ans;
    recurse(root, ans);
    return p->right;
  }
};
