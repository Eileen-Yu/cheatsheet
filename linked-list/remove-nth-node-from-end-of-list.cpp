// https://leetcode.com/problems/remove-nth-node-from-end-of-list
// skip a node in the linked list

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // number of nodes in the list
    int count = 0;
    ListNode *tmp = head;

    while (tmp) {
      count++;
      tmp = tmp->next;
    }

    // special cases:
    // needs to remove the head
    if (n == count)
      return head->next;

    tmp = head;
    // record the number of nodes we have looped
    int c = 0;
    while (tmp) {
      c++;

      // if this node is the one before the node to be removed
      if (c == count - n) {
        // skip the next node as it is the one to be removed
        tmp->next = tmp->next->next;
        break;
      }

      // else, move to the next node
      tmp = tmp->next;
    }

    return head;
  }
};
