// https://leetcode.com/problems/partition-list/
// 1. plain version, use additional vector to store + not inplace
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *dummy = new ListNode();
    ListNode *tmp = dummy;
    ListNode *p = head;
    // store the values >= target by relative order
    vector<int> store;

    // loop the linked list
    while (p != nullptr) {
      if (p->val >= x) {
        // store in the vector
        store.push_back(p->val);
        // loop to the next node
        p = p->next;
        continue;
      }
      // else if val < target
      // directly append the new node into the list
      tmp->next = new ListNode(p->val);
      tmp = tmp->next;
      // loop to the next
      p = p->next;
    }

    // append all vals that >= target to the linked list
    for (auto i : store) {
      tmp->next = new ListNode(i);
      tmp = tmp->next;
    }

    return dummy->next;
  }
};
