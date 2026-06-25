// @leetcode id=2099 questionId=2204 slug=find-subsequence-of-length-k-with-the-largest-sum lang=cpp site=leetcode.com title="Find Subsequence of Length K With the Largest Sum"
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Create pairs of (value, original index)
        vector<pair<int, int>> indexed(n);
        for (int i = 0; i < n; i++) {
            indexed[i] = {nums[i], i};
        }
        
        // Sort by value descending
        sort(indexed.begin(), indexed.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;
        });
        
        // Take top k indices
        vector<int> topIndices;
        for (int i = 0; i < k; i++) {
            topIndices.push_back(indexed[i].second);
        }
        
        // Sort indices to maintain original order
        sort(topIndices.begin(), topIndices.end());
        
        // Build result
        vector<int> result;
        for (int idx : topIndices) {
            result.push_back(nums[idx]);
        }
        
        return result;
    }
};
