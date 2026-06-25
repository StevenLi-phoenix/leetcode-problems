// @leetcode id=535 questionId=535 slug=encode-and-decode-tinyurl lang=cpp site=leetcode.com title="Encode and Decode TinyURL"
class Solution {
private:
    unordered_map<string, string> map;
    int counter = 0;

public:
    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/" + to_string(counter++);
        map[shortUrl] = longUrl;
        return shortUrl;
    }

    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
