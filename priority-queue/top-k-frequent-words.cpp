// https://leetcode.com/problems/top-k-frequent-words/

// input ["i","love","leetcode","i","love","coding"], k =2
// Approach 1: use map 2 times
class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {

    map<string, int> mp;
    vector<string> ans;

    for (auto w : words) {
      mp[w]++;
    }
    // i:2
    // love: 2
    // leetcode: 1
    // coding: 1

    // sort in descending order by key
    map<int, vector<string>, greater<int>> rmp;
    for (auto x : mp) {
      int frqc = x.second;
      rmp[frqc].push_back(x.first);
      // sort in alphabetical order
      sort(rmp[frqc].begin(), rmp[frqc].end());
    }

    // 2: [i,love]
    // 1: [coding,leetcode]

    // count num
    int n = 0;
    for (auto p : rmp) {
      for (auto i : p.second) {
        if (n < k) {
          ans.push_back(i);
          n++;
        }
        if (n == k)
          continue;
      }
    }

    return ans;
  }
};

// Approach 2:

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {

    unordered_map<string, int> hashmap;
    vector<string> ans;

    for (string &word : words) {
      hashmap[word]++;
    }
    // i: 2
    // love: 2
    // leetcode: 1
    // coding: 1

    // min heap
    priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
    for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
      pq.push(make_pair(it->second, it->first));
      // [<1,leetcode>, <2,love>, <2,i>]
      if (pq.size() > k)
        pq.pop();
      // [<2,love>,<2,i>]
    }

    while (!pq.empty()) {
      ans.insert(ans.begin(), pq.top().second);
      pq.pop();
    }
    return ans;
  }

private:
  struct MyComp {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
      if (a.first != b.first) {
        // sort by frequency
        return a.first > b.first;
      } else {
        // sort by alphabetical
        return a.second < b.second;
      }
    }
  }
};
