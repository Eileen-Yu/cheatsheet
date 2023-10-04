// https://leetcode.com/problems/design-twitter/
// complex data structure design
// key point:
// 1. tweetBy --> know tweetId is posted by certain userId
// so that we can match the relationship
// 2. use list to put the most recent tweets at the beginning for easier loop

class Twitter {
public:
  // tweetID list, the latter one would be put in the front for easier loop 10
  // most recent
  list<int> tweets;
  // followerID, [followeeID1, followeeID2,...]
  unordered_map<int, unordered_set<int>> followMp;
  // tweetID, userID who post this tweet
  unordered_map<int, int> tweetBy;

  Twitter() {}

  void postTweet(int userId, int tweetId) {
    // always put the latest at the beginning
    tweets.push_front(tweetId);
    // record who post this tweet
    tweetBy[tweetId] = userId;
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> ans;

    // loop each tweet from the most recent one
    for (auto i : tweets) {
      // user who post this tweet
      int uid = tweetBy[i];

      // if this tweet is:
      // 1. post by the user himself
      // 2. post by his followees
      // then push it into the ans
      if (uid == userId || followMp[userId].find(uid) != followMp[userId].end())
        ans.push_back(i);

      // when to break: we already got 10 most recent tweets
      if (ans.size() == 10)
        break;
    }

    return ans;
  }

  void follow(int followerId, int followeeId) {
    // update follow relationship
    followMp[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    // update follow relationship
    followMp[followerId].erase(followeeId);
  }
};
