// https://leetcode.com/problems/design-twitter/

class Tweet {
private:
    int id;
    int time;
    
public:
    Tweet(int tweetId, int timestamp) {
        id = tweetId;
        time = timestamp;
    }
    
    int getTweetId() {
        return id;
    }
    
    int getTweetTime() {
        return time;
    }
};

class User {
private: 
    int id;
    set<User*> followers;
    vector<Tweet*> tweets;
    
public:
    User(int userId) {
        id = userId;
    }
    
    void follow(User *followee) {
        // followers.push_back(followee);
        followers.insert(followee);
    }
    
    void unfollow(User *followee) {
//         if(!followers.size())
//             return;
        
//         int i = 0;
//         while(i < followers.size()) {
//             if(followers[i]->getUserId() == followee->getUserId())
//                 break;
//             i++;
//         }
//         followers.erase(followers.begin() + i);
        followers.erase(followee);
    }
    
    void tweet(Tweet *t) {
        tweets.push_back(t);
    }
    
    int getUserId() {
        return id;
    }
    
    set<User*> getFollowers() {
        return followers;
    }
    
    vector<Tweet*> getTweets() const {
        return tweets;
    }
};

class Twitter {
private:
    map<int, User*> users;
    int timestamp;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet *tweet = new Tweet(tweetId, timestamp);
        if(users.count(userId)) {
            users[userId]->tweet(tweet);
        } else {
            User* user = new User(userId);
            user->tweet(tweet);
            users[userId] = user;
        }
        timestamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(!users.count(userId))
            return vector<int> ();
        
        auto comp = [](Tweet *a, Tweet *b) { return a->getTweetTime() < b->getTweetTime(); };
        priority_queue<Tweet*, vector<Tweet*>, decltype(comp) > pq(comp);
        
        vector<Tweet*> currentUserTweets = users[userId]->getTweets();
        for(Tweet *tweet : currentUserTweets) {
            pq.push(tweet);
        }
        
        set<User*> followers = users[userId]->getFollowers();
        for(auto it = followers.begin(); it != followers.end(); it++) {
            vector<Tweet*> tweets = (*it)->getTweets();
            for(Tweet *tweet : tweets) {
                pq.push(tweet);
            }
        }
        
        vector<int> newsFeed;
        while(!pq.empty() && newsFeed.size() < 10) {
            Tweet *tweet = pq.top();
            newsFeed.push_back(tweet->getTweetId());
            pq.pop();
        }
        
        return newsFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(!users.count(followerId)) {
            users[followerId] = new User(followerId);
        }
        
        if(!users.count(followeeId)) {
            users[followeeId] = new User(followeeId);
        }
        
        users[followerId]->follow(users[followeeId]);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(!users.count(followerId) || followerId == followeeId)
            return;
        
        users[followerId]->unfollow(users[followeeId]);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
