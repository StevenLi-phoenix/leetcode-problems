// @leetcode id=3948 questionId=4174 slug=lexicographically-maximum-mex-array lang=cpp site=leetcode.com title="Lexicographically Maximum MEX Array"
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        int cap = n + 2;
        vector<int> cnt(cap, 0);
        for (int v : nums) if (v < cap) cnt[v]++;

        int mex = 0;
        while (mex < cap && cnt[mex] > 0) mex++;

        vector<int> lastSeenStep(cap, -1);
        int stepIndex = 0;
        int pos = 0;
        vector<int> result;

        while (pos < n) {
            int target = mex;
            int k;

            if (target == 0) {
                k = 1;
            } else {
                int distinctSeen = 0;
                k = 0;
                while (distinctSeen < target) {
                    int v = nums[pos + k];
                    if (v < target && lastSeenStep[v] != stepIndex) {
                        lastSeenStep[v] = stepIndex;
                        distinctSeen++;
                    }
                    k++;
                }
            }

            int newMex = target;
            for (int idx = pos; idx < pos + k; idx++) {
                int v = nums[idx];
                if (v < cap) {
                    cnt[v]--;
                    if (v < target && cnt[v] == 0) newMex = min(newMex, v);
                }
            }

            result.push_back(target);
            pos += k;
            mex = newMex;
            stepIndex++;
        }

        return result;
    }
};
