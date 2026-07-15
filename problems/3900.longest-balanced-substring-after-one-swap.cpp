// @leetcode id=3900 questionId=4265 slug=longest-balanced-substring-after-one-swap lang=cpp site=leetcode.com title="Longest Balanced Substring After One Swap"
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> P(n + 1, 0);
        for (int i = 0; i < n; i++) P[i + 1] = P[i] + (s[i] == '1' ? 1 : -1);

        int totalZero = 0, totalOne = 0;
        int firstZeroIdx = -1, lastZeroIdx = -1, firstOneIdx = -1, lastOneIdx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                totalZero++;
                if (firstZeroIdx == -1) firstZeroIdx = i;
                lastZeroIdx = i;
            } else {
                totalOne++;
                if (firstOneIdx == -1) firstOneIdx = i;
                lastOneIdx = i;
            }
        }

        unordered_map<int, int> eIdx, eIdxAfterZero, eIdxAfterOne;
        int best = 0;

        for (int r = 0; r <= n; r++) {
            int val = P[r];

            auto it0 = eIdx.find(val);
            if (it0 != eIdx.end()) best = max(best, r - it0->second);

            if (totalZero > 0) {
                int target = val - 2;
                if (r <= lastZeroIdx) {
                    auto it = eIdx.find(target);
                    if (it != eIdx.end()) best = max(best, r - it->second);
                } else {
                    auto it = eIdxAfterZero.find(target);
                    if (it != eIdxAfterZero.end()) best = max(best, r - it->second);
                }
            }

            if (totalOne > 0) {
                int target = val + 2;
                if (r <= lastOneIdx) {
                    auto it = eIdx.find(target);
                    if (it != eIdx.end()) best = max(best, r - it->second);
                } else {
                    auto it = eIdxAfterOne.find(target);
                    if (it != eIdxAfterOne.end()) best = max(best, r - it->second);
                }
            }

            if (eIdx.find(val) == eIdx.end()) eIdx[val] = r;
            if (r > firstZeroIdx && eIdxAfterZero.find(val) == eIdxAfterZero.end()) eIdxAfterZero[val] = r;
            if (r > firstOneIdx && eIdxAfterOne.find(val) == eIdxAfterOne.end()) eIdxAfterOne[val] = r;
        }

        return best;
    }
};
