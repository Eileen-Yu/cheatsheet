// https://leetcode.com/problems/top-k-frequent-elements/

// multimap + vector resize
/ class Solution {
public:
  multimap<int, int> invert(unordered_map<int, int> &mymap) {
    multimap<int, int> multiMap;

    unordered_map<int, int>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++) {
      multiMap.insert(make_pair(it->second, it->first));
    }

    return multiMap;
  }

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
      mp[nums[i]]++;

    multimap<int, int> newMap = invert(mp);

    for (multimap<int, int>::reverse_iterator nt = newMap.rbegin();
         nt != newMap.rend(); nt++)
      ans.push_back(nt->second);

    ans.resize(k);

    return ans;
  }
};

// priority_queue, max heap
typedef pair<int, int> pi;
class Solution {
public:
  struct myComparator {
  public:
    bool operator()(const pi &pi1, const pi &pi2) {
      return pi1.second > pi2.second;
    }
  };

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> record;
    for (auto i : nums) {
      record[i]++;
    }
    priority_queue<pi, vector<pi>, myComparator> pq;
    for (const auto &p : record) {
      pq.push(p);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<int> result;
    while (!pq.empty()) {
      result.push_back(pq.top().first);
      pq.pop();
    }
    return result;
  }
};
