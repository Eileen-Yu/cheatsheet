// https://leetcode.com/problems/decoded-string-at-index/
// 1. use math to decode the final string with repetition reversely
// e.g: string: prob3slov4 --> (3*4 + 4) * 4, k = 31, totalLength = 64
// first read 4, so 64 / 4 = 16, k = 31 % 16 = 15 --> o is the ans
class Solution {
public:
  string decodeAtIndex(string s, int k) {
    // length of the string to be decoded
    long long len = 0;
    // calculate the final length of the string with the repeatition
    for (auto i : s) {
      if (isalpha(i))
        len += 1;
      else
        len *= i - '0';
    }

    // try to decode the final string from the end to the biginning
    // e.g: (3*4 + 4)*4, we'll first decode the final *4
    for (int i = s.length() - 1; i >= 0; i--) {
      // if i is digit
      if (isdigit(s[i])) {
        // decode the repeatition
        len /= s[i] - '0';
        // also means, string[i] and string[i+len] is the same char
        // so decode the k to find it in the decoded(shortened) string
        k = k % len;
      }

      // else if i is letter
      else if (isalpha(s[i])) {
        // since 1-indexed, so k == 0 means the char we are seeking is the end
        // of the decoded string OR len == k means the idx we're at now is
        // exactly the one we are seeking
        if (k == 0 || len == k)
          return string(1, s[i]);

        // else, try to compare the previous char
        // len represents the idx we're at now(1-indexed)
        len--;
      }
    }

    // should never reach this line
    return "";
  }
};

// 2. same idea with 1, just use stack to eliminate the devision when we meet a
// digit
class Solution {
public:
  string decodeAtIndex(string s, int k) {
    // record the length of the full string when we read at each specific char
    // in the encoded string s
    stack<long long> st;
    // base, for easier push later
    st.push(0);

    // fill in the stack
    for (auto i : s) {
      if (isalpha(i))
        st.push(st.top() + 1);

      else
        st.push(st.top() * (i - '0'));
    }

    // traverse reversely
    // total # of elements in the stack
    int sz = st.size();
    while (!st.empty()) {
      k %= st.top();
      sz--;

      // if this char is the one we are seeking
      // idx is 1-indexed, so s[sz-1]
      if (k == 0 && isalpha(s[sz - 1]))
        return string(1, s[sz - 1]);

      // else, try the next one
      st.pop();
    }

    // should never reach this line
    return "";
  }
};

// 3. try to generate the string, most direct but MLE
class Solution {
public:
  string decodeAtIndex(string s, int k) {
    // record the tmp substring
    stack<char> st;
    string ans = "";

    for (auto i : s) {
      // if it's a letter
      if (isalpha(i)) {
        st.push(i);
        continue;
      }

      // else if it's a digit
      // 1. put all chars in the stack to the ans
      // the substring in the stack
      string tmp;
      while (!st.empty()) {
        tmp = st.top() + tmp;
        st.pop();
      }
      // append this substring to the ans
      ans += tmp;

      // 2. repeat it
      string s = ans;
      int repeat = int(i) - 1;
      while (repeat--)
        ans += s;
    }

    return string(1, ans[k - 1]);
  }
};
