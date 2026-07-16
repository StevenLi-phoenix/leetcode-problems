// @leetcode id=1726 questionId=1364 slug=tuple-with-same-product lang=cpp site=leetcode.com title="Tuple with Same Product"
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long, long long> count;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                count[(long long)nums[i] * nums[j]]++;
            }
        }

        long long total = 0;
        for (auto& [prod, c] : count) {
            total += c * (c - 1) / 2 * 8;
        }
        return (int)total;
    }
};
