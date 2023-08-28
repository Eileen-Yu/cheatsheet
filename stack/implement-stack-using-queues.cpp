// https://leetcode.com/problems/implement-stack-using-queues/description/
// use queue to mock stack

// 1. use 2 queues
class MyStack {
public:
  // init 2 queues
  // q1 is the mock stack
  // q2 is the helper for tmp store
  queue<int> q1, q2;

  MyStack() {
    // init q1 and q2 as empty queues
    q1 = queue<int>();
    q2 = queue<int>();
  }

  void push(int x) {
    // 1. put all elements in q1 to q2
    // since all elements in q1 are already in the reversed order,
    // this help to keep the order
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    // 2. push the current x into q1
    q1.push(x);

    // 3. put all elements in q2 back to q1, so as to have the reverse order
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int pop() {
    // remove the first element in q1
    int ans = q1.front();
    q1.pop();
    return ans;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
