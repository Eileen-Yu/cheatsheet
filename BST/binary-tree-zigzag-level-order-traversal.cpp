// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// level-order-traverse: use BFS(queue)

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root)
      return {};

    vector<vector<int>> ans;
    // traverse every level
    queue<TreeNode *> q;
    q.push(root);
    // odd level is true, even level is false
    bool f = true;

    while (!q.empty()) {
      int size = q.size();
      vector<int> cur(size);

      for (int i = 0; i < size; i++) {
        TreeNode *tmp = q.front();
        q.pop();

        // if odd level, in order
        if (f == true)
          cur[i] = tmp->val;
        // if even level, reverse order
        else
          cur[size - i - 1] = tmp->val;

        if (tmp->left)
          q.push(tmp->left);
        if (tmp->right)
          q.push(tmp->right);
      }

      // to the next level
      f = !f;
      ans.push_back(cur);
    }

    return ans;
  }
};
