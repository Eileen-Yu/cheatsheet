// https://leetcode.com/problems/convert-bst-to-greater-tree/
//
class Solution {
public:
  void recurse(TreeNode *root, int &sum) {
    if (root == nullptr)
      return;

    recurse(root->right, sum);

    root->val += sum; // for every node
    sum = root->val;

    recurse(root->left, sum);
  }

  TreeNode *convertBST(TreeNode *root) {
    int s = 0;
    recurse(root, s);
    return root;
  }
};
