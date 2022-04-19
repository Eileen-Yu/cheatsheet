// https://leetcode.com/problems/recover-binary-search-tree/

// 1. unorder_map to record val + vector to sort
class Solution {
public:
  unordered_map<int, TreeNode *> mp;
  vector<int> c;

  void recurse(TreeNode *root) {
    if (!root)
      return;
    recurse(root->left);
    mp[root->val] = root;
    c.push_back(root->val);
    recurse(root->right);
  }

  void recoverTree(TreeNode *root) {
    recurse(root);

    vector<int> n = c;
    sort(n.begin(), n.end()); // copy c for sorted

    for (int i = 0; i < n.size(); i++) {
      if (c[i] != n[i]) {
        mp[c[i]]->val = n[i];
      }
    }
  }
};

// 2. 1,2,6,4,5,3,7  --> principle, swap 6 & 3
class Solution {
public:
  TreeNode *firstMis;
  TreeNode *secondMis;
  TreeNode *pre = new TreeNode(int INT_MIN); // ascending

  void recurse(TreeNode *root) {
    if (!root)
      return;
    recurse(root->left);

    if (firstMis == nullptr && root->val < pre->val)
      firstMis = pre;
    if (firstMis != nullptr && root->val < pre->val)
      secondMis = root;
    pre = root;

    recurse(root->right);
  }

  void recoverTree(TreeNode *root) {
    recurse(root);
    swap(firstMis->val, secondMis->val);
  }
};
