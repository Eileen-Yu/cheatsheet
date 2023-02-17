// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
//
// 1. calculate in the recurse directly,
// because BST inOrder would be in asscending order
class Solution {
public:
  void recurse(TreeNode *node, int &ans, int &prev) {
    if (!node)
      return;
    // inOrder traverse
    recurse(node->left, ans, prev);
    // if the previous node exists
    // prev is always < current node->val
    if (prev != -1)
      ans = min(ans, node->val - prev);
    prev = node->val;
    recurse(node->right, ans, prev);
  }

  int minDiffInBST(TreeNode *root) {
    int ans = INT_MAX;
    // prev is the value of last visited node
    // first we haven't visited any node yet
    int prev = -1;
    recurse(root, ans, prev);
    return ans;
  }
};

// 2. use vector to keep all values in ascending order
class Solution {
public:
  void recurse(vector<int> &record, TreeNode *node) {
    if (!node)
      return;
    // InOrder traverse
    recurse(record, node->left);
    record.push_back(node->val);
    recurse(record, node->right);
  }

  int minDiffInBST(TreeNode *root) {
    vector<int> record;
    recurse(record, root);
    int ans = INT_MAX;

    for (int i = 0; i < record.size() - 1; i++) {
      ans = min(ans, record[i + 1] - record[i]);
    }

    return ans;
  }
};
