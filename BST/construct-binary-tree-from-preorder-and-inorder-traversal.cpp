// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// divide & conquer + hashmap
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
  // idx to loop preorder
  int preOrderIdx;
  // record element: idx in inorder to divide the tree into subtrees
  unordered_map<int, int> mp;
  TreeNode *buildTreeHelper(vector<int> &preorder, int left, int right) {
    // when to return
    if (left > right)
      return nullptr;
    // the first element of the preorder is the root of the subtree
    int rootVal = preorder[preOrderIdx++];
    TreeNode *root = new TreeNode(rootVal);
    // divide the tree into subtrees by the root in inorder
    // left first because we loop the preorder, it is left -> mid -> right
    int mid = mp[rootVal];

    root->left = buildTreeHelper(preorder, left, mid - 1);
    root->right = buildTreeHelper(preorder, mid + 1, right);

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    preOrderIdx = 0;

    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1);
  }
};
