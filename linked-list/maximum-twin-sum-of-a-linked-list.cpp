// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
// 1. stack, store value in the reverse sequence
class Solution {
public:
  int pairSum(ListNode *head) {
    // stack to store value in the reverse consequence
    stack<int> s;
    ListNode *tmp = head;

    // fill the stack with values
    while (tmp) {
      s.push(tmp->val);
      tmp = tmp->next;
    }

    int ans = INT_MIN;
    int sum = 0;
    tmp = head;

    // loop the linked list to get value of the first half, and add it with the
    // second half value stored in the stack
    while (tmp) {
      sum = tmp->val + s.top();
      s.pop();
      ans = max(ans, sum);
      tmp = tmp->next;
    }

    return ans;
  }
};

// 2. extra space: use vector to record value of each node
class Solution {
public:
  int pairSum(ListNode *head) {
    vector<int> record;

    while (head) {
      record.push_back(head->val);
      head = head->next;
    }

    int ans = INT_MIN;
    int n = record.size();

    for (int i = 0; i <= n / 2 - 1; i++) {
      int sum = record[i] + record[n - 1 - i];
      ans = max(ans, sum);
    }

    return ans;
  }
};
