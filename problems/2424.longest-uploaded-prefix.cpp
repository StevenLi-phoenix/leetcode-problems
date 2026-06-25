// @leetcode id=2424 questionId=2512 slug=longest-uploaded-prefix lang=cpp site=leetcode.com title="Longest Uploaded Prefix"
class LUPrefix {
private:
    unordered_set<int> uploaded;
    int longestPrefix = 0;

public:
    LUPrefix(int n) {
    }

    void upload(int video) {
        uploaded.insert(video);

        while (uploaded.count(longestPrefix + 1)) {
            longestPrefix++;
        }
    }

    int longest() {
        return longestPrefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
