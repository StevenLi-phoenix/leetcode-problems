// @leetcode id=1679 questionId=1798 slug=max-number-of-k-sum-pairs lang=cpp site=leetcode.com title="Max Number of K-Sum Pairs"
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int v : nums) count[v]++;

        int ops = 0;
        for (auto& [v, c] : count) {
            int complement = k - v;
            if (complement == v) {
                ops += c / 2;
            } else if (complement > v) {
                auto it = count.find(complement);
                if (it != count.end()) ops += min(c, it->second);
            }
        }
        return ops;
    }
};
