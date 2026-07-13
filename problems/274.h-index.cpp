// @leetcode id=274 questionId=274 slug=h-index lang=cpp site=leetcode.com title="H-Index"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n + 1, 0);
        for (int c : citations) bucket[min(c, n)]++;

        int papers = 0;
        for (int h = n; h >= 0; h--) {
            papers += bucket[h];
            if (papers >= h) return h;
        }
        return 0;
    }
};
