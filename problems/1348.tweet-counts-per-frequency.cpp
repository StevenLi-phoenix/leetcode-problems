// @leetcode id=1348 questionId=1470 slug=tweet-counts-per-frequency lang=cpp site=leetcode.com title="Tweet Counts Per Frequency"
class TweetCounts {
public:
    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        tweets[tweetName].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int chunkSize = (freq == "minute") ? 60 : (freq == "hour") ? 3600 : 86400;
        int numChunks = (endTime - startTime) / chunkSize + 1;
        vector<int> result(numChunks, 0);

        for (int t : tweets[tweetName]) {
            if (t >= startTime && t <= endTime) {
                result[(t - startTime) / chunkSize]++;
            }
        }
        return result;
    }

private:
    unordered_map<string, vector<int>> tweets;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
