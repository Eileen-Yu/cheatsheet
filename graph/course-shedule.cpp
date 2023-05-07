// https://leetcode.com/problems/course-schedule/description/

// DFS to detect if there is a cycle
// 1. color algorithm to mark status
class Solution {
public:
  bool isCycle(int cur, vector<vector<int>> &adj, vector<int> &visited) {
    // we meet this course again, means there is a cycle
    if (visited[cur] == 1)
      return true;

    // need to check if there is a cycle
    if (visited[cur] == 0) {
      // mark this as being checked
      visited[cur] = 1;
      for (auto neighbor : adj[cur]) {
        // as long as there is a cycle, return false
        if (isCycle(neighbor, adj, visited))
          return true;
      }
    }

    // if there is no cycle, mark this course as can be safely taken
    visited[cur] = 2;
    return false;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // adjacency matrix
    vector<vector<int>> adj(numCourses);

    for (auto i : prerequisites) {
      int course = i[0];
      int pre = i[1];
      adj[course].push_back(pre);
    }

    // mark the status of a certain course
    // 0: not visited
    // 1: is now visiting to check if there is a cycle
    // 2: already checked that can be safely taken
    vector<int> visited(numCourses, 0);

    // check course one by one
    for (int i = 0; i < numCourses; i++) {
      // if there is any cycle, return false
      if (isCycle(i, adj, visited))
        return false;
    }

    return true;
  }
};

// 2. plain version
class Solution {
public:
  bool dfs(int cur, vector<bool> &visited, vector<vector<int>> &adj,
           vector<bool> &safe) {
    // this course can be taken without any prerequisites
    if (adj[cur].empty()) {
      // mark as safe
      safe[cur] = true;
      return true;
    }

    // need to detect if there is a cycle
    visited[cur] = true;

    bool rslt;
    for (auto neighbor : adj[cur]) {
      // this course already checked that can be taken
      if (safe[neighbor]) {
        rslt = true;
        continue;
      }

      // there is a cycle as it's already visited
      if (visited[neighbor])
        return false;

      // else continue to check
      rslt = dfs(neighbor, visited, adj, safe);

      // as long as one prerequisite cannot be taken, break
      if (rslt == false)
        break;
    }

    // mark this course can be safely taken
    if (rslt == true)
      safe[cur] = true;
    return rslt;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // adjacency matrix
    vector<vector<int>> adj(numCourses);

    for (auto i : prerequisites) {
      int course = i[0];
      int pre = i[1];

      adj[course].push_back(pre);
    }

    // for detecting cycle
    vector<bool> visited(numCourses, false);

    // for marking if a course can be safely taken
    vector<bool> safe(numCourses, false);

    // check course one by one
    for (int i = 0; i < numCourses; i++) {
      if (safe[i])
        continue;
      // else check
      fill(visited.begin(), visited.end(), false);
      bool rslt = dfs(i, visited, adj, safe);
      // as long as one course cannot be taken, return false
      if (rslt == false)
        return false;
    }

    return true;
  }
};

// 3. BFS to detect cycle
// indegree: pick node with indegree = 0 as starting point,
// try to eliminate its neighbors' indegree
// if indegree of all nodes can be eliminated, then there is no cycle

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    if (prerequisites.empty())
      return true;
    // adjacency matrix:
    // idx: prerequisites, vector: courses
    // this is to eliminate courses that can be safely taken by knowing its pre
    // courses are safe
    vector<vector<int>> adj(numCourses);
    // idx: course, value: number of prerequisites for this course
    vector<int> degree(numCourses, 0);

    for (auto i : prerequisites) {
      int course = i[0];
      int pre = i[1];
      adj[pre].push_back(course);
      degree[course]++;
    }
    // BFS
    queue<int> q;
    // pick out courses that don't need prerequistes to init the queue
    for (int i = 0; i < degree.size(); i++) {
      if (degree[i] == 0) {
        q.push(i);
        // course waiting to be check --
        numCourses--;
      }
    }

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int tmp = q.front();
        q.pop();

        for (auto course : adj[tmp]) {
          // one pre of this course can be met
          degree[course]--;
          // check if this course can be fully safe
          // then mark this course as a safe prerequisites
          if (degree[course] == 0) {
            q.push(course);
            // -- course waiting to be check
            numCourses--;
          }
        }
      }
    }

    // if no course waiting to be check, means all can be met
    return numCourses == 0;
  }
};
