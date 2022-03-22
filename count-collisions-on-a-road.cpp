// https://leetcode.com/problems/count-collisions-on-a-road/

class Solution {
public:
    int countCollisions(string directions) {
      if(directions.size() == 0 || directions.size() == 1) return 0;
      
      int i = 0;
      int j = directions.size() - 1;
      int count = 0;
      
      while(directions[i] == 'L')  
        i++;
      while(directions[j] == 'R') 
        j--;
      
      for(int p = i; p <= j; p++){
        if(directions[p] != 'S') count++;
      }
      
      return count;
      
      
    }
};
