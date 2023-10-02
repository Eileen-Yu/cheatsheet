// https://leetcode.com/problems/reverse-words-in-a-string-iii
// 1. split the sentence + use stack to reverse word
class Solution {
public:
  string reverseWords(string s) {
    // split the whole sentence into individual words
    vector<string> words;
    string tmp = "";

    for (auto c : s) {
      // a complete individual word is finished if we meet a space
      if (c == ' ') {
        // store it
        words.push_back(tmp);
        // clean the cache
        tmp = "";
      } else
        tmp += c;
    }

    // also store the last word (as there is no space by the end)
    words.push_back(tmp);

    // reverse each word, and make up the sentence
    string ans = "";
    stack<char> st;

    // loop each word
    for (auto word : words) {
      // loop each char in the word
      for (auto c : word) {
        st.push(c);
      }

      // reverse the chars
      string reversed = "";
      while (!st.empty()) {
        reversed += st.top();
        st.pop();
      }

      // push this string into ans
      // still needs to seperate by space
      ans += reversed + ' ';
      // empty the stack for the next word
      st = stack<char>();
    }

    // remove the last space
    ans.pop_back();

    return ans;
  }
};

// 2. use string stream to help seperate the words from a sentence
class Solution {
public:
  string reverseWords(string s) {
    // create a string stream of the original string s
    stringstream ss(s);
    string tmp, ans;

    // for each word in the stream
    while (ss >> tmp) {
      reverse(tmp.begin(), tmp.end());
      // still needs to seperate the words by space
      ans += tmp + ' ';
    }

    // drop the space at the end
    return ans.substr(0, ans.length() - 1);
  }
};
