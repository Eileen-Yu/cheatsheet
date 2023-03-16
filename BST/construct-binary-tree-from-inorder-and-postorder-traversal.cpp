// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
//
// divide & conquer + hashmap
// use the last element of the postorder to find the root of each subtree
// use the root to devide the tree into left & right part by inorder

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
  // idx to loop postorder in the reverse order
  // this is because the last element is the root
  int postOrderIndex;

  // record the idx of each element in inOrder to divide the array
  // key: element , value: idx
  unordered_map<int, int> mp;

  // left: start of the subarray(subtree)
  // right: end of the subarray(subtree)
    TreeNode* buildTreeHelper(ve[<72;54;10Mctor<int>& postorder, int left, int right ) {
    if (left > right)
      return nullptr;

    // the last element of the postorder it the root (of the subtree)
    int rootVal = postorder[postOrderIndex--];
    TreeNode *root = new TreeNode(rootVal);
    // divide the inorder into left & right based on the root
    int mid = mp[rootVal];
    // right first because we traverse the postorder in the reverse order
    // (mid -> right -> left)
    root->right = buildTreeHelper(postorder, mid + 1, right);
    root->left = buildTreeHelper(postorder, left, mid - 1);

    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    postOrderIndex = postorder.size() - 1;

    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }

    return buildTreeHelper(postorder, 0, postorder.size() - 1);
    }
};
