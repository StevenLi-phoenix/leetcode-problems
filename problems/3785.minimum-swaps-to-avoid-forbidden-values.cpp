// @leetcode id=3785 questionId=4061 slug=minimum-swaps-to-avoid-forbidden-values lang=cpp site=leetcode.com title="Minimum Swaps to Avoid Forbidden Values"
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        unordered_map<int,long long> badCount;
        vector<pair<int,int>> good; // (value, forbidden) for good positions

        for (int i = 0; i < n; i++) {
            if (nums[i] == forbidden[i]) badCount[nums[i]]++;
            else good.push_back({nums[i], forbidden[i]});
        }

        priority_queue<pair<long long,int>> heap;
        for (auto& [v, c] : badCount) heap.push({c, v});

        int swaps = 0;
        vector<pair<int,int>> formedPairs;
        while (heap.size() >= 2) {
            auto [c1, v1] = heap.top(); heap.pop();
            auto [c2, v2] = heap.top(); heap.pop();
            swaps++;
            formedPairs.push_back({v1, v2});
            c1--; c2--;
            if (c1 > 0) heap.push({c1, v1});
            if (c2 > 0) heap.push({c2, v2});
        }

        if (!heap.empty()) {
            auto [leftoverCount, v] = heap.top();

            long long foldable = 0;
            for (auto& [v1, v2] : formedPairs) {
                if (v1 != v && v2 != v) foldable++;
            }
            foldable = min(foldable, leftoverCount);
            long long stillNeeded = leftoverCount - foldable;

            if (stillNeeded > 0) {
                long long available = 0;
                for (auto& [val, fb] : good) {
                    if (val != v && fb != v) available++;
                }
                if (available < stillNeeded) return -1;
            }

            swaps += (int)leftoverCount;
        }

        return swaps;
    }
};
