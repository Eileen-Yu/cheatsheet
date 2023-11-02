// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// post-order traversal(left, right, current)
class Solution {
public:
  int ans = 0;

  // return size & sum value of the subtree (includes the current node)
  pair<int, int> recursion(TreeNode *node) {
    // when to return
    if (!node)
      return {0, 0};

    // post-order traversal
    pair<int, int> left = recursion(node->left);
    pair<int, int> right = recursion(node->right);

    // main logic:
    // sum = left + right + current
    int sum = left.first + right.first + node->val;
    // count = leftCount + rightCount + 1(current)
    int count = left.second + right.second + 1;
    // if the current node == average
    if (sum / count == node->val)
      ans++;
    return {sum, count};
  }

  int averageOfSubtree(TreeNode *root) {
    // don't need the return value here, can ignore it
    recursion(root);
    return ans;
  }
};
