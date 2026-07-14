// @leetcode id=2195 questionId=2305 slug=append-k-integers-with-minimal-sum lang=cpp site=leetcode.com title="Append K Integers With Minimal Sum"
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        long long total = 0;
        long long prev = 0;
        long long remaining = k;

        auto sumRange = [](long long start, long long count) -> long long {
            // sum of `count` consecutive integers starting at `start`
            return count * start + count * (count - 1) / 2;
        };

        for (int v : nums) {
            if (remaining == 0) break;
            long long gap = v - prev - 1;
            long long take = min(gap, remaining);
            total += sumRange(prev + 1, take);
            remaining -= take;
            prev = v;
        }
        if (remaining > 0) total += sumRange(prev + 1, remaining);
        return total;
    }
};
