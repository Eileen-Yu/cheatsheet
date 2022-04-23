// https://leetcode.com/problems/design-twitter/

class Twitter {
public:
    list<int> tweets; // all tweets(TweetId)
    unordered_map<int,int> tweetedBy;// tweetId : userId
    unordered_map<int,unordered_set<int>> follows; // userId(follower): userId set(followees)
  
    Twitter() {      
    }
    
    void postTweet(int userId, int tweetId) {
      tweets.push_front(tweetId); // latest put in the first;
      tweetedBy[tweetId] = userId;
    }
    
    vector<int> getNewsFeed(int userId) {
      vector<int> ans;
      for(auto q: tweets){
        int uid = tweetedBy[q];  // tweet by whom
        
        // post by the user himself / by anyone in his follow list
        if(userId == uid || follows[userId].find(uid) != follows[userId].end()){  
          ans.push_back(q);
          if(ans.size() == 10) return ans;
        }
      }
      return ans; // in case < 10
    }
    
    void follow(int followerId, int followeeId) {
      follows[followerId].insert(followeeId);     // add to the follow list(set)
    }
    
    void unfollow(int followerId, int followeeId) {
      follows[followerId].erase(followeeId);     // remove from the follow list
    }
};
