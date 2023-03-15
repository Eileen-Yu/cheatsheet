// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

// combine ListNode and TreeNode
// Divide and Conquer
// hare turtoise to find middle node in the linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  ListNode *getMiddle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    // hare tortoise to find the middle node
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // intercept the original linked list for the next recursion
    if (prev)
      prev->next = nullptr;
    // slow is the middle node
    return slow;
  }

  TreeNode *sortedListToBST(ListNode *head) {
    // if no node
    if (!head)
      return nullptr;
    // if only one node
    if (!head->next)
      return new TreeNode(head->val);

    ListNode *mid = getMiddle(head);
    // convert the listNode to a treeNode
    TreeNode *root = new TreeNode(mid->val);

    // because the original linked list has been intercepted
    // e.g original: {1,2,3,4,5}, find 3 as the middle
    // left : {1,2,nullptr}
    // right: {4,5}
    // divide and conquer
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
  }
};
