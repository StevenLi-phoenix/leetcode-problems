// @leetcode id=3659 questionId=3979 slug=partition-array-into-k-distinct-groups lang=cpp site=leetcode.com title="Partition Array Into K-Distinct Groups"
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        int groups = n / k;

        unordered_map<int, int> freq;
        for (int v : nums) freq[v]++;

        for (auto& [val, cnt] : freq) {
            if (cnt > groups) return false;
        }
        return true;
    }
};
