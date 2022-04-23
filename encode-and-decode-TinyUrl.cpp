// https://leetcode.com/problems/encode-and-decode-tinyurl/
//
//
class Solution {
public:
    map<string,string> mp;
    int n = 0;
    string res = "";
  
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
      res = "http://tinyurl.com/" + to_string(n);
      mp[res] = longUrl;
      return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      return mp[shortUrl];  
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
