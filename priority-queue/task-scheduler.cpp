// https://leetcode.com/problems/task-scheduler/description/
// use pq to sort the frequency of each task, each represent a unique task
// try to arrange as many as unique tasks for each cycle
// similar to: https://leetcode.com/problems/reorganize-string/
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    // special case
    if (n == 0)
      return tasks.size();

    // record the frequency of each task
    unordered_map<char, int> mp;
    for (auto i : tasks) {
      mp[i]++;
    }

    // sort the tasks by decreasing frequency
    priority_queue<int> pq;
    for (auto [task, freq] : mp) {
      pq.push(freq);
    }

    int ans = 0;

    // In each cycle of size n + 1, try to process as many unique tasks as
    // possible, to minimize idle time
    while (!pq.empty()) {
      // record the left frequency of a task
      vector<int> record;
      // the length of a cycle without idle
      int cycle = n + 1;

      // get n+1 most frequent tasks
      while (cycle && !pq.empty()) {
        int freq = pq.top();
        pq.pop();
        // the unit time for this task
        ans++;
        // consume 1 cycle
        cycle--;

        // if still remains task, need to store it and push it back to the pq
        // later
        if (freq > 1)
          record.push_back(freq - 1);
      }

      // push back the left tasks to pq to re-sort
      for (auto i : record) {
        pq.push(i);
      }

      // if there is no more task, don't need to add the idle time
      if (pq.empty())
        break;
      // else, we need to add the idle time between the same tasks
      ans += cycle;
    }

    return ans;
  }
};
