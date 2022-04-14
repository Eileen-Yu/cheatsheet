// https://leetcode.com/problems/search-in-a-binary-search-tree/

class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root != nullptr) {
      if (root->val == val)
        return root;
      if (root->val > val)
        root = root->left;
      else if (root->val < val)
        root = root->right;
    }
    return nullptr;
  }
};
