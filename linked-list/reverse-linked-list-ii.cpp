// https://leetcode.com/problems/reverse-linked-list-ii/description
// 1. reverse: use stack
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    stack<int> st;

    // idx to loop the list
    ListNode *tmp = head;
    // count the idx of the nodes, only put those within [left,right] into stack
    int c = 1;

    // record the values in [left, right] in the reversed order
    while (tmp) {
      if (c >= left && c <= right) {
        st.push(tmp->val);
      }
      // move to the next node
      tmp = tmp->next;
      c++;
    }

    // create a new list with partly reversed
    ListNode *dummy = new ListNode();
    ListNode *last = dummy;
    tmp = head;
    // count the number of nodes
    c = 1;

    while (tmp) {
      // if it's out of [left, right], needs to keep the original order
      if (c < left || c > right) {
        last->next = new ListNode(tmp->val);
      } else {
        // else if its within [left, right], use the value in the stack
        last->next = new ListNode(st.top());
        st.pop();
      }

      // move to the next node
      last = last->next;
      tmp = tmp->next;
      c++;
    }

    return dummy->next;
  }
};
