// https://leetcode.com/problems/delete-nodes-and-return-forest/
// what kind of nodes need to be put into the ans: new root(without parent)
// use pre-order traversal to decide this node + its children
class Solution {
public:
  vector<TreeNode *> ans;
  // record the nodes to be deleted
  set<int> st;

  TreeNode *recursion(TreeNode *cur, bool isRoot, vector<TreeNode *> &ans) {
    // when to return
    if (!cur)
      return nullptr;

    // pre-order traversal
    // 1. for the current node
    // 1.1 check if needs to delete this node
    bool deleted = st.find(cur->val) != st.end();
    // if this node has no parent & no need to be deleted, push it as the root
    // to the ans
    if (isRoot && !deleted)
      ans.push_back(cur);

    // 2. for the left & right children, isRoot = parent has been deleted
    cur->left = recursion(cur->left, deleted, ans);
    cur->right = recursion(cur->right, deleted, ans);

    // return
    return deleted ? nullptr : cur;
  }

  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    // push all to_delete nodes into set for easier search
    for (auto i : to_delete) {
      st.insert(i);
    }

    vector<TreeNode *> ans;
    recursion(root, true, ans);

    return ans;
  }
};
