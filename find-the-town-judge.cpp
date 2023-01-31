// https://leetcode.com/problems/find-the-town-judge/description/
//
//
// 1. map
class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    // if only one people and he is the judge
    if (n == 1 && trust.empty())
      return 1;

    map<int, vector<int>> beTrusted; // person be trusted: who trust this person
    map<int, vector<int>> whoTrust;  // person; person to be trusted

    for (auto i : trust) {
      int sub = i[0];
      int obj = i[1];
      whoTrust[sub].push_back(obj);
      beTrusted[obj].push_back(sub);
    }

    for (auto i : beTrusted) {
      vector<int> people = i.second;
      int self = i.first;
      bool f = true;

      for (int j = 1; j < n + 1; j++) {
        // all people except judge himself would trust him
        if (j == self)
          continue;
        if (count(people.begin(), people.end(), j) == false) {
          f = false;
          break;
        }
      }

      if (f == true) {
        // check if the candidate trust anybody
        if (whoTrust.find(self) == whoTrust.end())
          return self;
      }
    }

    return -1;
  }
};

// 2. graph thoery(outdegree & indegree)
class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    // special case
    if (n == 1 && trust.empty())
      return 1;
    // record the number of trust that each person has
    // idx: people
    // ans[idx]: number of trust
    vector<int> ans(n + 1);
    for (auto i : trust) {
      // person trust another
      ans[i[0]]--;
      // person gain another's trust
      ans[i[1]]++;
    }

    for (int i = 1; i < n + 1; i++) {
      // all people except himself trust him
      if (ans[i] == n - 1)
        return i;
    }

    return -1;
  }
};
