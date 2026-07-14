// @leetcode id=1764 questionId=1874 slug=form-array-by-concatenating-subarrays-of-another-array lang=cpp site=leetcode.com title="Form Array by Concatenating Subarrays of Another Array"
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for (auto& g : groups) {
            bool found = false;
            while (pos + (int)g.size() <= n) {
                bool match = true;
                for (int i = 0; i < (int)g.size(); i++) {
                    if (nums[pos + i] != g[i]) { match = false; break; }
                }
                if (match) {
                    pos += g.size();
                    found = true;
                    break;
                }
                pos++;
            }
            if (!found) return false;
        }
        return true;
    }
};
