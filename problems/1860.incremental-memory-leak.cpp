// @leetcode id=1860 questionId=1971 slug=incremental-memory-leak lang=cpp site=leetcode.com title="Incremental Memory Leak"
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        long long m1 = memory1, m2 = memory2;
        long long i = 1;
        while (true) {
            if (m1 >= m2) {
                if (m1 < i) break;
                m1 -= i;
            } else {
                if (m2 < i) break;
                m2 -= i;
            }
            i++;
        }
        return {(int)i, (int)m1, (int)m2};
    }
};
