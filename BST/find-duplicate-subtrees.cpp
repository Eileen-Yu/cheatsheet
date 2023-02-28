// https://leetcode.com/problems/find-duplicate-subtrees/description/
//
// DFS(recurse) + post-order to travser BT
// hash map to find duplicate(calculate frequency)
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
  string recurse(TreeNode *root, vector<TreeNode *> &ans,
                 unordered_map<string, int> &mp) {
    // when to return
    if (!root)
      return "#";
    // post-order traverse
    string left = recurse(root->left, ans, mp);
    string right = recurse(root->right, ans, mp);
    // main logic
    // use "," to divide left and right to avoid ambiguity
    string tmp = left + "," + right + "," + to_string(root->val);

    // if the frequency is 1, means a new duplicate
    // if >= 1, would count more than once
    if (mp[tmp] == 1)
      ans.push_back(root);

    mp[tmp]++;

    return tmp;
  }

  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    vector<TreeNode *> ans;
    unordered_map<string, int> mp;

    recurse(root, ans, mp);

    return ans;
  }
};
