// https://leetcode.com/problems/implement-stack-using-queues/
//

class MyStack {
public:
  deque<int> q;

  MyStack() {}

  void push(int x) { q.push_back(x); }

  int pop() {
    int a = q.back();
    q.pop_back();
    return a;
  }

  int top() { return q.back(); }

  bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
