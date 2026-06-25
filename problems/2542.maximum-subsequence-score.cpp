// @leetcode id=2542 questionId=2636 slug=maximum-subsequence-score lang=cpp site=leetcode.com title="Maximum Subsequence Score"
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        // Sort indices by nums2 in descending order
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums2[a] > nums2[b];
        });
        
        // Use min-heap to maintain top-k nums1 values
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;
        
        for (int i : idx) {
            pq.push(nums1[i]);
            sum += nums1[i];
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = max(ans, sum * (long long)nums2[i]);
            }
        }
        
        return ans;
    }
};
