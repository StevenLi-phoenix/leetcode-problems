// @leetcode id=3779 questionId=4162 slug=minimum-number-of-operations-to-have-distinct-elements lang=cpp site=leetcode.com title="Minimum Number of Operations to Have Distinct Elements"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int dupCount = 0;
        for (int v : nums) {
            freq[v]++;
            if (freq[v] == 2) dupCount++;
        }

        int start = 0;
        int ops = 0;
        while (true) {
            if (dupCount == 0) return ops;
            int end = min(start + 3, n);
            for (int idx = start; idx < end; idx++) {
                int v = nums[idx];
                if (freq[v] == 2) dupCount--;
                freq[v]--;
            }
            start = end;
            ops++;
            if (start >= n) return ops;
        }
    }
};
