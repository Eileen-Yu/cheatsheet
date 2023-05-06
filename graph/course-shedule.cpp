// https://leetcode.com/problems/course-schedule/description/

// DFS to detect if there is a cycle

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
