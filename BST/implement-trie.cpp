// https://leetcode.com/problems/implement-trie-prefix-tree/description/

// Here TrieNode is a type
class TrieNode {
public:
  // Here children is an array whose length is 26
  // (there are 26 lowercase english letters)
  // each of the element's type is TrieNode
  // just like int arr[26]
  TrieNode *children[26];
  // record if current linked-list is complete(a complete word)
  // mark the complete position
  // initialize it as false
  bool isComplete = false;

  // constructor
  TrieNode() {
    // initialize all element in the array to 0;
    //  The value is passed as an int,
    // but the function fills the block of memory using the unsigned char
    // conversion of this value
    memset(children, 0, sizeof(children));
  }
};

class Trie {
public:
  TrieNode *root;
  // constructor to initialize the root
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *tmp = root;
    for (char ch : word) {
      // use idx to represent the char
      // and record in the children[]
      int alphaIdx = ch - 'a';
      if (tmp->children[alphaIdx] == nullptr) {
        tmp->children[alphaIdx] = new TrieNode();
      }
      tmp = tmp->children[alphaIdx];
    }
    // mark this word as complete
    tmp->isComplete = true;
  }

  bool search(string word) {
    TrieNode *tmp = root;
    for (char ch : word) {
      int alphaIdx = ch - 'a';
      if (!tmp->children[alphaIdx])
        return false;

      tmp = tmp->children[alphaIdx];
    }
    // if insert apple
    // then if search app, should return false
    if (tmp->isComplete)
      return true;

    return false;
  }

  bool startsWith(string prefix) {
    TrieNode *tmp = root;
    for (char ch : prefix) {
      int alphaIdx = ch - 'a';
      if (!tmp->children[alphaIdx])
        return false;

      tmp = tmp->children[alphaIdx];
    }
    // don't need the word is complete one
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
