// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//
//
// 1. recurse + count
class Solution {
public:
  int c = 0;
  int ans = 0;

  void recurse(TreeNode *root, int &k) {
    if (root == nullptr || c == k)
      return;

    recurse(root->left, k);
    if (c < k) {
      ans = root->val;
      c++;
    }
    recurse(root->right, k);
  }

  int kthSmallest(TreeNode *root, int k) {
    recurse(root, k);
    return ans;
  }
};

// 2. vector(size = k) to count
class Solution {
public:
  void recurse(TreeNode *root, int &k, vector<int> &n) {
    if (root == nullptr || n.size() == k)
      return;

    recurse(root->left, k);
    n.push_back(root->val);
    recurse(root->right, k);
  }

  int kthSmallest(TreeNode *root, int k) {
    vector<int> n;
    recurse(root, k, n);
    return n[k - 1]; // last element in the vector
  }
};
