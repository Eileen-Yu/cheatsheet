// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// traverse level by level
// skill of node Idx in tree:
// current node: i
// left: 2i+1, right: 2i+2

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
  int widthOfBinaryTree(TreeNode *root) {
    // pair: node, idx
    queue<pair<TreeNode *, size_t>> q;
    q.push({root, 0});
    size_t ans = 1;

    // traverse level by level
    while (!q.empty()) {
      // width = rightmost Idx - leftmost Idx + 1
      ans = max(ans, q.back().second - q.front().second + 1);

      int size = q.size();
        whi[<72;39;9Mle(size--) {
        TreeNode *curNode = q.front().first;
        size_t curIdx = q.front().second;
        q.pop();

        // idx of left node = 2i+1
        if (curNode->left)
          q.push({curNode->left, 2 * curIdx + 1});
        if (curNode->right)
          q.push({curNode->right, 2 * curIdx + 2});
        }
    }

    return (int)ans;
  }
};
