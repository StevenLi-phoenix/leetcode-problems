// @leetcode id=3365 questionId=3595 slug=rearrange-k-substrings-to-form-target-string lang=cpp site=leetcode.com title="Rearrange K Substrings to Form Target String"
class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int chunkLen = n / k;

        unordered_map<string, int> count;
        for (int i = 0; i < n; i += chunkLen) count[s.substr(i, chunkLen)]++;
        for (int i = 0; i < n; i += chunkLen) count[t.substr(i, chunkLen)]--;

        for (auto& [chunk, c] : count)
            if (c != 0) return false;
        return true;
    }
};
