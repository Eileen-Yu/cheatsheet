//https://leetcode.com/problems/find-palindrome-with-fixed-length/

class Solution {
public:
  long long reverse(long long n, bool skip) {    // n is half of the ans
    long long res = 0;
    for( n = skip ? n / 10 : n; n > 0 ; n /= 10) {
      res = res * 10 + n % 10;
    }
    return res;
  }
  
  
  vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
      vector<long long> ans;
      long long start = pow(10, (intLength + 1) / 2 - 1);   // start cannot be reached, like 1000
      long long end = pow(10, (intLength + 1) / 2);         // end cannot be reached, like 10000
      long long mul = pow(10, intLength / 2);               
      
      for(int q: queries)
        ans.push_back(start + q > end ? -1 : (start + q - 1)*mul + reverse(start + q - 1, intLength % 2));
        return ans;    
  }
  
};
