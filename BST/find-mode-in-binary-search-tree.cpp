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

// 2. use BST feature: ascending (same idea can be applied to array)
// in-order traversal, record:
// (1). value of last node
// (2). max frequency til now
// (3). current frequency of this specific value
class Solution {
public:
  // frequency of this current value
  int curFreq = 0;
  // max frequency in the whole tree
  int maxFreq = 0;
  // value of the last node
  int prev = INT_MIN;

  vector<int> ans;

  void recursion(TreeNode *node) {
    // when to return
    if (!node)
      return;

    // in-order traversal
    recursion(node->left);

    // main logic:
    // 1. if the current node value == last node value
    if (node->val == prev)
      curFreq++;
    else
      curFreq = 1;

    // 2. check if needs to update ans
    // 2.1 if node with more frequency occurs
    if (curFreq > maxFreq) {
      // empty the original ans
      ans.clear();
      // this value become the ans
      ans.push_back(node->val);
      // update maxFreq
      maxFreq = curFreq;
    }
    // 2.2 if multiple most frequency
    else if (curFreq == maxFreq)
      ans.push_back(node->val);

    // 3. update prev value
    prev = node->val;

    // in-order traversal
    recursion(node->right);
  }

  vector<int> findMode(TreeNode *root) {
    recursion(root);
    return ans;
  }
};
