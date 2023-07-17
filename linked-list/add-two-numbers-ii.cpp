// https://leetcode.com/problems/add-two-numbers-ii/
// 1 use stack to add up from the least significant positions +
// create the result linked list while traversing both stacks with carry
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // 1. use stack to reverse both l1 & l2 values for easier carry handling
    stack<int> s1, s2;
    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }

    // 2. add up each digit and do carry
    // dummy is the last one (nullptr) of the result linked
    ListNode *dummy = nullptr;
    int carry = 0;
    while (!s1.empty() || !s2.empty() || carry) {
      // sum should be digit1 + digit2 + carry
      int sum = carry;

      if (!s1.empty()) {
        sum += s1.top();
        s1.pop();
      }

      if (!s2.empty()) {
        sum += s2.top();
        s2.pop();
      }

      // update carry
      carry = sum / 10;
      // create the node with corresponding digit
      ListNode *newNode = new ListNode(sum % 10);
      // the new node should points to the previous node
      newNode->next = dummy;
      dummy = newNode;
    }

    return dummy;
  }
};

// 2. convert each linked list to number first, add up, then convert back
// would out of range for some large numbers
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
    // use vectors to record the digits
    vector<int> v1;
    while (l1 != nullptr) {
      v1.push_back(l1->val);
      l1 = l1->next;
    }
    // translate to a real number: num1
    reverse(v1.begin(), v1.end());
    // the 10 ^ c
    int c = 0;
    long long int num1 = 0;
    for (auto i : v1) {
      num1 += i * pow(10, c);
      c++;
    }

    vector<int> v2;
    while (l2 != nullptr) {
      v2.push_back(l2->val);
      l2 = l2->next;
    }
    // translate to a real number: num1
    reverse(v2.begin(), v2.end());
    c = 0;
    long long int num2 = 0;
    for (auto i : v2) {
      num2 += i * pow(10, c);
      c++;
    }

    long long int sum = num1 + num2;
    // translate sum to the linked list form
    vector<int> v3;
    while (sum > 0) {
      v3.push_back(sum % 10);
      sum /= 10;
    }
    reverse(v3.begin(), v3.end());

    ListNode *dummy = new ListNode();
    ListNode *tmp = dummy;
    for (auto i : v3) {
      // create the new node with the corresponding digit
      ListNode *nxt = new ListNode(i);
      // point to the next
      tmp->next = nxt;
      tmp = tmp->next;
    }

    // special case: 0 + 0 = 0
    if (!dummy->next)
      return new ListNode();
    return dummy->next;
  }
};
