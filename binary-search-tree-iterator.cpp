// https://leetcode.com/problems/binary-search-tree-iterator/
//
class BSTIterator {
public:
  vector<int> n;
  int p = 0;
  int ans;

  void recurse(TreeNode *root) {
    if (!root)
      return;
    recurse(root->left);
    n.push_back(root->val);
    recurse(root->right);
  }

  BSTIterator(TreeNode *root) {
    TreeNode *s = new TreeNode(INT_MIN);
    recurse(root);
  }

  int next() {
    if (p < n.size())
      ans = n[p];
    p++;
    return ans;
  }

  bool hasNext() {
    if (p < n.size())
      return true;
    return false;
  }
};
