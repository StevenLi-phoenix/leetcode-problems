// @leetcode id=3960 questionId=4322 slug=frequency-balance-subarray lang=cpp site=leetcode.com title="Frequency Balance Subarray"
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int best = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> valueCount;
            map<int, int> freqCount; // frequency -> number of distinct values with that frequency
            for (int j = i; j < n; j++) {
                int v = nums[j];
                int oldF = valueCount[v];
                if (oldF > 0) {
                    freqCount[oldF]--;
                    if (freqCount[oldF] == 0) freqCount.erase(oldF);
                }
                int newF = oldF + 1;
                valueCount[v] = newF;
                freqCount[newF]++;

                bool ok = false;
                if (valueCount.size() == 1) {
                    ok = true;
                } else if (freqCount.size() == 2) {
                    auto it = freqCount.begin();
                    int k1 = it->first;
                    ++it;
                    int k2 = it->first;
                    if (k2 == 2 * k1) ok = true;
                }
                if (ok) best = max(best, j - i + 1);
            }
        }
        return best;
    }
};
