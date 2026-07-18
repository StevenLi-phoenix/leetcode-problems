// @leetcode id=2136 questionId=2257 slug=earliest-possible-day-of-full-bloom lang=cpp site=leetcode.com title="Earliest Possible Day of Full Bloom"
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return growTime[a] > growTime[b];
        });

        int day = 0;
        int ans = 0;
        for (int i : idx) {
            day += plantTime[i];
            ans = max(ans, day + growTime[i]);
        }

        return ans;
    }
};
