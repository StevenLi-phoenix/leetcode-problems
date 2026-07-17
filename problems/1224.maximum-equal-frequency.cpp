// @leetcode id=1224 questionId=1344 slug=maximum-equal-frequency lang=cpp site=leetcode.com title="Maximum Equal Frequency"
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> freqCount;
        int maxFreq = 0;
        int best = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            int x = nums[i];
            int oldF = freq[x];
            if (oldF > 0) freqCount[oldF]--;
            freq[x] = oldF + 1;
            freqCount[oldF + 1]++;
            maxFreq = max(maxFreq, oldF + 1);

            int len = i + 1;
            bool ok = false;

            if (maxFreq == 1) {
                ok = true;
            } else if (freqCount[maxFreq] * maxFreq == len - 1) {
                ok = true;
            } else if (freqCount[maxFreq] == 1 && freqCount[maxFreq - 1] * (maxFreq - 1) + maxFreq == len) {
                ok = true;
            }

            if (ok) best = len;
        }

        return best;
    }
};
