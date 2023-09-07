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

// 2. inplace reverse parts of the nodes in a linked list
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *prev = dummy;

    // move prev to left - 1
    for (int i = 0; i < left - 1; i++) {
      prev = prev->next;
    }

    // start from left
    ListNode *cur = prev->next;

    // trick to reverse the nodes in [left, right] in a linked list, inplace
    for (int i = 0; i < right - left; i++) {
      // record the original next node
      ListNode *nextNode = cur->next;
      cur->next = nextNode->next;
      nextNode->next = prev->next;
      prev->next = nextNode;
    }

    // use dummy to avoid lose the new head (in case left = 1)
    return dummy->next;
  }
};
