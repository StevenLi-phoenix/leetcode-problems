// @leetcode id=2426 questionId=2513 slug=number-of-pairs-satisfying-inequality lang=cpp site=leetcode.com title="Number of Pairs Satisfying Inequality"
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = nums1[i] - nums2[i];

        // offset to keep Fenwick indices positive; a[i] range roughly [-2e4, 2e4]
        int OFFSET = 30001;
        int SIZE = 60005;
        vector<int> fenwick(SIZE + 2, 0);

        auto update = [&](int pos) {
            for (; pos <= SIZE; pos += pos & (-pos)) fenwick[pos]++;
        };
        auto query = [&](int pos) {
            long long s = 0;
            for (; pos > 0; pos -= pos & (-pos)) s += fenwick[pos];
            return s;
        };

        long long answer = 0;
        for (int j = 0; j < n; j++) {
            long long threshold = (long long)a[j] + diff;
            int pos = (int)(threshold + OFFSET);
            pos = min(pos, SIZE);
            if (pos >= 1) answer += query(pos);
            update(a[j] + OFFSET);
        }

        return answer;
    }
};
