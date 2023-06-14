// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
// 1. use extra vector to store the values
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
  vector<int> arr;

  void recursion(TreeNode *root) {
    // when to return
    if (!root)
      return;

    // preOrder
    arr.push_back(root->val);
    recursion(root->left);
    recursion(root->right);
  }

  int getMinimumDifference(TreeNode *root) {
    recursion(root);
    sort(arr.begin(), arr.end());

    int ans = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++) {
      ans = min(ans, arr[i + 1] - arr[i]);
    }
    return ans;
  }
};
