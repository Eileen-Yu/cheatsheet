// https://leetcode.com/problems/merge-two-sorted-lists/
// merge 2 sorted lists in place(don't generate new nodes of the same value)
// + dummy trick
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // dummy trick, as not sure who is the head
    ListNode *dummy = new ListNode(-1);
    // current node in the merged list
    ListNode *tmp = dummy;
    // idx to loop list1 and list2
    ListNode *head1 = list1;
    ListNode *head2 = list2;

    // loop 2 lists and compare each node
    while (head1 && head2) {
      if (head1->val <= head2->val) {
        tmp->next = head1;
        // move to the next node in list1
        head1 = head1->next;
      } else {
        tmp->next = head2;
        // move to the next node in list1
        head2 = head2->next;
      }

      // move to the next node in merged list
      tmp = tmp->next;
    }

    // if there are left nodes in list1
    while (head1) {
      tmp->next = head1;
      // move to the next node
      head1 = head1->next;
      tmp = tmp->next;
    }

    // if there are left nodes in list2
    while (head2) {
      tmp->next = head2;
      // move to the next node
      head2 = head2->next;
      tmp = tmp->next;
    }

    return dummy->next;
  }
};
