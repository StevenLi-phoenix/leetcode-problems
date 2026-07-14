// @leetcode id=2086 questionId=2191 slug=minimum-number-of-food-buckets-to-feed-the-hamsters lang=cpp site=leetcode.com title="Minimum Number of Food Buckets to Feed the Hamsters"
class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.size();
        vector<bool> fed(n, false), bucket(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (hamsters[i] != 'H' || fed[i]) continue;
            if (i + 1 < n && hamsters[i + 1] != 'H' && !bucket[i + 1]) {
                bucket[i + 1] = true;
                fed[i] = true;
                if (i + 2 < n) fed[i + 2] = true;
                count++;
            } else if (i - 1 >= 0 && hamsters[i - 1] == '.' && !bucket[i - 1]) {
                bucket[i - 1] = true;
                fed[i] = true;
                count++;
            } else {
                return -1;
            }
        }
        return count;
    }
};
