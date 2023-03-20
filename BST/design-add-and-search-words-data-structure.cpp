// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
// Trie + DFS(recursion)

class TrieNode {
public:
  TrieNode *children[26];
  bool isComplete = false;
  // constructor
  TrieNode() {
    // initialize the children
    memset(children, 0, sizeof(children));
  }
};

class WordDictionary {
public:
  TrieNode *root;

  WordDictionary() { root = new TrieNode(); }

  void addWord(string word) {
    TrieNode *tmp = root;
    for (char ch : word) {
      int alphaIdx = ch - 'a';
      if (!tmp->children[alphaIdx]) {
        tmp->children[alphaIdx] = new TrieNode();
      }
      tmp = tmp->children[alphaIdx];
    }
    tmp->isComplete = true;
  }

  bool search(string word) {
    TrieNode *tmp = root;

    return searchHelper(word, tmp, 0);
  }

  bool searchHelper(string word, TrieNode *tmp, int idx) {
    // when to return
    if (idx == word.length())
      return tmp->isComplete;

    char ch = word[idx];
    if (ch != '.') {
      int alphaIdx = ch - 'a';
      if (!tmp->children[alphaIdx]) {
        return false;
      } else {
        return searchHelper(word, tmp->children[alphaIdx], idx + 1);
      }
    }

    // else if ch == '.'
    // we need to check every possible path
    for (int i = 0; i < 26; i++) {
      if (tmp->children[i] && searchHelper(word, tmp->children[i], idx + 1)) {
        return true;
      }
    }

    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
