//https://leetcode.com/problems/longest-substring-without-repeating-characters/

// 1. use map to keep the state
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> b;
      int i = 0;
      int j = 0;
      int rslt = 0;
      
      while(j < s.length()) {
        if (b.count(s[j]) > 0 ) {
          i = max(i, b[s[j]] + 1);
        }
        
        rslt = max(rslt, j - i + 1);
        b[s[j]] = j;
        j++;
      }
      
      return rslt;
      
    }
};






// 2. Use new string to keep the state
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int i = 0;
      int j = 0;
      string news="";
      int rslt = 0;
      
      while (j < s.length()){
        news = s.substr(i,j - i + 1);
        int newRslt = news.length(); 
        rslt = max(rslt, newRslt);
        
        if( (j+1) >= s.length() ) break;
        
        if (news.find(s[j + 1]) == string::npos) {
          j++;
        }
        
        else {
          while (news.find(s[j+1]) != string::npos ) {
            i++;
            news = s.substr(i,j-i+1);
          }
          j++;
        }  
      }
      
      return rslt;
    }
};
