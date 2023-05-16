// https://leetcode.com/problems/swap-nodes-in-pairs/description/
// 1. inplace, recursion
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *tmp = head->next;
    head->next = swapPairs(head->next->next);
    // must be the last step, otherwise head->next = tmp && tmp->next = head
    tmp->next = head;

    return tmp;
  }
};

// 2. not in place, create a new Linked List as the ans
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
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    // special cases
    if (!head)
      return nullptr;
    if (!head->next)
      return head;

    ListNode *dumb = new ListNode();
    // dumb node for convenience
    ListNode *cur = dumb;
    ListNode *tmp1 = head;
    ListNode *tmp2 = head->next;

    while (tmp1 && tmp2) {
      cur->next = new ListNode(tmp2->val);
      cur = cur->next;
      cur->next = new ListNode(tmp1->val);
      cur = cur->next;

      if (tmp1->next->next && tmp2->next->next) {
        tmp1 = tmp1->next->next;
        tmp2 = tmp2->next->next;
      } else
        break;
    }

    // for odd cases, only one more node would remain
    if (tmp1->next->next) {
      cur->next = new ListNode(tmp1->next->next->val);
      cur = cur->next;
    }

    return dumb->next;
  }
};
