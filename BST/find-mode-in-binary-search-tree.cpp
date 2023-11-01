// https://leetcode.com/problems/find-mode-in-binary-search-tree/description
// 1. use map to record the frequency of each element
// not fully use the BST feature
class Solution {
public:
  void recursion(TreeNode *node, unordered_map<int, int> &mp) {
    // when to return
    if (!node)
      return;

    // in-order trversal
    recursion(node->left, mp);
    mp[node->val]++;
    recursion(node->right, mp);
  }

  vector<int> findMode(TreeNode *root) {
    // {element, frequency}
    unordered_map<int, int> mp;
    // record the frequency of each element
    recursion(root, mp);

    // {frequency, {element1, element2...}}
    map<int, vector<int>> reverseMp;
    for (auto i : mp) {
      reverseMp[i.second].push_back(i.first);
    }

    // the last element is the one of the most frequency
    return reverseMp.rbegin()->second;
  }
};
