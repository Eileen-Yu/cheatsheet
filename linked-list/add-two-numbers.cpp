// https://leetcode.com/problems/add-two-numbers/description/
// traverse l1 & l2 simutaneously, use carry to create the result linked list
// small trick: dummy node

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // the start node before the real start of the result
    ListNode *dummy = new ListNode();
    // ptr to move
    ListNode *tmp = dummy;
    int carry;

    while (l1 || l2 || carry) {
      // sum = digit1 + digit2 + carry
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      // update carry
      carry = sum / 10;
      // create a new node with the corresponding digit of this position
      ListNode *newNode = new ListNode(sum % 10);
      // points to this new node
      tmp->next = newNode;
      tmp = tmp->next;
    }

    return dummy->next;
  }
};
