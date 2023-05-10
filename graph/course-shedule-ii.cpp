// https://leetcode.com/problems/course-schedule-ii/description/
// BFS: if all indegree can be eliminates, there is no loop in the graph
// O(V+E)
//
class Solution {
public:
  vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
    // adjacency matrix:
    // idx: prerequisites, item: [courses]
    vector<vector<int>> adj(n);
    // idx: course, value: indegree
    vector<int> degree(n, 0);

    // fill up adj and degree
    for (auto i : prerequisites) {
      int course = i[0];
      int pre = i[1];
      adj[pre].push_back(course);
      degree[course]++;
    }

    // BFS, store courses that can be safely taken
    queue<int> q;

    for (int i = 0; i < degree.size(); i++) {
      if (degree[i] == 0) {
        q.push(i);
        // decrease courses need to be checked
        n--;
      }
    }

    vector<int> ans;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int cur = q.front();
        // put this safe course into ans
        ans.push_back(cur);
        q.pop();

        for (auto relateCourse : adj[cur]) {
          // eliminate a prerequisite
          degree[relateCourse]--;
          // if all are eliminated, mark this course can be safely taken
          if (degree[relateCourse] == 0) {
            q.push(relateCourse);
            // decrease courses need to be checked
            n--;
          }
        }
      }
    }

    // if it is impossible to finish all courses
    if (n != 0)
      return {};

    return ans;
  }
};
