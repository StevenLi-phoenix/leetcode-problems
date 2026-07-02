// @leetcode id=2163 questionId=2267 slug=minimum-difference-in-sums-after-removal-of-elements lang=cpp site=leetcode.com title="Minimum Difference in Sums After Removal of Elements"
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;

        vector<long long> minLeft(m + 1, 0);
        {
            priority_queue<long long> maxHeap;
            long long sum = 0;
            for (int i = 0; i < 2 * n; ++i) {
                sum += nums[i];
                maxHeap.push(nums[i]);
                if ((int)maxHeap.size() > n) {
                    sum -= maxHeap.top();
                    maxHeap.pop();
                }
                if (i + 1 >= n) minLeft[i + 1] = sum;
            }
        }

        vector<long long> maxRight(m + 1, 0);
        {
            priority_queue<long long, vector<long long>, greater<long long>> minHeap;
            long long sum = 0;
            for (int j = m - 1; j >= n; --j) {
                sum += nums[j];
                minHeap.push(nums[j]);
                if ((int)minHeap.size() > n) {
                    sum -= minHeap.top();
                    minHeap.pop();
                }
                if (m - j >= n) maxRight[j] = sum;
            }
        }

        long long ans = LLONG_MAX;
        for (int k = n; k <= 2 * n; ++k) {
            ans = min(ans, minLeft[k] - maxRight[k]);
        }
        return ans;
    }
};
