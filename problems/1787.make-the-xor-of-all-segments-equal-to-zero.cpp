// @leetcode id=1787 questionId=1913 slug=make-the-xor-of-all-segments-equal-to-zero lang=cpp site=leetcode.com title="Make the XOR of All Segments Equal to Zero"
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        const int BITS = 1024;
        const int INF = INT_MAX / 2;

        vector<int> prevDp(BITS, INF);
        prevDp[0] = 0;

        for (int c = 0; c < k; c++) {
            unordered_map<int,int> freq;
            int size = 0;
            for (int i = c; i < n; i += k) {
                freq[nums[i]]++;
                size++;
            }

            int minPrev = INF;
            for (int x = 0; x < BITS; x++) minPrev = min(minPrev, prevDp[x]);

            vector<int> newDp(BITS, minPrev == INF ? INF : minPrev + size);

            for (auto& [v, cnt] : freq) {
                int costBase = size - cnt;
                for (int x = 0; x < BITS; x++) {
                    if (prevDp[x] >= INF) continue;
                    int y = x ^ v;
                    int cand = prevDp[x] + costBase;
                    if (cand < newDp[y]) newDp[y] = cand;
                }
            }

            prevDp = newDp;
        }

        return prevDp[0];
    }
};
