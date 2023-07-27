// https://leetcode.com/problems/all-possible-full-binary-trees/description/
// divide & conquer + recursion + full binary tree:
// each time separate the odd number of :w
// nodes into left & right subtrees,
// then try different combinations to make up a new subtree

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
  vector<TreeNode *> allPossibleFBT(int n) {
    // a full binary tree(FBT) would only contain odd number of nodes
    if (n % 2 == 0)
      return {};
    // base case: only 1 as the root
    if (n == 1)
      return {new TreeNode(0)};

    // store each subtree
    vector<TreeNode *> subtree;
    // divide part: separate as left & right subtrees
    // iterate over odd numbers of the nodes as the size of the left subtree
    for (int i = 1; i < n; i += 2) {
      vector<TreeNode *> left = allPossibleFBT(i);
      // n-i-1 is the size of the right subtree
      vector<TreeNode *> right = allPossibleFBT(n - i - 1);

      // conquer part:
      // loop over each possible combination
      for (auto l : left) {
        for (auto r : right) {
          // create a root for this new subtree
          TreeNode *root = new TreeNode(0);
          root->left = l;
          root->right = r;
          subtree.push_back(root);
        }
      }
    }

    return subtree;
  }
};
