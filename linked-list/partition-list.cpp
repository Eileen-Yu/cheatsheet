// https://leetcode.com/problems/partition-list/
// 1. 2 pointers + combine 2 linked list
// direcly points to the original node instead of creating new
// ones
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    // this list contains elements < x
    // dummy to record the head
    ListNode *dummy1 = new ListNode();
    // tmp to move along the list
    ListNode *tmp1 = dummy1;
    // this list contains elements >= x
    ListNode *dummy2 = new ListNode();
    ListNode *tmp2 = dummy2;

    // loop the list
    while (head != nullptr) {
      if (head->val < x) {
        // directly point to this node, instead of creating a new node
        tmp1->next = head;
        tmp1 = tmp1->next;
      } else if (head->val >= x) {
        // directly point to this node, instead of creating a new node
        tmp2->next = head;
        tmp2 = tmp2->next;
      }
      // move to the next node in the original list
      head = head->next;
    }

    // connect link1 with link2
    tmp1->next = dummy2->next;
    // mark the link as finished
    // Without this line, tmp2 would still be pointing to its next element from
    // the original list which can create a cycle or some other incorrect link
    tmp2->next = nullptr;

    return dummy1->next;
  }
};
// 2. plain version, use additional vector to store + not inplace
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
