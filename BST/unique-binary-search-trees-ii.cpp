// https://leetcode.com/problems/unique-binary-search-trees-ii/description/
// the recursion idea(divide & conquer) is very similar to:
// https://leetcode.com/problems/all-possible-full-binary-trees/description/

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
  // as the given function params don't include the `end` value, so we have a
  // separate recursion function
  vector<TreeNode *> recursion(int start, int end) {
    // when to return
    int size = end - start + 1;
    if (size == 0)
      return {nullptr};
    if (size == 1)
      return {new TreeNode(start)};

    // the subtrees that would be returned in this recursion, whose range is
    // [start, end]
    vector<TreeNode *> subtrees;
    // 1. divide: divide the nodes to left & right subtree, the root is i
    for (int i = start; i <= end; i++) {
      vector<TreeNode *> left = recursion(start, i - 1);
      vector<TreeNode *> right = recursion(i + 1, end);

      // 2. conquer: combine the left & right subtree with the root to form a
      // new subtree, there can be various combinations
      for (auto l : left) {
        for (auto r : right) {
          // i is the root
          TreeNode *root = new TreeNode(i);
          root->left = l;
          root->right = r;
          subtrees.push_back(root);
        }
      }
    }

    return subtrees;
  }

  vector<TreeNode *> generateTrees(int n) { return recursion(1, n); }
};
