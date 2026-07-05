// @leetcode id=3636 questionId=3955 slug=threshold-majority-queries lang=cpp site=leetcode.com title="Threshold Majority Queries"
class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) positions[nums[i]].push_back(i);

        int B = max(1, (int)sqrt((double)n));
        int numBlocks = (n + B - 1) / B;

        auto blockStart = [&](int b) { return b * B; };
        auto blockEnd = [&](int b) { return min(n, (b + 1) * B) - 1; };

        // blockMode[bi][bj] = {value, count} of the mode within blocks [bi, bj]
        vector<vector<pair<int, int>>> blockMode(numBlocks, vector<pair<int, int>>(numBlocks, {-1, 0}));
        for (int bi = 0; bi < numBlocks; ++bi) {
            unordered_map<int, int> freq;
            int bestVal = -1, bestCnt = 0;
            for (int bj = bi; bj < numBlocks; ++bj) {
                for (int i = blockStart(bj); i <= blockEnd(bj); ++i) {
                    int v = nums[i];
                    int c = ++freq[v];
                    if (c > bestCnt || (c == bestCnt && v < bestVal)) {
                        bestCnt = c;
                        bestVal = v;
                    }
                }
                blockMode[bi][bj] = {bestVal, bestCnt};
            }
        }

        auto trueFreq = [&](int v, int l, int r) {
            auto& pos = positions[v];
            long long cnt = upper_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l);
            return (int)cnt;
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1], threshold = q[2];

            int leftBlock = (l + B - 1) / B;      // first block fully >= l
            int rightBlock = (r + 1) / B - 1;      // last block fully <= r

            int bestVal = -1, bestCnt = 0;
            auto consider = [&](int v) {
                int c = trueFreq(v, l, r);
                if (c > bestCnt || (c == bestCnt && v < bestVal)) {
                    bestCnt = c;
                    bestVal = v;
                }
            };

            if (leftBlock <= rightBlock) {
                consider(blockMode[leftBlock][rightBlock].first);
                for (int i = l; i < blockStart(leftBlock); ++i) consider(nums[i]);
                for (int i = blockEnd(rightBlock) + 1; i <= r; ++i) consider(nums[i]);
            } else {
                for (int i = l; i <= r; ++i) consider(nums[i]);
            }

            ans.push_back(bestCnt >= threshold ? bestVal : -1);
        }
        return ans;
    }
};
