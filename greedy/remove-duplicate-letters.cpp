// https://leetcode.com/problems/remove-duplicate-letters/description
// 1. frequency + visited, each time check if this char has been added to the
// ans + where to put it
class Solution {
public:
  string removeDuplicateLetters(string s) {
    // hash table to count the frequency of each char
    // so that we can know once a char has been erased (to meet the
    // lexicographical order), can we append it later
    vector<int> freq(26, 0);
    // fill in the hash table
    for (auto i : s)
      freq[i - 'a']++;

    // mark if we have added a char into the ans
    vector<bool> visited(26, false);
    string ans;

    // loop each char in string
    for (auto i : s) {
      int curIdx = i - 'a';
      // update the frequency to record how many this char are left in the
      // string
      freq[curIdx]--;

      // if this char already added to the ans before, continue
      if (visited[i - 'a'])
        continue;

      // else, need to add it to the ans
      // then, decide where to put it
      // if 1. ans is not empty
      // 2. this char has a smaller lexico order
      // 3. the last char will occur later
      while (ans.length() > 0 && i < ans.back() &&
             freq[ans.back() - 'a'] >= 1) {
        // mark it as unused
        visited[ans.back() - 'a'] = false;
        // remove the last char (will add it later)
        ans.pop_back();
      }

      // add this current char
      ans.push_back(i);
      // mark it as used
      visited[curIdx] = true;
    }

    return ans;
  }
};

// 2. use stack to track the last char in the tmp ans
// the idea is similar to the above: track the ans, each time compare with the
// last char in the tmp ans, drop it if there's more later
class Solution {
public:
  string removeDuplicateLetters(string s) {
    int n = s.length();
    // record the idx when each char last occured in the string
    // {char, idx}
    unordered_map<char, int> lastOccur;
    // fill in the map
    for (int i = 0; i < n; i++) {
      lastOccur[s[i]] = i;
    }

    // record if a certain char has been added to the ans
    unordered_set<char> visited;
    // keep track of the final ans
    stack<char> st;

    for (int i = 0; i < n; i++) {
      // current char
      char cur = s[i];
      // if this char already been added into the ans, skip
      if (visited.find(cur) != visited.end())
        continue;

      // else, need to add it to the ans in the correct position
      // 1. drop previous chars if necessary
      while (!st.empty() && cur < st.top() && lastOccur[st.top()] > i) {
        // mark it as unused, so as to add it later in the loop
        visited.erase(st.top());
        // remove it from the ans
        st.pop();
      }

      // 2. add this char to the ans
      st.push(cur);
      // mark it as used in the ans
      visited.insert(cur);
    }

    // generate the ans in the correct order (the order in the stack is
    // reversed)
    string ans = "";
    while (!st.empty()) {
      ans = st.top() + ans;
      st.pop();
    }

    return ans;
  }
};
