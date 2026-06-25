// @leetcode id=3877 questionId=4097 slug=minimum-removals-to-achieve-target-xor lang=cpp site=leetcode.com title="Minimum Removals to Achieve Target XOR"
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int half = n / 2;
        
        // For each subset, store xor -> max count of elements
        // Left half: indices [0, half)
        // Right half: indices [half, n)
        
        // left_map[xor] = max number of elements we can keep from left with this xor
        unordered_map<int, int> left_map;
        int leftSize = half;
        for (int mask = 0; mask < (1 << leftSize); mask++) {
            int xorVal = 0, cnt = 0;
            for (int i = 0; i < leftSize; i++) {
                if (mask & (1 << i)) {
                    xorVal ^= nums[i];
                    cnt++;
                }
            }
            auto it = left_map.find(xorVal);
            if (it == left_map.end() || it->second < cnt) {
                left_map[xorVal] = cnt;
            }
        }
        
        int rightSize = n - half;
        int ans = -1;
        
        for (int mask = 0; mask < (1 << rightSize); mask++) {
            int xorVal = 0, cnt = 0;
            for (int i = 0; i < rightSize; i++) {
                if (mask & (1 << i)) {
                    xorVal ^= nums[half + i];
                    cnt++;
                }
            }
            int need = xorVal ^ target;
            auto it = left_map.find(need);
            if (it != left_map.end()) {
                int kept = cnt + it->second;
                ans = max(ans, kept);
            }
        }
        
        if (ans == -1) return -1;
        return n - ans;
    }
};
