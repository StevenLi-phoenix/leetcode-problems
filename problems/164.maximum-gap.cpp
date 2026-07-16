// @leetcode id=164 questionId=164 slug=maximum-gap lang=cpp site=leetcode.com title="Maximum Gap"
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        if (mn == mx) return 0;

        int bucketSize = max(1, (mx - mn) / (n - 1));
        int bucketCount = (mx - mn) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        for (int x : nums) {
            int idx = (x - mn) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
        }

        int result = 0;
        int prevMax = mn;
        for (int i = 0; i < bucketCount; i++) {
            if (bucketMin[i] == INT_MAX) continue;
            result = max(result, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        return result;
    }
};
