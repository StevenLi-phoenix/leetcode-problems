// @leetcode id=355 questionId=355 slug=design-twitter lang=cpp site=leetcode.com title="Design Twitter"
class Twitter {
public:
    Twitter() : timestamp(0) {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq; // time, tweetId, listIdx (index into tweets vector)
        vector<int> users = {userId};
        for (int f : following[userId]) users.push_back(f);

        vector<int> pos(users.size());
        for (int i = 0; i < (int)users.size(); i++) {
            auto& list = tweets[users[i]];
            pos[i] = (int)list.size() - 1;
            if (pos[i] >= 0) {
                pq.push({list[pos[i]].first, list[pos[i]].second, i});
            }
        }

        vector<int> result;
        while (!pq.empty() && (int)result.size() < 10) {
            auto [time, tweetId, idx] = pq.top(); pq.pop();
            result.push_back(tweetId);
            pos[idx]--;
            if (pos[idx] >= 0) {
                auto& list = tweets[users[idx]];
                pq.push({list[pos[idx]].first, list[pos[idx]].second, idx});
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> list of (time, tweetId)
    unordered_map<int, unordered_set<int>> following;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
