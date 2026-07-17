// @leetcode id=220 questionId=220 slug=contains-duplicate-iii lang=cpp site=leetcode.com title="Contains Duplicate III"
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;
        long long bucketSize = (long long)valueDiff + 1;
        unordered_map<long long, long long> buckets;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long val = nums[i];
            long long bucketId = val >= 0 ? val / bucketSize : (val + 1) / bucketSize - 1;

            if (buckets.count(bucketId)) return true;
            if (buckets.count(bucketId - 1) && val - buckets[bucketId - 1] <= valueDiff) return true;
            if (buckets.count(bucketId + 1) && buckets[bucketId + 1] - val <= valueDiff) return true;

            buckets[bucketId] = val;

            if (i >= indexDiff) {
                long long oldVal = nums[i - indexDiff];
                long long oldBucket = oldVal >= 0 ? oldVal / bucketSize : (oldVal + 1) / bucketSize - 1;
                buckets.erase(oldBucket);
            }
        }

        return false;
    }
};
