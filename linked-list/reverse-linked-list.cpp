// https://leetcode.com/problems/reverse-linked-list/description/
// inplace reversal, use iteration
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *prev = nullptr;

    while (cur) {
      // record the original next node
      ListNode *next = cur->next;
      // change rhe direction
      cur->next = prev;
      // update the new positions
      prev = cur;
      cur = next;
    }

    return prev;
  }
};
