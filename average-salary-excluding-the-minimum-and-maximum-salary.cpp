// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

// 1. sort
class Solution {
public:
    double average(vector<int>& salary) {
      sort(salary.begin(), salary.end());
      // remove the maximum
      salary.pop_back();
      // remove the minimum
      salary.erase(salary.begin());
      int n = salary.size();
      
      double sum = 0;
    
      for(auto i : salary) {
        sum += i;
      }

      double ans = sum / n;

      return ans;
    }
};

// 2. find max & min when loop
class Solution {
public:
    double average(vector<int>& salary) {
      int minSalary = INT_MAX, maxSalary = INT_MIN;
      double sum = 0;
      for(auto i : salary) {
        minSalary = min(i, minSalary);
        maxSalary = max(i, maxSalary);
        sum += i;
      }
      
      int n = salary.size();
      double ans = (sum-minSalary-maxSalary) / (n-2);

      return ans;

    }
};
