// @leetcode id=659 questionId=659 slug=split-array-into-consecutive-subsequences lang=cpp site=leetcode.com title="Split Array into Consecutive Subsequences"
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, appendCount;
        for (int n : nums) freq[n]++;

        for (int n : nums) {
            if (freq[n] == 0) continue;
            if (appendCount[n - 1] > 0) {
                appendCount[n - 1]--;
                appendCount[n]++;
                freq[n]--;
            } else if (freq[n + 1] > 0 && freq[n + 2] > 0) {
                freq[n]--;
                freq[n + 1]--;
                freq[n + 2]--;
                appendCount[n + 2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};
