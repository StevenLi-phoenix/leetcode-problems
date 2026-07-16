// @leetcode id=3755 questionId=3946 slug=find-maximum-balanced-xor-subarray-length lang=cpp site=leetcode.com title="Find Maximum Balanced XOR Subarray Length"
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, int>, int> firstSeen;
        firstSeen[{0, 0}] = 0;

        int prefixXor = 0, balance = 0;
        int best = 0;
        for (int i = 0; i < n; i++) {
            prefixXor ^= nums[i];
            balance += (nums[i] % 2 == 0) ? 1 : -1;

            auto key = make_pair(prefixXor, balance);
            auto it = firstSeen.find(key);
            if (it != firstSeen.end()) {
                best = max(best, i + 1 - it->second);
            } else {
                firstSeen[key] = i + 1;
            }
        }
        return best;
    }
};
