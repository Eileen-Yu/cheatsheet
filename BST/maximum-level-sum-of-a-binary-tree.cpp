// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
// BFS to traverse the tree level by level
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
  int maxLevelSum(TreeNode *root) {
    // BFS to traverse level by level
    queue<TreeNode *> q;
    q.push(root);

    int level = 0, sum = INT_MIN;
    int ans = 0;
    while (!q.empty()) {
      int size = q.size();
      level++;

      int tmp = 0;
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();
        tmp += cur->val;
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }

      if (tmp > sum) {
        sum = tmp;
        ans = level;
      }
    }

    return ans;
  }
};
