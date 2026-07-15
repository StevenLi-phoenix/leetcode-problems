// @leetcode id=1296 questionId=1422 slug=divide-array-in-sets-of-k-consecutive-numbers lang=cpp site=leetcode.com title="Divide Array in Sets of K Consecutive Numbers"
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<long long, int> count;
        for (int x : nums) count[x]++;

        for (auto& [key, cnt] : count) {
            if (cnt == 0) continue;
            long long start = key;
            int need = cnt;
            for (long long v = start; v < start + k; v++) {
                auto found = count.find(v);
                if (found == count.end() || found->second < need) return false;
                found->second -= need;
            }
        }
        return true;
    }
};
