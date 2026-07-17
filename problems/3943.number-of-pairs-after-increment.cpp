// @leetcode id=3943 questionId=4076 slug=number-of-pairs-after-increment lang=cpp site=leetcode.com title="Number of Pairs After Increment"
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums2.size();
        int blockSize = max(1, (int)(sqrt((double)n * 2.5)) + 1);
        int numBlocks = (n + blockSize - 1) / blockSize;

        vector<long long> raw(nums2.begin(), nums2.end());
        vector<long long> blockTag(numBlocks, 0);
        vector<unordered_map<long long,int>> blockFreq(numBlocks);
        for (auto& m : blockFreq) m.reserve(blockSize * 2);

        auto blockOf = [&](int idx) { return idx / blockSize; };

        for (int i = 0; i < n; i++) blockFreq[blockOf(i)][raw[i]]++;

        auto updatePartial = [&](int lo, int hi, long long val) {
            int b = blockOf(lo);
            for (int i = lo; i <= hi; i++) {
                auto it = blockFreq[b].find(raw[i]);
                if (--(it->second) == 0) blockFreq[b].erase(it);
                raw[i] += val;
                blockFreq[b][raw[i]]++;
            }
        };

        auto updateRange = [&](int x, int y, long long val) {
            int bx = blockOf(x), by = blockOf(y);
            if (bx == by) {
                updatePartial(x, y, val);
                return;
            }
            int xBlockEnd = (bx + 1) * blockSize - 1;
            updatePartial(x, xBlockEnd, val);
            int yBlockStart = by * blockSize;
            updatePartial(yBlockStart, y, val);
            for (int b = bx + 1; b < by; b++) blockTag[b] += val;
        };

        vector<int> result;

        for (auto& q : queries) {
            if (q[0] == 1) {
                updateRange(q[1], q[2], q[3]);
            } else {
                long long tot = q[1];
                long long total = 0;
                for (int v1 : nums1) {
                    long long target = tot - v1;
                    for (int b = 0; b < numBlocks; b++) {
                        long long need = target - blockTag[b];
                        auto it = blockFreq[b].find(need);
                        if (it != blockFreq[b].end()) total += it->second;
                    }
                }
                result.push_back((int)total);
            }
        }

        return result;
    }
};
