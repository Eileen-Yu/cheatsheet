// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
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
