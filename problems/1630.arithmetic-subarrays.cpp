// @leetcode id=1630 questionId=1752 slug=arithmetic-subarrays lang=cpp site=leetcode.com title="Arithmetic Subarrays"
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        for (size_t i = 0; i < l.size(); i++) {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub.begin(), sub.end());
            bool ok = true;
            int diff = sub[1] - sub[0];
            for (size_t j = 2; j < sub.size(); j++) {
                if (sub[j] - sub[j - 1] != diff) { ok = false; break; }
            }
            result.push_back(ok);
        }
        return result;
    }
};
