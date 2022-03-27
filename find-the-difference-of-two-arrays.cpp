// https://leetcode.com/problems/find-the-difference-of-two-arrays/

// use map
class Solution {
public:
    vector<int>fun(vector<int>n1,vector<int>n2){
        unordered_map<int,int>mp;
        for(int i:n1)   mp[i]++;    // put all elements of first vector in map
        for(int i:n2)   if(mp[i])   mp[i]=0;  // iterate through second vector, if find any number in the map, erase it
        
        vector<int>ans;
        for(auto x:mp)  if(x.second)  ans.push_back(x.first);
        return ans;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        ans.push_back(fun(nums1,nums2));
        ans.push_back(fun(nums2,nums1));
        return ans;
    }
};




// ugly one by loop
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      vector<vector<int>> ans;
      vector<int> new1;
      vector<int> new2; 
     
      for(int i = 0; i < nums1.size(); i++){
        bool exists = std::find(std::begin(new1), std::end(new1), nums1[i]) != std::end(new1);
        if(exists == true) continue;
        
        int f = 0;
        for(int j = 0; j < nums2.size();j++){
          if(nums1[i] == nums2[j]) f = 1;
        }
        if (f != 1) new1.push_back(nums1[i]);
      }
      
      for(int i = 0; i < nums2.size(); i++){
        bool exists = std::find(std::begin(new2), std::end(new2), nums2[i]) != std::end(new2);
        if(exists == true) continue;        
        
        int f = 0;
        for(int j = 0; j < nums1.size();j++){
          if(nums2[i] == nums1[j]) f = 1;
        }
        if (f != 1) new2.push_back(nums2[i]);
      }
      
      ans.push_back(new1);
      ans.push_back(new2);
      return ans; 
    }    
};
